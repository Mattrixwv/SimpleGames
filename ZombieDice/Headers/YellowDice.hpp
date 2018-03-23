//Games/ZombieDice/EHaders/YellowDice.hpp
//Matthew Ellison
// Created: 3-21-18
//Modified: 3-21-18
//This file contains the YellowDice class created for the Zombie Dice game

#ifndef YELLOW_DICE_HPP
#define YELLOW_DICE_HPP

#include "Dice.hpp"
#include "DiceVars.hpp"

class YellowDice : public Dice{
private:
	char zFace;
public:
	YellowDice() : Dice(6, 1)
	{	zFace = BRAIN;	}
	virtual ~YellowDice()
	{	}
	virtual char zRoll(){
		Dice::roll();
		switch (getFace()){
			case 6 :;
			case 5 : zFace = BRAIN;	break;
			case 4 :;
			case 3 : zFace = FEET;	break;
			case 2 :;
			case 1 : zFace = SHOTGUN;	break;
			default : zFace = '\0';	break;
		}
	}
};

#endif //YELLOW_DICE_HPP
