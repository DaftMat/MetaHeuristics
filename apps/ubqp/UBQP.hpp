//
// Created by daftmat on 02/12/19.
//

#ifndef METAHEURISTICS_UBQP_HPP
#define METAHEURISTICS_UBQP_HPP

#include <Searchable.hpp>

class UBQP : public Searchable<std::vector<int>> {
public:
    explicit UBQP(const std::vector<std::vector<int>> &q, int n, int p = 0)
    : Searchable<std::vector<int>>([p, q, n](const std::vector<int> &x) {
        double ret = 0;
        for (int i = 0 ; i < n ; ++i)
            for (int j = 0 ; j < n ; ++j)
                ret += q[i][j] * x[i] * x[j];
        return ret;
    }), m_N { n } {}

    std::vector<int> generate() const override;
    std::vector<int> greatest_neighbor(const std::vector<int> &s) const override;
    std::vector<int> greatest_neighbor_not_taboo(const std::vector<int> &s, const std::vector<std::vector<int>> &t) const override;
    std::vector<std::vector<int>> neighbors(const std::vector<int> &s) const override;
    std::vector<std::vector<int>> neighbors_not_taboo(const std::vector<int> &s, const std::vector<std::vector<int>> &t) const override;

private:
    int m_N;
};

#include "UBQP.inl"

#endif //METAHEURISTICS_UBQP_HPP
