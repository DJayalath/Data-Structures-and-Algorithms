#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>

// Difference between hill climbing and BEST first search
// Best-first expands most promising node according to rule (possibly heuristic) (graph search)
// Hill-climbing expands to find all neighbours and picks best (optimization)

// This example attempts to find a number by flipping bits from starting 32-bit input

void generateNeighbours(int* neighbours, int current) {
    for (int i = 0; i < 32; i++) {
        neighbours[i] = current ^ (1 << i); // Flip bit i
    }
}

// Count number of bits not correct
int score(int v, int t) {
    int c = v ^ t; // Sets all mismatching bits to 1
    int count = 0;
    while (c != 0) {
        c &= c - 1; // Clears rightmost 1
        count++;
    }
    return count;
}

int highestNeighbour(int* neighbours, int target) {

    int max = INT_MAX;
    int best = -1;
    for (int i = 0; i < 32; i++) {
        int sc = score(neighbours[i], target);
        if (sc < max) {
            max = sc;
            best = neighbours[i];
        }
    }

    return best;
}

void hillClimbing(int start, int target) {

    int current = start;
    int* neighbours = new int[32];

    while (current != target) {
        // Usually we test the best neighbour against the current
        generateNeighbours(neighbours, current);
        int neighbour = highestNeighbour(neighbours, target);
        if (score(neighbour, target) < score(current, target)) {
            current = neighbour;
            std::cout << current << std::endl;
        }
    }

    std::cout << "Target found!" << std::endl;

}

int main() {

    hillClimbing(5, 505);
    hillClimbing(241432, 655);

    return 0;
}