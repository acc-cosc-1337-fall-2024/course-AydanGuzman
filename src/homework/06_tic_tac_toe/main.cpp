#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"

#include <iostream>
#include <string>

using std::cout; using std::cin; using std::string;


int main() 
{
	
	char user_choice = 'y';

	do 
	{
		TicTacToeManager manager;

		do
		{
			TicTacToe game;
			std::string first_player;

			cout<<"Enter first player (X or O): ";
			cin>>first_player;

			while (first_player != "X" && first_player != "O")
			{
				cout << "Invalid input. Enter X or O: ";
				cin >> first_player;
			}

			game.start_game(first_player);

			int position;

			while(!game.game_over())
			{
				cout<<"Enter a position: ";
				cin>>position;
				game.mark_board(position);
				game.display_board();

				while ((position < 1 || position > 9) || (game.get_player() != "X" && game.get_player() != "O") || (game.get_winner() != ""))
				{
					cout << "Invalid Input. Enter a postion (1-9): ";
					cin.clear();

					cin >> position;
				}
			}

			

			cout << "Game Over!\n";
			game.display_board();
			string winner = game.get_winner();

			if (winner == "C")
			{
				cout<< "C\n";
			}
			else
			{
				cout << "Player " << winner << " wins.\n";
			
			}

			manager.save_game(game);

			cout << "Play again? (y or Y for yes): ";
			cin >> user_choice;
		


		} while (user_choice == 'y' || user_choice == 'Y');

		int x_wins, o_wins, ties;
		manager.get_winner_total(x_wins, o_wins, ties);
		cout << "X wins: " << x_wins << ", O wins: " << o_wins << ", Ties: " << ties << "\n";

		cout << "Play again? (y or Y for yes): ";
		cin >> user_choice;
	


	} while (user_choice == 'y' || user_choice == 'Y');

	return 0;
	
}