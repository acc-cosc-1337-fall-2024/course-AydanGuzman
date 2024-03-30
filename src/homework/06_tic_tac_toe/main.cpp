#include "tic_tac_toe.h"

#include <iostream>
#include <string>

using std::cout; using std::cin;


int main() 
{
	TicTacToe game;
	std::string first_player;
	char user_choice = 'y';

	do
	{
		cout<<"Enter first player: ";
		cin>>first_player;

		game.start_game(first_player);

		int position;

		while(!game.game_over())
		{
			cout<<"Enter a position: ";
			cin>>position;
			game.mark_board(position);
			game.display_board();
		}

		cout<<"Play again? (y or Y for yes) ";
		cin>>user_choice;


	} while (user_choice == 'y' || user_choice == 'Y');
	
	return 0;
}