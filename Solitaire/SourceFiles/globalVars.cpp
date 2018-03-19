#include "../Headers/globalVars.hpp"
#include "../Headers/TermColors.hpp"

//const unsigned int NUM_PILES = 7;
const mee::textColors CARD_BACK_COLOR = mee::textColors::BLUE;
const char CARD_BACK[4] = "#*#";
const mee::textColors BLACK_CARD_COLOR = mee::textColors::WHITE;
const mee::textColors RED_CARD_COLOR = mee::textColors::RED;

///Card locations
const unsigned int TOP_ROW = 2;
const unsigned int COL_OFFSET = 2;
const unsigned int COL_WIDTH = 5;


//Columns
const unsigned int FIRST_COL = 1;
const unsigned int SECOND_COL = FIRST_COL + COL_WIDTH + COL_OFFSET;
const unsigned int THIRD_COL = SECOND_COL + COL_WIDTH + COL_OFFSET;
const unsigned int FOURTH_COL = THIRD_COL + COL_WIDTH + COL_OFFSET;
const unsigned int FIFTH_COL = FOURTH_COL + COL_WIDTH + COL_OFFSET;
const unsigned int SIXTH_COL = FIFTH_COL + COL_WIDTH + COL_OFFSET;
const unsigned int SEVENTH_COL = SIXTH_COL + COL_WIDTH + COL_OFFSET;
const unsigned int EIGHTH_COL = SEVENTH_COL + COL_WIDTH + COL_OFFSET;

const unsigned int COLUMNS[] {FIRST_COL, SECOND_COL, THIRD_COL, FOURTH_COL, FIFTH_COL, SIXTH_COL, SEVENTH_COL, EIGHTH_COL};


//Draw
const unsigned int DRAW_ROW = TOP_ROW;
const unsigned int DRAW_COL = FIRST_COL;


//Discard
const unsigned int DISCARD_ROW = TOP_ROW;
const unsigned int DISCARD_COL = SECOND_COL;


//Foundations
const unsigned int FOUNDATION1_ROW = TOP_ROW;
const unsigned int FOUNDATION1_COL = FOURTH_COL;
const unsigned int FOUNDATION2_ROW = TOP_ROW;
const unsigned int FOUNDATION2_COL = FIFTH_COL;
const unsigned int FOUNDATION3_ROW = TOP_ROW;
const unsigned int FOUNDATION3_COL = SIXTH_COL;
const unsigned int FOUNDATION4_ROW = TOP_ROW;
const unsigned int FOUNDATION4_COL = SEVENTH_COL;

const unsigned int FOUNDATION_ROWS[] {FOUNDATION1_ROW, FOUNDATION2_ROW, FOUNDATION3_ROW, FOUNDATION4_ROW};
const unsigned int FOUNDATION_COLS[] {FOUNDATION1_COL, FOUNDATION2_COL, FOUNDATION3_COL, FOUNDATION4_COL};


//Piles
const unsigned int PILES_TOP_ROW = 4;

