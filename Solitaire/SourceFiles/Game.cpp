//Games/Solitaire/SourceFiles/Game.cpp
//Matthew Ellison
// Created: 3-6-18
//Modified: 3-6-18
//This file contians the implementation of the Game class for the Solitaire game
//

#include <string>
#include <sstream>
#include <algorithm>
#include <random>
#include "../Headers/TermColors.hpp"
#include "../Headers/Card.hpp"
#include "../Headers/Game.hpp"
#include "../Headers/globalVars.hpp"

/*
	Card deck[52];
	std::vector<Card*> piles[7];
	std::vector<Card*> foundations[4];
	std::stack<Card*> draw;
	std::stack<Card*> discard;
	mee::TermColors term;
*/

Game::Game(){
	setup();
}

Game::~Game(){
	
}

void Game::setup(){
	//Make sure the piles are empty
	for(int pileCnt = 0;pileCnt < NUM_PILES;++pileCnt){
		piles[pileCnt].empty();
	}
	//Make sure the foundations are empty
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
}

void Game::shuffle(){

}

inline void Game::deal(){

}

void Game::discardToPile(unsigned int pil){

}

void Game::discardToFoundation(unsigned int found){

}

void Game::foundationToPile(unsigned int found, unsigned int pil){

}

void Game::pileToFoundation(unsigned int pil, unsigned int found){

}

void Game::pileToPile(unsigned int fromPil, unsigned int toPil){

}

bool Game::isValidMove(Card* fromCard, Card* toCard, bool isFoundation){

}

std::string Game::suggestion(){

}

std::string Game::instruction(std::string move){

}

std::string Game::operator()(std::string move){

}

std::string Game::print(Card card){
	//Need to add colors
}

std::string Game::print(){
	//Need to add Colors
	std::stringstream temp("");
	while(!draw.empty()){
		temp << draw.top().getSize() << ' ' << draw.top().getSuit() << '\n';
		draw.pop();
	}
	return temp.str();
}
