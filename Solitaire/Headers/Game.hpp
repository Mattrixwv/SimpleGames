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


class Game{
private:
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
	std::string suggestion();	//Returns a valid move
public:
	Game();
	~Game();
	std::string instruction(std::string move);
	std::string operator()(std::string move);	//Simply calls instruction
};

#endif //GAME_HPP
