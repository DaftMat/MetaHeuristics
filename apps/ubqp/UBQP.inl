#include <random>

std::vector<int> UBQP::generate() const {
    std::vector<int> ret;
    std::random_device rd;
    for (int i = 0 ; i < m_N ; ++i) {
        ret.push_back(rd() % 2);
    }
    return ret;
}

std::vector<int> UBQP::greatest_neighbor(const std::vector<int> &s) const {
    std::vector<int> cn, bn = s;
    double cr, br = this->f(s);
    for (int i = 0 ; i < m_N ; ++i) {
        cn = s;
        cn[i] = std::abs(s[i]-1);
        cr = this->f(cn);
        if (cr < br){
            br = cr;
            bn = cn;
        }
    }
    return bn;
}