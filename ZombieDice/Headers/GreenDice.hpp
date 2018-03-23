//Games/ZombieDice/Headers/GreenDice.hpp
//Matthew Ellison
// Created: 3-21-18
//Modified: 3-21-18
//This file contains the declaration of the GreenDice class for the Zombie Dice game

#ifndef GREEN_DICE_HPP
#define GREEN_DICE_HPP

#include "Dice.hpp"
#include "DiceVars.hpp"

class GreenDice : public Dice{
private:
	char zFace;
public:
	GreenDice() : Dice(6, 1)
	{	zFace = BRAIN;	}
	virtual ~GreenDice()
	{	}
	virtual char zRoll(){
		Dice::roll();
		switch (getFace()){
			case 6 :;
			case 5 :;
			case 4 : zFace = BRAIN;	break;
			case 3 :;
			case 2 : zFace = FEET;	break;
			case 1 : zFace = SHOTGUN;	break;
			default : zFace = '\0';	break;
		}
	}
};

#endif //GREEN_DICE_HPP
