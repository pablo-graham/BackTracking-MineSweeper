//
// Created by Pablo Ruiz on 4/28/25.
//

#include "Node.h"

/* psuedocode:
 function solve(index)
    if index == total number of nodes
        if isSolved()  // Check if all nodes have correct bomb count
            return true  // Board is solved
        else
            return false  // Continue searching



    for each combination in node.combinations
        if canPlaceBomb(combination)  // Check if bombs can be placed without breaking the board's rules
            placeBomb(combination, node)  // Place bombs for this combination

            if solve(index + 1)  // Recursively solve the next node
                return true  // If solving the next node works, return true

            node.reset()  // Backtrack: Remove placed bombs and reset node

    return false  // No valid bomb placement was found for this node
 */

void Node::generateCombinations() {
    //generate all 8 possible adjacent positions (for now)
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) continue; // Skip the center position
            sf::Vector2f newPos(coords.x + dx, coords.y + dy);
            //posCombinations.push_back(newPos);
        }
    }
}

void Node::addCombination(const vector<sf::Vector2i>& combo){
    posCombinations.push_back(combo);
}