//
// Created by Pablo Ruiz on 4/28/25.
//

#include "NQueens.h"
NQueens::NQueens(int n){
    _n = n;
    board = std::vector<int>(_n);

}
bool NQueens::Place(int row,int col)
{

    for (int j = 0 ; j <= row - 1; j++){
        if ((board[j] == col) || (abs(board[j] - col) == abs(j - row))){
            return false;
        }

    }
    return true;
}
void NQueens::solveNQueens(int row){
    if (_n>=4)
    {
        // Using backtracking, this procedure prints all
        // possible placements of n queens on an n×n
        // chessboard so that they are nonattacking.
        for (int col = 0 ; col < _n ; col++)
        {
            if (Place(row, col))
            {
                board[row] = col;
                if (row == _n -1 ){

                    run();
                }
                else
                    solveNQueens(row+1);
            }

        }
    }
    else
    {
        std::cout <<"No Solutions for " << _n <<std::endl;
    }
}

void NQueens::run() {
    // Print the board with 'Q' for queens and '.' for empty spaces
    std::cout << "Solutions for: " <<  _n << std::endl;
    for (int i = 0; i < _n; i++) {
        for (int j = 0; j < _n; j++) {
            if (board[i] == j) {
                std::cout << "Q ";  // Queen found in this column
            } else {
                std::cout << ". ";  // Empty space
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
