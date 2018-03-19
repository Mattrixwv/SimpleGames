//Games/Solitaire/SourceFiles/Game.cpp
//Matthew Ellison
// Created: 3-6-18
//Modified: 3-6-18
//This file contians the implementation of the Game class for the Solitaire game


#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <random>
#include <cctype>
#include <cstring>
#include "../Headers/TermColors.hpp"
#include "../Headers/Card.hpp"
#include "../Headers/Game.hpp"
#include "../Headers/globalVars.hpp"


Game::Game(){
	setup();
	gmOvr = false;
}

Game::~Game(){
	
}

void Game::setup(){
	///*Make sure the piles are empty
	for(int pileCnt = 0;pileCnt < NUM_PILES;++pileCnt){
		piles[pileCnt].empty();
	}
	///*Make sure the foundations are empty
	for(int fndCnt = 0;fndCnt < Suits::NUM;++fndCnt){
		foundations[fndCnt].empty();
	}
	//Make sure the draw is empty
	draw.empty();
	//Make sure the discard is empty
	discard.empty();
	//Create the correct number of cards
	std::vector<Card> deck;
	deck.reserve(52);
		//Setup Spades
	for(int cnt = 1;cnt <= 13;++cnt){
		deck.emplace_back(cnt, SPADES);
	}
		//Setup Hearts
	for(int cnt = 1;cnt <= 13;++cnt){
		deck.emplace_back(cnt, HEARTS);
	}
		//Setup Diamonds
	for(int cnt = 1;cnt <= 13;++cnt){
		deck.emplace_back(cnt, DIAMONDS);
	}
		//Setup Clubs
	for(int cnt = 1;cnt <= 13;++cnt){
		deck.emplace_back(cnt, CLUBS);
	}
	//Shuffle the cards
	std::shuffle(deck.begin(), deck.end(), std::default_random_engine(std::random_device{}()));
	//Put all of the cards in the draw
	for(int cnt = 0;cnt < 52;++cnt){
		draw.push(deck[cnt]);
	}
	//Put the correct number of cards in each pile
	for(int pileCnt = 0;pileCnt < NUM_PILES;++pileCnt){
		for(int pl = pileCnt;pl < NUM_PILES;++pl){
			piles[pl].push_back(draw.top());
			draw.pop();
		}
	}
	flip();
}

inline void Game::deal(){
	//Start dealing with the first pile and deal to every pile - 1 with each loop
	for(int startPile = 0;startPile < NUM_PILES;++startPile){
		for(int currentPile = startPile;currentPile < NUM_PILES;++currentPile){
			piles[currentPile].push_back(draw.top());
			draw.pop();
		}
	}
}

void Game::flip(){
	for(int cnt = 0;cnt < NUM_PILES;++cnt){
		if(!(piles[cnt].at(piles[cnt].size() - 1)).isFaceUp()){
			piles[cnt].at(piles[cnt].size() - 1).flip();
		}
	}
}

void Game::drawToDiscard(){
	//If deal is empty move everything back over
	if(draw.empty()){
		while(!discard.empty()){
			Card temp = discard.top();
			discard.pop();
			temp.flip();
			draw.push(temp);
		}
	}
	//Otherwise move one card from deal to discard
	else{
		Card temp = draw.top();
		draw.pop();
		temp.flip();
		discard.push(temp);
	}
}

void Game::discardToPile(unsigned int pil){
	//Check if something is empty
	if(discard.empty()){
		//Throw an error
	}
	else if(piles[pil].empty()){
		//If the card is a king it can go on the pile
		if(discard.top().getSize() == KING){
			piles[pil].push_back(discard.top());
			discard.pop();
		}
		else{
		//Else throw an error
		}
	}
	//If the card can be moved
	else if(isValidMove(discard.top(), piles[pil].at(piles[pil].size() - 1), false)){
		//Move the card to the dicard pile
		piles[pil].push_back(discard.top());
		discard.pop();
	}
	else{
		//Throw an error about an invalid move
	}
}

void Game::discardToFoundation(Suits found){
	//Check if something is empty
	if(discard.empty()){
		//Throw an error
	}
	if(found == NUM){
		found = discard.top().getSuit();
	}
	else if(foundations[found].empty()){
		//If the card is an ace it can be moved to the foundation
		if(discard.top().getSize() == ACE){
			foundations[found].push(discard.top());
			discard.pop();
		}
		//Throw an error about an empty foundation
		else{

		}
	}
	else if(isValidMove(discard.top(), foundations[found].top(), true)){
		foundations[found].push(discard.top());
		discard.pop();
	}
	else{
		//Throw an error about an invalid move
	}
}

void Game::foundationToPile(unsigned int found, unsigned int pil){
	if(foundations[found].empty()){
		//Throw an error
	}
	else if(piles[pil].empty()){
		//If the Card is a king it can come down
		if(foundations[found].top().getSize() == KING){
			piles[pil].push_back(foundations[found].top());
			foundations[found].pop();
		}
		//Else throw an error about an invalid move
		else{

		}
	}
	else if(isValidMove(foundations[found].top(), piles[pil].at(piles[pil].size() - 1), false)){
		piles[pil].push_back(foundations[found].top());
		foundations[found].pop();
	}
	else{
		//Throw an error about an invalid move
	}
}

void Game::pileToFoundation(unsigned int pil, Suits found){
	if(piles[pil].empty()){
		//Throw an error about an empty pile
		return;
	}
	if(found == NUM){
		found = piles[pil].at(piles[pil].size() - 1).getSuit();
	}
	//^gets the suit of the card on the top of the pile
	if(foundations[found].empty()){
		//If the card is an Ace it can be moved
		if(piles[pil].at(piles[pil].size() - 1).getSize() == ACE){
			foundations[found].push(piles[pil].at(piles[pil].size() - 1));
			piles[pil].pop_back();
		}
		//Else throw an error about an empty foundation
		else{
			//Throw an error about an empty foundation
			return;
		}
	}
	else if(isValidMove(piles[pil].at(piles[pil].size() - 1), foundations[found].top(), false)){
		foundations[found].push(piles[pil].at(piles[pil].size() - 1));
		piles[pil].pop_back();
	}
	else{
		//Throw an error for an invalid move
		return;
	}
	
}

void Game::pileToPile(unsigned int fromPil, unsigned int toPil){
	//Check that fromPil is not empty
	if(piles[fromPil].empty()){
		//Throw an error about an empty fromPil
	}
	//Run through every card in fromPil until you find one that is face up and save the location
	int faceUpLocation = 0;
	while(!piles[fromPil].at(faceUpLocation).isFaceUp()){
		++faceUpLocation;
	}
	//Check that toPil is not empty
	if(piles[toPil].empty()){
		//Check that the card to move is a king
		//Check if the bottom card is a king
		//Else throw an error
	}
	//Check that it is a valid move
	//Run through every face up card in fromPil and check if it can moved to the top card in toPil
	for(unsigned int cnt = faceUpLocation;cnt < (piles[fromPil].size() - 1);++cnt){
		if(isValidMove(piles[fromPil].at(cnt), piles[toPil].at(piles[toPil].size() - 1), false)){
			//Move the card and every card after it to the new pile
			while((piles[fromPil].size() - 1) >= cnt){
				piles[toPil].push_back(piles[fromPil].at(cnt));
				piles[fromPil].pop_back();
			}
			return;
		}
	}
	//Throw an error about an invalid move
	return;
}

bool Game::isValidMove(Card fromCard, Card toCard, bool isFoundation){
	//The rules for the foundation
	if(isFoundation){
		//If the 2 cards are the same suit
		if(fromCard.getSuit() == toCard.getSuit()){
			//fromCard is 1 greater than toCard
			if(fromCard.getSize() == (toCard.getSize() + 1)){
				return true;
			}
			else{
				return false;
			}
		}
		//Else return false
		else{
			return false;
		}
	}
	//The rules for all other cards
	else{
		//If the cards are of different colors
		if(fromCard.getColor() != toCard.getColor()){
			//If the fromCard is one less than the toCard
			if(fromCard.getSize() == (toCard.getSize() - 1)){
				return true;
			}
			else{
				return false;
			}
		}
		else{
			return false;
		}
	}
}

std::string Game::suggestion(){

}

std::string Game::instruction(std::string move){
	//Decide what kind of command it is
	std::string errorMsg = "";
	std::string fromLoc;
	fromLoc = move[0];
	std::string toLoc = "";
	if(move == "help"){
		return printInstructions();
	}
	else if(move == "end" || move == "exit"){
		gmOvr = true;
		errorMsg = "Game Over";
	}
	else if(fromLoc == "." || move == "deal"){
		drawToDiscard();
	}
	else{
		toLoc = move[2];
		//Call the appropriate function in a try box
	///These triples need to be removed when error catching is ready
		///try{
			//If you are moving from a pile
			if(fromLoc >= "1" && fromLoc <= "7"){
				//If you are moving to another pile
				if(toLoc >= "1" && toLoc <= "7"){
					pileToPile(std::stoi(fromLoc), std::stoi(toLoc));
				}
				//If you are moving to the foundation
				///*Allow for a specific foundation
				else if(toLoc == "F"){
					pileToFoundation(std::stoi(fromLoc));
				}
				else if(toLoc == "S" || toLoc == "H" || toLoc == "D" || toLoc == "C"){
					if(toLoc == "S"){
						pileToFoundation(std::stoi(fromLoc), SPADES);
					}
					else if(toLoc == "H"){
						pileToFoundation(std::stoi(fromLoc), HEARTS);
					}
					else if(toLoc == "D"){
						pileToFoundation(std::stoi(fromLoc), DIAMONDS);
					}
					else{
						pileToFoundation(std::stoi(fromLoc), CLUBS);
					}
				}
				else{
					//Throw an error about an invalid move
				}
			}
			//If you are moving from the discard
			else if(fromLoc == "0" || fromLoc == "D"){
				//If you are moving to a pile
				if(toLoc >= "1" && toLoc <="7"){
					discardToPile(std::stoi(toLoc));
				}
				//If you are moving to the foundation
				///*Allow for a specific foundation
				else if(toLoc == "F"){
					discardToFoundation();
				}
				else if(toLoc == "S" || toLoc == "H" || toLoc == "D" || toLoc == "C"){
					if(toLoc == "S"){
						discardToFoundation(SPADES);
					}
					else if(toLoc == "H"){
						pileToFoundation(std::stoi(fromLoc), HEARTS);
					}
					else if(toLoc == "D"){
						pileToFoundation(std::stoi(fromLoc), DIAMONDS);
					}
					else{
						pileToFoundation(std::stoi(fromLoc), CLUBS);
					}
				}
				else{
					//Throw an error about an invalid move
				}
			}
			//If you are moving from a foundation
			else if(fromLoc == "S" || fromLoc == "H" || fromLoc == "D" || fromLoc == "C"){
				//If you are moving to a pile
				if(toLoc >= "1" && toLoc <= "7"){
					if(fromLoc == "S"){
						foundationToPile(SPADES, std::stoi(toLoc));
					}
					else if(fromLoc == "H"){
						foundationToPile(HEARTS, std::stoi(toLoc));
					}
					else if(fromLoc == "D"){
						foundationToPile(DIAMONDS, std::stoi(toLoc));
					}
					else{
						foundationToPile(CLUBS, std::stoi(toLoc));
					}
				}
				else{
					//Throw an error about an invalid move
				}
			}
			else{
				//Throw an error about an invalid move
			}
		///}
		///catch(){

		///}
	}
	flip();
	//Print the new screen as well as any error messages
	printBoard(errorMsg);
}

std::string Game::print(Card card){
	std::stringstream printedCard;
	//If the card is face down print the back of the card
	if(!card.isFaceUp()){
		printedCard << term.setText(CARD_BACK_COLOR) << '|' << std::right << std::setw(3) << CARD_BACK << '|';
	}

	//Otherwise print the card
	//Set the color
	if(card.getColor() == RED){
		printedCard << term.setText(mee::textColors::RED);
	}
	else{
		printedCard << term.setText(mee::textColors::WHITE);
	}
	printedCard << term.setText(CARD_BACK_COLOR) << '|' << std::right << std::setw(2);

	//Print the number or letter
	if(card.getSize() == ACE){
		printedCard << 'A';
	}
	else if(card.getSize() == JACK){
		printedCard << 'J';
	}
	else if(card.getSize() == QUEEN){
		printedCard << 'Q';
	}
	else if(card.getSize() == KING){
		printedCard << 'K';
	}
	else{
		printedCard << card.getSize();
	}

	//Print the suit
	#ifdef _WIN32
	if(card.getSuit() == SPADES){
		printedCard << 'S';
	}
	else if(card.getSuit() == HEARTS){
		printedCard << 'H';
	}
	else if(card.getSuit() == DIAMONDS){
		printedCard << 'D';
	}
	else{
		printedCard << 'C';
	}
	#else
	if(card.getSuit() == SPADES){
		printedCard << u8"\u2660";
	}
	else if(card.getSuit() == HEARTS){
		printedCard << u8"\u2665";
	}
	else if(card.getSuit() == DIAMONDS){
		printedCard << u8"\u2666";
	}
	else{
		printedCard << u8"\u2663";
	}
	#endif
	printedCard << term.setText(CARD_BACK_COLOR) << '|';

	//Set everything back to default

	return printedCard.str();
}

/*
std::string Game::print(){
	//Need to add Colors
	std::stringstream temp("");
	while(!draw.empty()){
		temp << draw.top().getSize() << ' ' << draw.top().getSuit() << '\n';
		draw.pop();
	}
	return temp.str();
}
*/

std::string Game::printBoard(std::string errorMsg){
	std::stringstream screen;
	//Clear the screen
	screen << term.eraseScreen();
	screen << term.setPos(0, 0) << errorMsg;
	//Print draw
	//Draw will always be faceDown if it is not empty
	if(!draw.empty()){
		screen << term.setPos(DRAW_ROW, DRAW_COL) << print(draw.top());
	}
	//Print discard
	if(!discard.empty()){
		screen << term.setPos(DISCARD_ROW, DISCARD_COL) << print(discard.top());
	}
	//Print the foundations
	for(int foundCnt = 0;foundCnt < Suits::NUM;++foundCnt){
		//If the foundations is not empty print the card
		screen << term.setPos(FOUNDATION_ROWS[foundCnt], FOUNDATION_COLS[foundCnt]);
		if(!foundations[foundCnt].empty()){
			screen << print(foundations[foundCnt].top());
		}
		//Otherwise print the suit
		else{
			#ifdef _WIN32
			//For windows
			if(foundCnt == SPADES){
				screen << term.setText(mee::textColors::BLACK) << 'S';
			}
			else if(foundCnt == HEARTS){
				screen << term.setText(mee::textColors::RED) << 'H';
			}
			else if(foundCnt == DIAMONDS){
				screen << term.setText(mee::textColors::RED) << 'D';
			}
			else{
				screen << term.setText(mee::textColors::BLACK) << 'C';
			}
			//For linux
			#else
			if(foundCnt == SPADES){
				screen << term.setText(mee::textColors::BLACK) << u8"\u2660";
			}
			else if(foundCnt == HEARTS){
				screen << term.setText(mee::textColors::RED) << u8"\u2665";
			}
			else if(foundCnt == DIAMONDS){
				screen << term.setText(mee::textColors::RED) << u8"\u2666";
			}
			else{
				screen << term.setText(mee::textColors::BLACK) << u8"\u2663";
			}
			#endif //_WIN32
		}
	}

	//Print the piles in order
	for(int pilesCnt = 0;pilesCnt < NUM_PILES;++pilesCnt){
		//Print the cards from bottom to top, accounting for faceUp
		for(int loc = 0;loc < piles[pilesCnt].size();++loc){
			//Print the card at the current location
			screen << term.setPos((FOUNDATION_ROWS[pilesCnt] + loc), FOUNDATION_COLS[pilesCnt]) << print(piles[pilesCnt].at(loc));
		}
		//Print an extra row for show
		screen << term.setPos((FOUNDATION_ROWS[pilesCnt] + piles[pilesCnt].size()), FOUNDATION_COLS[pilesCnt]) <<     "|___|";
	}

	return screen.str();
}

std::string Game::printInstructions(){
	std::stringstream screen;
	//Clear the screen
	screen << term.eraseScreen();
	//Start at the first location
	//Print the point of the game
	//Print the controls
	screen << term.setPos(1, 1) << "These are the instructions";
	return screen.str();
}

bool Game::gameOver(){
	return gmOvr;
}

bool Game::win(){
	//Determine if the game is over
	if((foundations[0].size() == 13) && (foundations[1].size() == 13) && (foundations[2].size() == 13) && (foundations[3].size() == 13)){
		return true;
	}
	else{
		return false;
	}
}
