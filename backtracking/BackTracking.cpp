//
// Created by Pablo Ruiz on 4/28/25.
//

#include "BackTracking.h"
#include "Malena/Utilities/TextureSlicer.h"
#include <chrono>
BackTracking::BackTracking(Model* m) : model(m), texture(&m->getTexture()), intRect(&m->getIntRect()){
    //texture.loadFromFile("/Users/pabloruiz/CLionProjects/New_Malena/MineSweeper/TextureSlicerDemo/minesweep_cut.png");
    cout << "BackTracking Class Called\n";
    for (int row = 0; row < model->getRows(); row++) {
        for (int col = 0; col < model->getCols(); col++) {
            cout << "getting node - >";
            Node* node = model->getNodeAt(row, col);
            //all numbered nodes
            if (node && node->getBombCount() > 0) {
                cout << "pushing node";
                solvableNodes.push_back(node);
            }
            cout << endl;
        }
    }
}

bool BackTracking::solve() {
    cout << "solve() called\n";
    return solveRecursive(0);
}

bool BackTracking::solveRecursive(int index) {
    cout << "\nsolveRecursive() called\n";
    if(index == solvableNodes.size()){
        cout << "[last index] ->";
        if(isSolved()){ // Check if all nodes have correct bomb count
            cout << "-> solved\n";
            return true;
        }else{
            cout << "-> not solved\n";
            return false;
        }
    }

    Node* current = solvableNodes[index];
    cout << "grabbed node at (" << current->getCoords().x << ", " << current->getCoords().y << ")\n";
    const auto& combinations = current->getCombinations();
    cout << "combination size: " << combinations.size() << endl;
    for (const auto& combo : combinations){
        cout << "combo size [" << combo.size() << "]\n";
        if (canPlaceFlags(combo)){ // Check if bombs can be placed without breaking the board's rules
            placeFlags(combo, current); // Place bombs for this combination
            cout << "placed flagged\nchecking next index";
            if (solveRecursive(index + 1)) {
                cout << "all flags placed\n";
                return true;
            }
            cout << "removing flags\n";
            removeFlags(combo, current);
        }
    }

    cout << "returning false\n";
    return false;
}

bool BackTracking::isSolved(){
    cout << "isSolved called\n";
    for (Node* node : solvableNodes) {
        int expectedBombs = node->getBombCount();
        int actualFlags = 0;

        for (int row = -1;row <= 1; row++) {
            for (int col = -1; col <= 1; col++) {
                if (row == 0 && col == 0) continue;

                int r = node->getCoords().x + row;
                int c = node->getCoords().y + col;

                Node* neighbor = model->getNodeAt(r, c);
                if (neighbor && neighbor->getFlagged()) {
                    actualFlags++;
                }
            }
        }

        if (actualFlags != expectedBombs) {
            return false;
        }
    }
    return true;
}

bool BackTracking::canPlaceFlags(const vector<sf::Vector2i> &combo) const {
    cout << "canPlaceFlags() called\n";
    return true;
}

void BackTracking::placeFlags(const vector<sf::Vector2i> &combo, Node *node) {
    cout << "placeFlags() called\n";
    //sf::sleep(sf::milliseconds(100));

    ml::ImageRects rects = TextureSlicer::getImageRects(*texture, 11, 12);
    for(auto flag : combo){
        model->getNodeAt(flag.x, flag.y)->setFlagged(true);
        *intRect = rects.getIntRect(2, 0);
        model->getNodeAt(flag.x, flag.y)->setTextureRect(*intRect);
        model->getNodeAt(flag.x, flag.y)->setTexture(*(&texture));
    }
}

void BackTracking::removeFlags(const vector<sf::Vector2i> &combo, Node *node) {
    cout << "removeFlags() called\n";
    //sf::sleep(sf::milliseconds(100));

    ml::ImageRects rects = TextureSlicer::getImageRects(*texture, 11, 12);
    for(auto flag : combo){
        model->getNodeAt(flag.x, flag.y)->setFlagged(false);
        *intRect = rects.getIntRect(0, 0);
        model->getNodeAt(flag.x, flag.y)->setTextureRect(*intRect);
        model->getNodeAt(flag.x, flag.y)->setTexture(*(&texture));
    }
}
