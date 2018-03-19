#include <iostream>
//#include <vector>
#include <string>
#include "Headers/Game.hpp"

/*
#include "Headers/TermColors.hpp"
int main(){
	mee::TermColors term;
	std::cout << term.setText(mee::textColors::RED) << "Hello World" << std::endl;

	return 0;
}
*/

/*
int main(){
	//std::vector<int> vec;
	//vec.push_back(4);
	//vec.push_back(8);
	//vec.push_back(16);

	//for(int cnt = 0;cnt < 5;++cnt){
	//	std::cout << vec.at(cnt) << std::endl;
	//}
	std::cout << u8"\u2660" << u8"\u2665" << u8"\u2663" << u8"\u2666" << std::endl;
	//std::cout << u8"\u2660\u2665\u2663\u2666" << std::endl;
	//std::cin.get();

	//Game game;
	//std::cout << game.print();

	return 0;
}
*/

int main(){
	std::cout << "Welcome to Solitaire!\nPress Enter to begin" << std::endl;
	std::cin.get();

	Game game;
	std::cout << game.printBoard("");
	std::string move;

	while(!game.gameOver()){
		std::cin >> move;
		std::cout << game(move);
	}

	if(game.win()){
		std::cout << "You Won!";
	}

	return 0;
}
/* */
