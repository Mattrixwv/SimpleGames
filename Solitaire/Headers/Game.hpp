//Games/Solitaire/Headers/Game.cpp
//Matthew Ellison
// Created: 3-3-18
//Modified: 3-3-18
//This file contains the declaration of the Game class that controlls the Solitaire program

#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <sstream>
#include <stack>
#include <vector>
#include "Card.hpp"
#include "TermColors.hpp"
#include "globalVars.hpp"


class Game{
private:
	std::vector<Card> piles[NUM_PILES];
	std::vector<Card> foundations[Suits::NUM];
	std::stack<Card> draw;
	std::stack<Card> discard;
	mee::TermColors term;
	void setup();	//Sets up the different piles for cards. Only called in setup and reset
	void shuffle();
	void deal();
	void discardToPile(unsigned int pil);
	void discardToFoundation(unsigned int found);
	void foundationToPile(unsigned int found, unsigned int pil);
	void pileToFoundation(unsigned int pil, unsigned int found);
	void pileToPile(unsigned int fromPil, unsigned int toPil);
	bool isValidMove(Card* fromCard, Card* toCard, bool isFoundation = false);	//Checks if you can move a card
	std::string suggestion();	//Returns a valid move
public:
	Game();
	~Game();
	std::string instruction(std::string move);
	std::string operator()(std::string move);	//Simply calls instruction
	std::string print(Card card);
	std::string print();	//Prints everythingin the draw. Used for debugging
};

#endif //GAME_HPP
