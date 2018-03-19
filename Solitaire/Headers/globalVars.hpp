//Games/Solitaire/Headers/globalVars.hpp
//Matthew Ellison
// Created: 3-8-18
//Modified: 3-8-18
//This file contains the global variables for the Solitaire game


#ifndef GLOBAL_VARS_HPP
#define GLOBAL_VARS_HPP
//#pragma once

#include "TermColors.hpp"

#define NUM_PILES 7
extern const mee::textColors CARD_BACK_COLOR;
extern const char CARD_BACK[4];
extern const mee::textColors BLACK_CARD_COLOR;
extern const mee::textColors RED_CARD_COLOR;

///Card locations
extern const unsigned int TOP_ROW;
extern const unsigned int COL_OFFSET;
extern const unsigned int COL_WIDTH;


//Columns
extern const unsigned int FIRST_COL;
extern const unsigned int SECOND_COL;
extern const unsigned int THIRD_COL;
extern const unsigned int FOURTH_COL;
extern const unsigned int FIFTH_COL;
extern const unsigned int SIXTH_COL;
extern const unsigned int SEVENTH_COL;
extern const unsigned int EIGHTH_COL;

extern const unsigned int COLUMNS[];


//Draw
extern const unsigned int DRAW_ROW;
extern const unsigned int DRAW_COL;


//Discard
extern const unsigned int DISCARD_ROW;
extern const unsigned int DISCARD_COL;


//Foundations
extern const unsigned int FOUNDATION1_ROW;
extern const unsigned int FOUNDATION1_COL;
extern const unsigned int FOUNDATION2_ROW;
extern const unsigned int FOUNDATION2_COL;
extern const unsigned int FOUNDATION3_ROW;
extern const unsigned int FOUNDATION3_COL;
extern const unsigned int FOUNDATION4_ROW;
extern const unsigned int FOUNDATION4_COL;

extern const unsigned int FOUNDATION_ROWS[];
extern const unsigned int FOUNDATION_COLS[];


//Piles
extern const unsigned int PILES_TOP_ROW;


#endif //GLOBAL_VARS_HPP
