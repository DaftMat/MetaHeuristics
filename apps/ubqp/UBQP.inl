#include <random>
#include <deque>

std::vector<int> UBQP::generate() const {
    std::vector<int> ret;
    std::random_device rd;
    for (int i = 0 ; i < m_N ; ++i) {
        ret.push_back(rd() % 2);
    }
    return ret;
}

std::vector<int> UBQP::greatest_neighbor(const std::vector<int> &s) const {
    return neighbors(s)[0];
}

std::vector<int> UBQP::greatest_neighbor_not_taboo(const std::vector<int> &s, const std::vector<std::vector<int>> &t) const {
    return neighbors_not_taboo(s, t)[0];

}

std::vector<std::vector<int>> UBQP::neighbors(const std::vector<int> &s) const {
    std::deque<std::vector<int>> res;
    double cr, br = this->f(s);
    for (int i = 0 ; i < m_N ; ++i) {
        auto cn = s;
        cn[i] = std::abs(s[i]-1);
        cr = this->f(cn);
        if (cr < br){
            res.push_front(cn);
        }else{
            res.push_back(cn);
        }
    }
    std::vector<std::vector<int>> neighs;
    for (int i = 0 ; i < m_N ; ++i)
        neighs.push_back(res[i]);
    return neighs;
}

std::vector<std::vector<int>> UBQP::neighbors_not_taboo(const std::vector<int> &s, const std::vector<std::vector<int>> &t) const {
    auto neighs = neighbors(s);
    std::vector<std::vector<int>> res;
    int k = 0;
    bool isIn { false };
    while (k++ < neighs.size()) {
        for (int i = 0; i < t.size() ; ++i) {
            if (neighs[k] == t[i])
                isIn = true;
        }
        if (!isIn)
            res.push_back(neighs[k]);
        isIn = false;
    }
    return res;
}
