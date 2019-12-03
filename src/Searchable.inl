#include <vector>
#include <random>

template <class T>
T Searchable<T>::steepest_hill_climbing(T _s, int max_shift, int max_tries, int p) const {
    int num_tries { 0 };
    int num_shift { 0 };
    auto s = _steepest_hill_climbing(_s, max_shift, num_shift, p);
    while (num_tries++ < max_tries) {
        auto sp = _steepest_hill_climbing(s, max_shift, num_shift, p);
        if (f(sp) < f(s))
            s = sp;
    }
    std::cout << "Number of shifts : " << num_shift << std::endl;
    return s;
}

template<class T>
T Searchable<T>::_steepest_hill_climbing(T _s, int max_shift, int &n_shift, int p) const {
    std::vector<T> s;
    s.push_back(_s);
    int num_shift { 0 };
    bool stop { false };
    while (num_shift++ < max_shift && !stop) {
        T sp = greatest_neighbor(s[s.size() - 1]);
        double fsp = f(sp);
        double fs = f(s[0]);
        int sum { 0 };
        for (int i = 0 ; i < sp.size() ; sum += sp[i++]);
        if (fsp < fs && sum >= p)
            s.clear();
        if (fsp <= fs && sum >= p)
            s.push_back(sp);
        if (fsp > fs)
            stop = true;
    }
    std::random_device rd;
    int i = rd() % s.size();
    n_shift += num_shift;
    return s[i];
}

template<class T>
T Searchable<T>::taboo(T &s, int max_shift, int max_size) const {
    std::vector<T> t;
    int num_shift { 0 };
    auto msol = s;
    bool stop = false;
    while (num_shift++ < max_shift && !stop) {
        auto neighs = neighbors_not_taboo(s, t);
        T sp;
        if (!neighs.empty()) {
            sp = greatest_neighbor_not_taboo(s, t);
        } else {
            stop = true;
        }
        if (t.size() == max_size+1) {
            for (int i = 0; i < t.size() - 1; ++i) {
                t[i] = t[i + 1];
            }
            t[t.size()-1] = s;
        } else {
            t.push_back(s);
        }
        if (f(sp) < f(msol))
            msol = sp;
        s = sp;
    }
    std::cout << "Number of shifts : " << num_shift << std::endl;
    s = t[0];
    return msol;
}
