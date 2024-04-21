#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test if the board is full") 
{
	std::unique_ptr<TicTacToe> game = std::make_unique<TicTacToe>(3);

	game->mark_board(1);
	REQUIRE(game->game_over() == false);

	game->mark_board(2);
	REQUIRE(game->game_over() == false);

	game->mark_board(3);
	REQUIRE(game->game_over() == false);

	game->mark_board(4);
	REQUIRE(game->game_over() == false);

	game->mark_board(5);
	REQUIRE(game->game_over() == false);

	game->mark_board(7);
	REQUIRE(game->game_over() == false);

	game->mark_board(6);
	REQUIRE(game->game_over() == false);

	game->mark_board(9);
	REQUIRE(game->game_over() == false);

	game->mark_board(8);
	REQUIRE(game->game_over() == true);


	
}

TEST_CASE("Test first player X")
{
	std::unique_ptr<TicTacToe> game = std::make_unique<TicTacToe>(3);
	game->start_game("X");
	REQUIRE(game->get_player() == "X");
}

TEST_CASE("Test first player O")
{
	std::unique_ptr<TicTacToe> game = std::make_unique<TicTacToe>(3);
	game->start_game("O");
	REQUIRE(game->get_player() == "O");
}

TEST_CASE("Test game over if 9 slots are selected")
{
	std::unique_ptr<TicTacToe> game = std::make_unique<TicTacToe>(3);
	game->start_game("O");
	game->mark_board(1);
	game->mark_board(3);
	game->mark_board(2);
	game->mark_board(4);
	game->mark_board(5);
	game->mark_board(8);
	game->mark_board(6);
	game->mark_board(9);
	game->mark_board(7);
	
	REQUIRE(game->get_winner() == "C");
}

TEST_CASE("Test win by first column 3")
{
	std::unique_ptr<TicTacToe> game = std::make_unique<TicTacToe>(3);
	game->start_game("X");
	game->mark_board(1);
	game->mark_board(2);
	game->mark_board(4);
	game->mark_board(5);
	game->mark_board(7);
	REQUIRE(game->game_over() == true);
}

TEST_CASE("Test win by second column 3")
{
	std::unique_ptr<TicTacToe> game = std::make_unique<TicTacToe>(3);
	game->start_game("X");
	game->mark_board(2);
	game->mark_board(1);
	game->mark_board(5);
	game->mark_board(6);
	game->mark_board(8);
	REQUIRE(game->game_over() == true);
}

TEST_CASE("Test win by third column 3")
{
	std::unique_ptr<TicTacToe> game = std::make_unique<TicTacToe>(3);
	game->start_game("X");
	game->mark_board(3);
	game->mark_board(2);
	game->mark_board(6);
	game->mark_board(7);
	game->mark_board(9);
	REQUIRE(game->game_over() == true);
}

TEST_CASE("Test win by first row 3")
{
	std::unique_ptr<TicTacToe> game = std::make_unique<TicTacToe>(3);
	game->start_game("X");
	game->mark_board(1);
	game->mark_board(5);
	game->mark_board(2);
	game->mark_board(4);
	game->mark_board(3);
	REQUIRE(game->game_over() == true);
}

TEST_CASE("Test win by second row 3")
{
	std::unique_ptr<TicTacToe> game = std::make_unique<TicTacToe>(3);
	game->start_game("X");
	game->mark_board(4);
	game->mark_board(2);
	game->mark_board(5);
	game->mark_board(3);
	game->mark_board(6);
	REQUIRE(game->game_over() == true);
}

TEST_CASE("Test win by third row 3")
{
	std::unique_ptr<TicTacToe> game = std::make_unique<TicTacToe>(3);
	game->start_game("X");
	game->mark_board(7);
	game->mark_board(2);
	game->mark_board(8);
	game->mark_board(1);
	game->mark_board(9);
	REQUIRE(game->game_over() == true);
}

TEST_CASE("Test win by first diagonal 3")
{
	std::unique_ptr<TicTacToe> game = std::make_unique<TicTacToe>(3);
	game->start_game("X");
	game->mark_board(1);
	game->mark_board(2);
	game->mark_board(5);
	game->mark_board(3);
	game->mark_board(9);
	REQUIRE(game->game_over() == true);
}

TEST_CASE("Test win by second diagonal 3")
{
	std::unique_ptr<TicTacToe> game = std::make_unique<TicTacToe>(3);
	game->start_game("X");
	game->mark_board(3);
	game->mark_board(2);
	game->mark_board(5);
	game->mark_board(6);
	game->mark_board(7);
	REQUIRE(game->game_over() == true);
}

TEST_CASE("Test TicTacToe manager get winner total function 3")
{
	TicTacToeManager manager;
	std::unique_ptr<TicTacToe> game1 = std::make_unique<TicTacToe>(3);
	std::unique_ptr<TicTacToe> game2 = std::make_unique<TicTacToe>(3);
	std::unique_ptr<TicTacToe> game3 = std::make_unique<TicTacToe>(3);

	game1->start_game("X");
	game1->mark_board(1);
	game1->mark_board(2);
	game1->mark_board(4);
	game1->mark_board(5);
	game1->mark_board(7);

	manager.save_game(std::move(game1));

	game2->start_game("O");
	game2->mark_board(1);
	game2->mark_board(2);
	game2->mark_board(4);
	game2->mark_board(5);
	game2->mark_board(7);

	manager.save_game(std::move(game2));
	
	game3->start_game("C");
	game3->mark_board(1);
	game3->mark_board(3);
	game3->mark_board(2);
	game3->mark_board(4);
	game3->mark_board(5);
	game3->mark_board(8);
	game3->mark_board(6);

	manager.save_game(std::move(game3));

	int x_wins, o_wins, ties;
	manager.get_winner_total(x_wins, o_wins, ties);
	REQUIRE(x_wins == 1);
	REQUIRE(o_wins == 1);
	REQUIRE(ties == 1);

}

TEST_CASE("Test a win by first column 4")
{
	std::unique_ptr<TicTacToe> game = std::make_unique<TicTacToe>(4);
	game->start_game("X");
	game->mark_board(1);
	game->mark_board(2);
	game->mark_board(5);
	game->mark_board(3);
	game->mark_board(9);
	game->mark_board(4);
	game->mark_board(13);

	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");

}

TEST_CASE("Test a win by second column 4")
{
	std::unique_ptr<TicTacToe> game = std::make_unique<TicTacToe>(4);
	game->start_game("X");
	game->mark_board(2);
	game->mark_board(1);
	game->mark_board(6);
	game->mark_board(3);
	game->mark_board(10);
	game->mark_board(4);
	game->mark_board(14);

	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");

}

TEST_CASE("Test a win by third column 4")
{
	std::unique_ptr<TicTacToe> game = std::make_unique<TicTacToe>(4);
	game->start_game("X");
	game->mark_board(3);
	game->mark_board(1);
	game->mark_board(7);
	game->mark_board(2);
	game->mark_board(11);
	game->mark_board(4);
	game->mark_board(15);

	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");

}

TEST_CASE("Test a win by fourth column 4")
{
	std::unique_ptr<TicTacToe> game = std::make_unique<TicTacToe>(4);
	game->start_game("X");
	game->mark_board(4);
	game->mark_board(1);
	game->mark_board(8);
	game->mark_board(2);
	game->mark_board(12);
	game->mark_board(3);
	game->mark_board(16);

	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");

}

TEST_CASE("Test a win by first row 4")
{
	std::unique_ptr<TicTacToe> game = std::make_unique<TicTacToe>(4);
	game->start_game("X");
	game->mark_board(1);
	game->mark_board(5);
	game->mark_board(2);
	game->mark_board(6);
	game->mark_board(3);
	game->mark_board(7);
	game->mark_board(4);

	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");

}

TEST_CASE("Test a win by second row 4")
{
	std::unique_ptr<TicTacToe> game = std::make_unique<TicTacToe>(4);
	game->start_game("X");
	game->mark_board(5);
	game->mark_board(1);
	game->mark_board(6);
	game->mark_board(2);
	game->mark_board(7);
	game->mark_board(3);
	game->mark_board(8);

	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");

}

TEST_CASE("Test a win by third row 4")
{
	std::unique_ptr<TicTacToe> game = std::make_unique<TicTacToe>(4);
	game->start_game("X");
	game->mark_board(9);
	game->mark_board(1);
	game->mark_board(10);
	game->mark_board(2);
	game->mark_board(11);
	game->mark_board(3);
	game->mark_board(12);

	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");

}

TEST_CASE("Test a win by fourth row 4")
{
	std::unique_ptr<TicTacToe> game = std::make_unique<TicTacToe>(4);
	game->start_game("X");
	game->mark_board(13);
	game->mark_board(1);
	game->mark_board(14);
	game->mark_board(2);
	game->mark_board(15);
	game->mark_board(3);
	game->mark_board(16);

	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");

}

TEST_CASE("Test a win by diagonal1 row 4")
{
	std::unique_ptr<TicTacToe> game = std::make_unique<TicTacToe>(4);
	game->start_game("X");
	game->mark_board(1);
	game->mark_board(2);
	game->mark_board(6);
	game->mark_board(3);
	game->mark_board(11);
	game->mark_board(4);
	game->mark_board(16);

	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");

}

TEST_CASE("Test a win by diagonal2 row 4")
{
	std::unique_ptr<TicTacToe> game = std::make_unique<TicTacToe>(4);
	game->start_game("X");
	game->mark_board(4);
	game->mark_board(2);
	game->mark_board(7);
	game->mark_board(3);
	game->mark_board(10);
	game->mark_board(12);
	game->mark_board(13);

	REQUIRE(game->game_over() == true);
	REQUIRE(game->get_winner() == "X");

}