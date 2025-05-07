//
// Created by Pablo Ruiz on 4/28/25.
//

#ifndef MALENATEST_MODEL_H
#define MALENATEST_MODEL_H
#include "Node.h"
#include "Malena/common.hpp"
#include <vector>


using namespace std;
class Model : public ml::Application{
public:
    Model();
    Model(int rows, int cols, int numOfBombs);

    Node* getNodeAt(int row, int col);

    int getRows() const {return _rows;}
    int getCols() const {return _cols;}
    sf::Texture& getTexture() {return texture;}
    sf::IntRect& getIntRect() {return intRect;}


    void requestRedraw() { needsRedraw = true;}

private:

    //vector<sf::Vector2i> fixedBombs = {{1, 1}, {3, 3}, {5, 5}};

    bool needsRedraw = false;
    vector<Node*> squares; ///rectangle button
    sf::Texture texture;
    sf::IntRect intRect;
    ml::Grid board;



    vector<sf::Vector2i> bombs;
    int _rows, _cols, _numOfBombs;

    //BackTracking* solver = nullptr;
    void runSolver();

    void placeBombs();
    void setBoard();
    void setCombinations();
    void generateFlagCombos(const vector<sf::Vector2i>& neighbors, int start, int numToPick, vector<sf::Vector2i>& current, vector<vector<sf::Vector2i>>& results);


    vector<vector<char>> model;



    void initialization() override;
    void registerEvents() override;
    void update();
};


#endif //MALENATEST_MODEL_H
