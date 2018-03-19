//Games/Solitaire/HEaders/TermColors.hpp
//Matthew Ellison
// Created: 3-6-18
//Modified: 3-6-18
//This file contains the class that helps control the colors presented on the terminal
//It will also aid in printing all of the cards and stacks of cards
//This class uses the ANSI escape sequences to color the terminal


#ifndef TERMCOLORS_HPP
#define TERMCOLORS_HPP

namespace mee{


enum class textAttributes {ALL_OFF, BOLD, UNDERSCORE = 4, BLINK};
enum class textColors {BLACK = 30, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE};
enum class backColors {BLACK = 40, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE};

#include <string>
#include <sstream>

class TermColors{
private:
public:
	TermColors()
	{		}
	std::string eraseLine()
	{	return "\033[K";	}
	std::string eraseLine(unsigned int row){
		std::stringstream text;
		text << "\033[" << row << ";0H\033[2J";
		return text.str();
	}
	std::string eraseScreen()
	{	return "\033[2J";	}
	std::string setAttr(mee::textAttributes atr){

	}
	std::string setText(mee::textColors txt){
		std::stringstream text;
		text << "\033[" << static_cast<int>(txt) << 'm';
		return text.str();
	}
	std::string setBackground(mee::backColors bck){
		std::stringstream text;
		text << "\033[" << static_cast<int>(bck) << 'm';
		return text.str();
	}
	std::string setColor(mee::textColors txt, mee::backColors bck){
		std::stringstream text;
		text << "\033[" << static_cast<int>(txt) << ';' << static_cast<int>(bck) << 'm';
		return text.str();
	}
	std::string setPos(unsigned int row, unsigned int col = 0){
		std::stringstream text;
		text << "\033[" << row << ';' << col << 'H';
		return text.str();
	}
};	//End TermColors

}	//End namespace mee

#endif //TERMCOLORS_HPP
