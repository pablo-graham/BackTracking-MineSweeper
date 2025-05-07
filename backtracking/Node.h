//
// Created by Pablo Ruiz on 4/28/25.
//

#ifndef MALENATEST_NODE_H
#define MALENATEST_NODE_H
#include "Malena/common.hpp"
#include <vector>

using namespace std;

class Node : public ml::RectangleButton{
private:
    sf::Vector2i coords;
    vector<vector<sf::Vector2i>> posCombinations;


    bool thisIsABomb = false;
    bool isFlagged = false;
    int numOfBombCount;

public:
    Node() :coords(sf::Vector2i(0, 0)) , numOfBombCount(0){};

    Node(int x, int y, int bombCount, bool bomb) : coords(sf::Vector2i(x, y)),
                                                       numOfBombCount(bombCount),
                                                       thisIsABomb(bomb){};

    void generateCombinations();
    void addCombination(const vector<sf::Vector2i>& combo);

    void setType(bool isBomb, int numOfBombs){ thisIsABomb = isBomb; numOfBombCount = numOfBombs;}
    void setCoords(int x, int y){ coords = sf::Vector2i(x, y);}
    void setFlagged(bool flag){isFlagged = flag;}

    vector<vector<sf::Vector2i>>  getCombinations(){return posCombinations;}
    sf::Vector2i getCoords(){return coords;}
    bool getType(){return thisIsABomb;}
    int getBombCount(){return numOfBombCount;}
    bool getFlagged() const {return isFlagged;}



    class Iterator {
    private:
        const Node& node;
        int index;

    public:
        Iterator(const Node& n, int i) : node(n), index(i) {}

        const vector<sf::Vector2i>& operator*() const { return node.posCombinations[index]; }
        Iterator& operator++() { ++index; return *this; }
    };

    Iterator begin() const { return Iterator(*this, 0); }
    Iterator end() const { return Iterator(*this, posCombinations.size()); }

};


#endif //MALENATEST_NODE_H
