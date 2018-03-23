//Games/ZombieDice/Headers/RedDice.hpp
//Matthew Ellison
// Created: 3-21-18
//Modified: 3-21-18
//This file contains the RedDice class for the ZombieDice game

#ifndef RED_DICE_HPP
#define RED_DICE_HPP

#include "Dice.hpp"
#include "DiceVars.hpp"

class RedDice : public Dice{
private:
	char zFace;
public:
	RedDice() : Dice(6, 1)
	{	zFace = BRAIN;	}
	virtual ~RedDice()
	{	}
	virtual char zRoll(){
		Dice::roll();
		switch (getFace()){
			case 6 :zFace = BRAIN;	break;
			case 5 :;
			case 4 :zFace = FEET;	break;
			case 3 :;
			case 2 :;
			case 1 : zFace = SHOTGUN;	break;
			default : zFace = '\0';	break;
		}
	}
};

#endif //RED_DICE_HPP
