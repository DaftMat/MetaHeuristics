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

    std::vector<int> x0 {1, 1, 1, 1, 0, 1};
    std::cout << "x0 { 1, 1, 1, 1, 0, 1 } = " << min.apply_f(x0) << std::endl;
    auto x1 = min.greatest_neighbor(x0);
    std::cout << "x1 { ";
    for (int i = 0 ; i < n ; ++i) {
        std::cout << x1[i];
        if (i < n-1) std::cout << ", ";
    }
    std::cout << "} = " << min.apply_f(x1) <<std::endl;

    int ns { 0 };
    auto x2 = min._steepest_hill_climbing(x0, 10, ns);
    std::cout << "Nb shifts : " << ns << std::endl;
    std::cout << "x2 { ";
    for (int i = 0 ; i < n ; ++i) {
        std::cout << x2[i];
        if (i < n-1) std::cout << ", ";
    }
    std::cout << "} = " << min.apply_f(x2) <<std::endl;

    auto x0p = min.generate();
    std::cout << "x0' { ";
    for (int i = 0 ; i < n ; ++i) {
        std::cout << x0p[i];
        if (i < n-1) std::cout << ", ";
    }
    std::cout << "} = " << min.apply_f(x0p) <<std::endl;

    auto x3 = min.steepest_hill_climbing(x0p, 100, 100);
    std::cout << "x3 { ";
    for (int i = 0 ; i < n ; ++i) {
        std::cout << x3[i];
        if (i < n-1) std::cout << ", ";
    }
    std::cout << "} = " << min.apply_f(x3) <<std::endl;

    auto x0temp = x0;
    auto x4 = min.taboo(x0temp, 100, 10);
    std::cout << "x4 { ";
    for (int i = 0 ; i < n ; ++i) {
        std::cout << x4[i];
        if (i < n-1) std::cout << ", ";
    }
    std::cout << "} = " << min.apply_f(x4) <<std::endl;
    std::cout << "oldest taboo { ";
    for (int i = 0 ; i < n ; ++i) {
        std::cout << x0temp[i];
        if (i < n-1) std::cout << ", ";
    }
    std::cout << "} = " << min.apply_f(x0temp) <<std::endl;


    x0temp = { 1, 0, 0, 1, 1, 0 };
    auto x5 = min.taboo(x0temp, 100, 10);
    std::cout << "x5 { ";
    for (int i = 0 ; i < n ; ++i) {
        std::cout << x5[i];
        if (i < n-1) std::cout << ", ";
    }
    std::cout << "} = " << min.apply_f(x5) <<std::endl;
    std::cout << "oldest taboo { ";
    for (int i = 0 ; i < n ; ++i) {
        std::cout << x0temp[i];
        if (i < n-1) std::cout << ", ";
    }
    std::cout << "} = " << min.apply_f(x0temp) <<std::endl;

    int np { 0 };
    auto x6 = min._steepest_hill_climbing(x0, 10, np, p);
    std::cout << "Nb shifts : " << ns << std::endl;
    std::cout << "x6 { ";
    for (int i = 0 ; i < n ; ++i) {
        std::cout << x6[i];
        if (i < n-1) std::cout << ", ";
    }
    std::cout << "} = " << min.apply_f(x6) <<std::endl;

    return 0;
}