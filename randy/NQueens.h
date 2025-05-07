//
// Created by Pablo Ruiz on 4/28/25.
//

#ifndef MALENATEST_NQUEENS_H
#define MALENATEST_NQUEENS_H

#include <iostream>
#include <vector>

class NQueens {
private:
    int _n;
    std::vector<int> board;

    bool Place(int row, int col);
    void run();

public:
    NQueens(int n);
    void solveNQueens(int row = 0);
};


#endif //MALENATEST_NQUEENS_H
