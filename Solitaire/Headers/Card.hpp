//Games/Solitaire/Card.hpp
//Matthew Ellison
// Created: 3-2-18
//Modified: 3-2-18
//This file contains the cards that are used for the Solitaire program

#ifndef CARD_HPP
#define CARD_HPP


enum Suits{	SPADES, HEARTS, CLUBS, DIAMONDS, NUM };
enum suitColor{ RED, BLACK };
enum cardValue{ ACE = 1, JACK = 11, QUEEN, KING };

class Card{
private:
	int size;
	Suits suit;
	bool faceUp;
public:
	Card(int size, Suits suit, bool faceUp = false)
	{	this->size = size;	this->suit = suit;	this->faceUp = faceUp;	}
	int getSize() const
	{	return size;	}
	Suits getSuit() const
	{	return suit;	}
	bool isFaceUp() const
	{	return faceUp;	}
	void flip()
	{	faceUp ? faceUp = false : faceUp = true;	}
	suitColor getColor() const{
		if(suit == SPADES || suit == CLUBS){
			return RED;
		}
		else{
			return BLACK;
		}
	}
};


#endif //CARD_HPP
