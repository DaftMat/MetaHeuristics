#include <iostream>
#include <array>
#include <fstream>
#include "UBQP.hpp"


int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "Usage: ./ubqp <filepath>" << std::endl;
        return 1;
    }

    std::ifstream file(argv[1]);
    int n, p, c;
    file >> n >> p;
    std::vector<std::vector<int>> qv;
    for (int i = 0 ; i < n ; ++i) {
        qv.emplace_back(std::vector<int>());
        for (int j = 0 ; j < n ; ++j) {
            file >> c;
            qv[i].push_back(c);
            std::cout << qv[i][j] << " ";
        }
        std::cout << std::endl;
    }

    UBQP min(qv, n, p);

    std::vector<int> vec = min.steepest_hill_climbing(10, 10);
    std::cout << "{ ";
    for (int i = 0 ; i < n ; ++i) {
        std::cout << vec[i];
        if (i < n-1) std::cout << ", ";
    }
    std::cout << "}" <<std::endl;

    return 0;
}