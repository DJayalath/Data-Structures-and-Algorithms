#include <iostream>
#include <cstring>

// Some backtracking improvements
// - Most constrained variable (choose var with least legal values)
// - Most constraining variable (var with most constraints on remaing vars)
// - Forward checking (track remaining legal values for each variable, terminate if any zero)
// - Arc consistency (check propagated consistency between arcs)

// Alternatively, for dense solution spaces use iterative min-conflicts algorithm
// - Pick random conflicted variable and pick value that minimises conflicts (and repeat)

// Backtracking to solve the N-Queens problem

// Chess board size
#define N 8
#define UNASS -1

int findUnassigned(int* assignment);

// Test CONSISTENCY of assignment (i.e. are all queens in allowed positions?)
bool isConsistent(int* assignment) {
    // We are already guaranteed no queens in same column due to representation

    // Test if all queens in different rows
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (assignment[i] != UNASS && assignment[j] != UNASS) {
                if (assignment[i] == assignment[j] && i != j) return false;
            }
        }
    }


    // Test if all queen diagonals satisfied
    for (int i = 0; i < N; i++) {
        if (assignment[i] != UNASS) {
            for (int j = 0; j < N; j++) {

                if (assignment[j] != UNASS) {

                    int row = assignment[i];
                    int col = i;

                    while (row + 1 < N && col + 1 < N) {
                        if (j == col + 1 && assignment[j] == row + 1) return false;
                        row++; col++;
                    }

                    row = assignment[i];
                    col = i;

                    while (row + 1 < N && col - 1 >= 0) {
                        if (j == col - 1 && assignment[j] == row + 1) return false;
                        row++; col--;
                    }

                    row = assignment[i];
                    col = i;

                    while (row - 1 >= 0 && col + 1 < N) {
                        if (j == col + 1 && assignment[j] == row - 1) return false;
                        row--; col++;
                    }

                    row = assignment[i];
                    col = i;

                    while (row - 1 >= 0 && col - 1 >= 0) {
                        if (j == col - 1 && assignment[j] == row - 1) return false;
                        row--; col--;
                    }

                }

            }
        }
    }

    return true;
}

// Test COMPLETENESS of assignment (i.e. are queens assigned to all columns?)
bool isComplete(int* assignment) {
    return findUnassigned(assignment) == -1;
}

// Find a column without an assignment
// This is deterministic, if we introduce randomness we could get different solutions each time!
int findUnassigned(int* assignment) {
    for (int i = 0; i < N; i++) {
        if (assignment[i] == UNASS) return i;
    }
    return -1;
}

bool recursiveBacktracking(int* assignment) {

    // If complete assignment reaches this stage, we are done.
    if (isComplete(assignment)) return true;

    // Select unassigned variable
    int unassigned = findUnassigned(assignment);
    
    // Loop over possible assignments
    for (int i = 0; i < N; i++) {

        // Try assigning value
        assignment[unassigned] = i;
        if (isConsistent(assignment)) {
            // If successful backtracking with this assignment, return true
            if (recursiveBacktracking(assignment)) {
                return true;
            }

        }

        // Remove assignment if consistency fails or recursive backtracking fails to find solution
        assignment[unassigned] = UNASS;
    }

    // Possibilities exhausted
    return false;

}

void printAssignment(int* assignment) {
    std::cout << "(";
    for (int i = 0; i < N; i++) {
        std::cout << assignment[i] << ",";
    }
    std::cout<< ")" << std::endl;
}

int main() {

    // Represent assignment as an N-length vector indicating position of queen in that column
    int* assignment = new int[N];
    memset(assignment, UNASS, sizeof(int) * N);

    if (recursiveBacktracking(assignment)) {
        printAssignment(assignment);
    } else {
        std::cout << "FAILED" << std::endl;
    }

    return 0;
}