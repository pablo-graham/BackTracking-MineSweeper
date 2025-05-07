//
// Created by Pablo Ruiz on 4/21/25.
//

#include "MineSweeper.h"
#include "Malena/Utilities/TextureSlicer.h"


MineSweeper::MineSweeper() : Application(sf::VideoMode({720, 420}, 32), "Text Input", *this){
    _rows = 12;
    _cols = 11;
    board = ml::Grid(sf::Vector2u(12,11));
}

MineSweeper::MineSweeper(int rows, int cols) : Application(sf::VideoMode({720, 420}, 32), "Text Input", *this), board(sf::Vector2u(rows, cols)){
    _rows = rows;
    _cols = cols;
}

void MineSweeper::initialization() {
    for(int i = 0; i < _rows; i++){
        for(int j = 0; j < _cols; j++){
            ml::RectangleButton* sq = new ml::RectangleButton();
            sq->setSize({50.f, 50.f});
            texture.loadFromFile("/Users/pabloruiz/CLionProjects/New_Malena/MineSweeper/TextureSlicerDemo/minesweep_cut.png");
            ml::ImageRects rects = TextureSlicer::getImageRects(texture, 11, 12);
            sf::IntRect intRect = rects.getIntRect(0, 13);

            sq->setTextureRect(intRect);
            sq->setTexture(&texture);

            squares.push_back(sq);
            board.addComponent(*sq);
        }
    }

    addComponent(board);
    std::cout << "Components added: " << board.getUIComponents().size() << std::endl;
}

void MineSweeper::registerEvents() {
//    auto changeColor = [](ml::RectangleButton* button){
//        return [button](){
//            if (button->checkState(ml::Stateful::ENABLED)) {
//                button->setFillColor(sf::Color::Blue);
//                button->disableState(ml::Stateful::ENABLED);
//            } else {
//                button->setFillColor(sf::Color::White);
//                button->enableState(ml::Stateful::ENABLED);
//            }
//        };
//    };
//
//    for(auto& box : squares){
//        box->onClick(changeColor(box));
//    }

}



/*original code (pre-texture)
 * MineSweeper::MineSweeper() : Application(sf::VideoMode({720, 420}, 32), "Text Input", *this){
    board = ml::Grid(sf::Vector2u(4,4));
    _rows = _cols = 4;
}

MineSweeper::MineSweeper(int rows, int cols) : Application(sf::VideoMode({720, 420}, 32), "Text Input", *this), board(sf::Vector2u(rows, cols)){
    _rows = rows;
    _cols = cols;
}

void MineSweeper::initialization() {
    for(int i = 0; i < _rows * _cols; i++){
        ml::RectangleButton* sq = new ml::RectangleButton();

        sq->setFillColor(sf::Color::White);
        sq->setSize({50, 50});

        squares.push_back(sq);
        board.addComponent(*sq);
    }

    addComponent(board);
    std::cout << "Components added: " << board.getUIComponents().size() << std::endl;
}

void MineSweeper::registerEvents() {
    auto changeColor = [](ml::RectangleButton* button){
        return [button](){
            if (button->checkState(ml::Stateful::ENABLED)) {
                button->setFillColor(sf::Color::Blue);
                button->disableState(ml::Stateful::ENABLED);
            } else {
                button->setFillColor(sf::Color::White);
                button->enableState(ml::Stateful::ENABLED);
            }
        };
    };

    for(auto& box : squares){
        box->onClick(changeColor(box));
    }

}



 */