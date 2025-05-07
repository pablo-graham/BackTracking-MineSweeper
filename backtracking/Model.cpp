//
// Created by Pablo Ruiz on 4/28/25.
//

#include "Model.h"
#include "Malena/Utilities/TextureSlicer.h"
#include <ctime>
#include <thread>
//#include "BackTracking.h"

Model::Model(int rows, int cols, int numOfBombs) :Application(sf::VideoMode({720, 420}, 32), "Text Input", *this), board(sf::Vector2u(rows, cols)), _rows(rows), _cols(cols), _numOfBombs(numOfBombs){
    board.setSpacing(0);

    model.resize(_rows);
    for(auto& rows : model){
        rows.resize(_cols);
    }

    placeBombs();
    setBoard();
    setCombinations();
}

Model::Model() : Application(sf::VideoMode({720, 420}, 32), "Text Input", *this) {
    _rows = 8;
    _cols = 5;
    _numOfBombs = 6;
    board = ml::Grid(sf::Vector2u(_rows,_cols));
    board.setSpacing(0);
    model.resize(_rows);

    for(auto& rows : model){
        rows.resize(_cols);
    }

    placeBombs();
    setBoard();
    for(auto i : model){
        for(auto j : i){
            cout << " " << j << " ";
        }
        cout << "\n";
    }
    setCombinations();

//    BackTracking solve(this);
//
//    if (solve.solve()) {
//        cout << "Solution found!\n";
//    } else {
//        cout << "No solution found!\n";
//    }
}

void Model::placeBombs() {
    bombs.clear();

//    vector<sf::Vector2i> fixedBombs = {
//            {1, 1}, {2, 3}, {3, 0}
//    };
//
//    for (auto& pos : fixedBombs) {
//        model[pos.x][pos.y] = 'B';
//        bombs.push_back(pos);
//    }

    srand(time(nullptr));

    while (bombs.size() < _numOfBombs){
        int r = rand() % _rows;
        int c = rand() % _cols;

        if (model[r][c] != 'B'){
            model[r][c] = 'B';
            bombs.emplace_back(r, c);
        }
    }

}

void Model::initialization() {
    addComponent(board);
}

void Model::update() {
}

void Model::runSolver() {
//    BackTracking solver(this);
//    if (solver.solve()) {
//        cout << "Solved!\n";
//    }
}

void Model::registerEvents() {
}

void Model::setBoard() {
    texture.loadFromFile("/Users/pabloruiz/CLionProjects/New_Malena/MineSweeper/TextureSlicerDemo/minesweep_cut.png");
    ml::ImageRects rects = TextureSlicer::getImageRects(texture, 11, 12);

    for(int i = 0; i < _rows; i++){
        for(int j = 0; j < _cols; j++){
            Node* sq = nullptr;
            sf::IntRect intRect;

            if (model[i][j] == 'B'){
                //sq = new Node(i, j, 0, true); //this sets it as bomb
                sq = new Node(i, j, 0, false);
                sq->setSize({50.f, 50.f});
//                intRect = rects.getIntRect(5, 0);
                intRect = rects.getIntRect(0, 0);
                sq->setTextureRect(intRect);

            }else{
                int bombsInArea = 0;
                for(int checkRow = -1; checkRow <= 1; checkRow++){
                    for(int checkCol = -1; checkCol <= 1; checkCol++){

                        int newI = i + checkRow;
                        int newJ = j + checkCol;

                        //making sure it is in bounds and if it is bomb
                        if(newI >= 0 && newI < _rows && newJ >= 0 && newJ < _cols && model[newI][newJ] == 'B'){
                            bombsInArea++;
                        }
                    }
                }

                model[i][j] = bombsInArea + '0'; // convert int to char

                switch (bombsInArea){
                    case 0:
                        sq = new Node(i, j, 0, false);
                        intRect = rects.getIntRect(0, 0);
                        break;
                    case 1:
                        sq = new Node(i, j, 1, false);
                        intRect = rects.getIntRect(0, 1);
                        break;
                    case 2:
                        sq = new Node(i, j, 2, false);
                        intRect = rects.getIntRect(1, 1);
                        break;
                    case 3:
                        sq = new Node(i, j, 3, false);
                        intRect = rects.getIntRect(2, 1);
                        break;
                    case 4:
                        sq = new Node(i, j, 4, false);
                        intRect = rects.getIntRect(3, 1);
                        break;
                    case 5:
                        sq = new Node(i, j, 5, false);
                        intRect = rects.getIntRect(4, 1);
                        break;
                    case 6:
                        sq = new Node(i, j, 6, false);
                        intRect = rects.getIntRect(5, 1);
                        break;
                    case 7:
                        sq = new Node(i, j, 7, false);
                        intRect = rects.getIntRect(6, 1);
                        break;
                    case 8:
                        sq = new Node(i, j, 8, false);
                        intRect = rects.getIntRect(7, 1);
                        break;
                    default:
                        sq = new Node(i, j, -1, false);
                        intRect = rects.getIntRect(3, 0);
                }
            }

            sq->setSize({50.f, 50.f});
            sq->setTextureRect(intRect);
            sq->setTexture(&texture);
            squares.push_back(sq);
            board.addComponent(*sq);
        }
    }
}

void Model::setCombinations() {
    for(int i = 0; i < _rows; i++) {
        for(int j = 0; j < _cols; j++) {
            Node* sq = getNodeAt(i, j);
            //cheks that it is not a bomb and that it has bombs around
            if(sq->getBombCount() > 0){
                vector<sf::Vector2i> neighbors;

                //checking surroundings
                for(int checkRow = -1; checkRow <= 1; checkRow++){
                    for(int checkCol = -1; checkCol <= 1; checkCol++){

                        if (checkRow == 0 && checkCol == 0) continue; ///self

                        int newRow = i + checkRow;
                        int newCol = j + checkCol;

                        Node* neighborNode = getNodeAt(newRow, newCol);

                        //add coords if empty tile
                        if (neighborNode && neighborNode->getBombCount() == 0){
                            neighbors.emplace_back(newRow, newCol);
                        }
                    }
                }

                vector<vector<sf::Vector2i>> allCombos;
                vector<sf::Vector2i> currentCombo;

                generateFlagCombos(neighbors, 0, sq->getBombCount(), currentCombo, allCombos);

                for(const auto& combo : allCombos){
                    sq->addCombination(combo);
                }


                if (!sq->getCombinations().empty()) {
                    //cout << "Node at " << i << "," << j << " expects " << sq->getBombCount() << " bombs and has " << sq->getCombinations().size() << " combos:\n";
                    for (const auto& combo : sq->getCombinations()) {
                        cout << "   ";
                        for (const auto& pos : combo)
                            cout << "(" << pos.x << "," << pos.y << ") ";
                        cout << "\n";
                    }
                }
            }
        }
    }


    ///DEBUGING
    for(int i = 0; i < _rows; i++){
        for(int j = 0; j < _cols; j++){
            Node* sq = getNodeAt(i, j);

            const auto& combos = sq->getCombinations();
            if(!combos.empty()){
                cout << "Node(" << i << "," << j << ") has combinations:\n";
                for(const auto& combo : combos){
                    for(const auto& pos : combo){
                        cout << "(" << pos.x << ", " << pos.y << ") ";
                    }
                    cout << endl;
                }
            }
        }
    }
}

//from sudocode
void Model::generateFlagCombos(const vector<sf::Vector2i>& neighbors, int start, int numToPick, vector<sf::Vector2i>& current, vector<vector<sf::Vector2i>>& results) {
    if (current.size() == numToPick){
        results.push_back(current);
        return;
    }

    for (int i = start; i < neighbors.size(); ++i){
        current.push_back(neighbors[i]);
        generateFlagCombos(neighbors, i + 1, numToPick, current, results);
        current.pop_back();
    }
}

Node* Model::getNodeAt(int row, int col) {
    if(row < 0 || row >= _rows || col < 0 || col >= _cols)
        return nullptr;

    return squares[row * _cols + col];
}

