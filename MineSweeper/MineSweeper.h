//
// Created by Pablo Ruiz on 4/21/25.
//

#ifndef MALENATEST_MINESWEEPER_H
#define MALENATEST_MINESWEEPER_H

#include "Malena/common.hpp"
#include <vector>
#include "./TextureSlicerDemo/Bomb.h"

class MineSweeper : public ml::Application {
public:
    std::vector<ml::RectangleButton* > squares;
    sf::Texture texture;
    ml::Grid board;
    MineSweeper();
    MineSweeper(int rows, int cols);
    void start();

private:
    int _rows, _cols;
    void initialization() override;
    void registerEvents() override;
};


/*
place random bombs
add the numbers based on the board
*/
#endif //MALENATEST_MINESWEEPER_H
