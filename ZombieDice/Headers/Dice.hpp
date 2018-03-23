//Games/ZombieDice/Headers/Dice.hpp
//Matthew Ellison
// Created: 3-21-18
//Modified: 3-21-18
//This file contains the declaration for the Dice class for the Zombie Dice game

#ifndef DICE_HPP
#define DICE_HPP

#include <random>

class Dice{
private:
	std::default_random_engine generator;
	std::uniform_int_distribution<int> dist;
	int bottom;
	int top;
	int face;
public:
	Dice(int top = 6, int bottom = 1) : dist(bottom, top), generator(std::random_device{}())
	{	this->top = top;	this->bottom = bottom;	face = bottom;	}
	virtual ~Dice()
	{	}
	int getFace()
	{	return face;	}
	int roll()
	{	face = dist(generator);	return face;	}
	virtual char zRoll() = 0;
};

#endif //DICE_HPP