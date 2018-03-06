//Games/Solitaire/SourceFiles/Game.cpp
//Matthew Ellison
// Created: 3-6-18
//Modified: 3-6-18
//This file contians the implementation of the Game class for the Solitaire game
//

#include <string>
#include <sstream>
#include "../Headers/TermColors.hpp"
#include "../Headers/Card.hpp"
#include "../Headers/Game.hpp"
/*
	Card deck[52];
	std::vector<Card*> piles[7];
	std::vector<Card*> foundations[4];
	std::stack<Card*> draw;
	std::stack<Card*> discard;
	mee::TermColors term;
	void setup();	//Sets up the different piles for cards. Only called in setup and reset
	void deal();
	void discardToPile(unsigned int pil);
	void discardToFoundation(unsigned int found);
	void foundationToPile(unsigned int found, unsigned int pil);
	void pileToFoundation(unsigned int pil, unsigned int found);
	void pileToPile(unsigned int fromPil, unsigned int toPil);
	bool isValidMove(Card* fromCard, Card* toCard, bool isFoundation = false);	//Checks if you can move a card
	std::string suggestion();
public:
	Game();
	~Game();
	std::string instruction(std::string move);
	std::string operator()(std::string move);	//Simply calls instruction
*/

Game::Game() : deck{{1, SPADES}, {2, SPADES}, {3, SPADES}, {4, SPADES}, {5, SPADES}, {6, SPADES}, {7, SPADES}, {8, SPADES}, {9, SPADES}, {10, SPADES}, {11, SPADES}, {12, SPADES}, {13, SPADES},
					{1, HEARTS}, {2, HEARTS}, {3, HEARTS}, {4, HEARTS}, {5, HEARTS}, {6, HEARTS}, {7, HEARTS}, {8, HEARTS}, {9, HEARTS}, {10, HEARTS}, {11, HEARTS}, {12, HEARTS}, {13, HEARTS},
					{1, CLUBS}, {2, CLUBS}, {3, CLUBS}, {4, CLUBS}, {5, CLUBS}, {6, CLUBS}, {7, CLUBS}, {8, CLUBS}, {9, CLUBS}, {10, CLUBS}, {11, CLUBS}, {12, CLUBS}, {13, CLUBS},
					{1, DIAMONDS}, {2, DIAMONDS}, {3, DIAMONDS}, {4, DIAMONDS}, {5, DIAMONDS}, {6, DIAMONDS}, {7, DIAMONDS}, {8, DIAMONDS}, {9, DIAMONDS}, {10, DIAMONDS}, {11, DIAMONDS}, {12, DIAMONDS}, {13, DIAMONDS}}
{

}

Game::~Game(){
	
}

void Game::setup(){

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
