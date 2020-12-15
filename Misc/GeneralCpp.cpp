#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <fstream>
#include <string>

bool sortReverse(int a, int b)
{
    return b < a;
}

int main() {

    // Sorting an array
    int randomArray[8] = {5, 9, 1, 5, -10, 3, 1, 6};
    std::sort(randomArray, &randomArray[7]);
    for (auto v : randomArray) {
            std::cout << v << ", ";
    }
    std::cout << std::endl;

    // Sorting a vector (+ custom sort comparison function)
    std::vector<int> vec;
    for (int i = 0; i < 8; i++) {
        vec.push_back(randomArray[i]);
    }
    std::sort(vec.begin(), vec.end(), sortReverse);
    for (auto v : vec) {
            std::cout << v << ", ";
    }
    std::cout << std::endl;

    // Vector usage
    vec.pop_back(); // Only removes last element (DOES NOT RETURN IT)
    vec.back(); // To get last element

    // Searching a vector
    std::find(vec.begin(), vec.end(), 5) != vec.end(); // Test if found

    // Set contains a find function
    std::set<int> s;
    s.find(5) != s.end(); // Test if found

    // File I/O
    std::ofstream file("test.txt");
    if (file.is_open()) {
        file << "Line of text";
        file.close();
    }

    std::string line;
    std::ifstream ifile("input.txt");
    if (ifile.is_open()) {
        while (getline(ifile, line)) {

        }
        ifile.close();
    }

    // C++ STL
    // STL Map uses Binary Search Tree O(logn) in comparison to hash table
    // 

}