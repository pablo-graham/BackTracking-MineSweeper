//
// Created by Pablo Ruiz on 4/28/25.
//

#ifndef MALENATEST_BACKTRACKING_H
#define MALENATEST_BACKTRACKING_H

//#include "Malena/common.hpp"
#include <iostream>
#include <vector>
#include <string>
#include "Model.h"

using namespace std;

class BackTracking {
public:
    explicit BackTracking(Model* model);
    bool solve();

    // For visualization control
    bool isSolving() const { return mIndex < solvableNodes.size(); }
    const vector<sf::Vector2i>& getCurrentFlags() const {return currentFlags;}
    bool isSolved();

    void recordStep(const vector<sf::Vector2i>& step) {solvingSteps.push_back(step);}
    const vector<vector<sf::Vector2i>>& getStepHistory() const {return solvingSteps;}
    const auto& getSolvingSteps() const {return solvingSteps;}
    vector<Node*> getNumberedNodes() const;
    bool validatePartialSolution(int limit) const;

private:
    Model* model;
    vector<Node*> solvableNodes;
    vector<sf::Vector2i> currentFlags;
    int mIndex = 0;
    vector<vector<sf::Vector2i>> solvingSteps;
    sf::Texture* texture;
    sf::IntRect* intRect;

    bool solveRecursive(int index);
    bool canPlaceFlags(const vector<sf::Vector2i>& combo) const;
    void placeFlags(const vector<sf::Vector2i>& combo, Node* node);
    void removeFlags(const vector<sf::Vector2i>& combo, Node *node);
    bool validateSolution() const;
    int countAdjacentFlags(const sf::Vector2i& pos) const;
};



///failed backtracking
/*
class BackTracking {
private:
    Model* minesweeper;
    vector<Node*> solvableNodes;

    //sf::Texture texture;


    bool solveRecursive(int index);
    vector<Node*> getSolvableNodes();
    bool canPlaceBomb(const vector<sf::Vector2i>& combination);
    void placeFlag(const vector<sf::Vector2i>& combination);
    void removeFlag(const vector<sf::Vector2i>& combination);
    bool isSolved();
public:
    BackTracking(Model* m);

    bool solve();
};

 */

#endif //MALENATEST_BACKTRACKING_H
