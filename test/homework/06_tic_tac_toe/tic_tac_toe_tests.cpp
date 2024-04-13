#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test if the board is full") 
{
	TicTacToe game;

	game.mark_board(1);
	REQUIRE(game.game_over() == false);

	game.mark_board(2);
	REQUIRE(game.game_over() == false);

	game.mark_board(3);
	REQUIRE(game.game_over() == false);

	game.mark_board(4);
	REQUIRE(game.game_over() == false);

	game.mark_board(5);
	REQUIRE(game.game_over() == false);

	game.mark_board(7);
	REQUIRE(game.game_over() == false);

	game.mark_board(6);
	REQUIRE(game.game_over() == false);

	game.mark_board(9);
	REQUIRE(game.game_over() == false);

	game.mark_board(8);
	REQUIRE(game.game_over() == true);

	
}

TEST_CASE("Test first player X")
{
	TicTacToe game;
	game.start_game("X");
	REQUIRE(game.get_player() == "X");
}

TEST_CASE("Test first player O")
{
	TicTacToe game;
	game.start_game("O");
	REQUIRE(game.get_player() == "O");
}

TEST_CASE("Test game over if 9 slots are selected")
{
	TicTacToe game;
	game.start_game("O");
	game.mark_board(1);
	game.mark_board(3);
	game.mark_board(2);
	game.mark_board(4);
	game.mark_board(5);
	game.mark_board(8);
	game.mark_board(6);
	game.mark_board(9);
	game.mark_board(7);
	
	REQUIRE(game.get_winner() == "C");
}

TEST_CASE("Test win by first column")
{
	TicTacToe game;
	game.start_game("X");
	game.mark_board(1);
	game.mark_board(2);
	game.mark_board(4);
	game.mark_board(5);
	game.mark_board(7);
	REQUIRE(game.game_over() == true);
}

TEST_CASE("Test win by second column")
{
	TicTacToe game;
	game.start_game("X");
	game.mark_board(2);
	game.mark_board(1);
	game.mark_board(5);
	game.mark_board(6);
	game.mark_board(8);
	REQUIRE(game.game_over() == true);
}

TEST_CASE("Test win by third column")
{
	TicTacToe game;
	game.start_game("X");
	game.mark_board(3);
	game.mark_board(2);
	game.mark_board(6);
	game.mark_board(7);
	game.mark_board(9);
	REQUIRE(game.game_over() == true);
}

TEST_CASE("Test win by first row")
{
	TicTacToe game;
	game.start_game("X");
	game.mark_board(1);
	game.mark_board(5);
	game.mark_board(2);
	game.mark_board(4);
	game.mark_board(3);
	REQUIRE(game.game_over() == true);
}

TEST_CASE("Test win by second row")
{
	TicTacToe game;
	game.start_game("X");
	game.mark_board(4);
	game.mark_board(2);
	game.mark_board(5);
	game.mark_board(3);
	game.mark_board(6);
	REQUIRE(game.game_over() == true);
}

TEST_CASE("Test win by third row")
{
	TicTacToe game;
	game.start_game("X");
	game.mark_board(7);
	game.mark_board(2);
	game.mark_board(8);
	game.mark_board(1);
	game.mark_board(9);
	REQUIRE(game.game_over() == true);
}

TEST_CASE("Test win by first diagonal")
{
	TicTacToe game;
	game.start_game("X");
	game.mark_board(1);
	game.mark_board(2);
	game.mark_board(5);
	game.mark_board(3);
	game.mark_board(9);
	REQUIRE(game.game_over() == true);
}

TEST_CASE("Test win by second diagonal")
{
	TicTacToe game;
	game.start_game("X");
	game.mark_board(3);
	game.mark_board(2);
	game.mark_board(5);
	game.mark_board(6);
	game.mark_board(7);
	REQUIRE(game.game_over() == true);
}

TEST_CASE("Test TicTacToe manager get winner total function")
{
	TicTacToeManager manager;
	TicTacToe game1;
	TicTacToe game2;
	TicTacToe game3;

	game1.start_game("X");
	game1.mark_board(1);
	game1.mark_board(2);
	game1.mark_board(4);
	game1.mark_board(5);
	game1.mark_board(7);

	manager.save_game(game1);

	game2.start_game("O");
	game2.mark_board(1);
	game2.mark_board(2);
	game2.mark_board(4);
	game2.mark_board(5);
	game2.mark_board(7);

	manager.save_game(game2);
	
	game3.start_game("C");
	game3.mark_board(1);
	game3.mark_board(3);
	game3.mark_board(2);
	game3.mark_board(4);
	game3.mark_board(5);
	game3.mark_board(8);
	game3.mark_board(6);

	manager.save_game(game3);

	int x_wins, o_wins, ties;
	manager.get_winner_total(x_wins, o_wins, ties);
	REQUIRE(x_wins == 1);
	REQUIRE(o_wins == 1);
	REQUIRE(ties == 1);

}