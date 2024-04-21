//cpp
#include "tic_tac_toe_manager.h"
#include <iostream>

void TicTacToeManager::save_game(std::unique_ptr<TicTacToe>&& game) 
{
    update_winner_count(game->get_winner());
    games.push_back(std::move(game));
}

void TicTacToeManager::get_winner_total(int& x, int& o, int& t)
{
    x = x_win;
    o = o_win;
    t = ties;
} 
 
void TicTacToeManager::update_winner_count(std::string winner)
{
    if (winner == "X")
        x_win++;
    else if (winner == "O")
        o_win++;
    else if (winner == "C")
        ties++;
}

void TicTacToeManager::display()
{
    for (const auto& game : games)
    {
        
        game->display_board();
        std::cout << "\n";
    }
}