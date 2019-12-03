#include <vector>
#include <random>

template <class T>
T Searchable<T>::steepest_hill_climbing(int max_shift, int max_tries) const {
    int num_tries { 0 };
    auto s = _steepest_hill_climbing(max_shift);
    while (num_tries++ < max_tries) {
        auto sp = _steepest_hill_climbing(max_shift);
        if (f(sp) < f(s))
            s = sp;
    }
    return s;
}

template<class T>
T Searchable<T>::_steepest_hill_climbing(int max_shift) const {
    std::vector<T> s;
    s.push_back(generate());
    int num_shift { 0 };
    bool stop { false };
    while (num_shift++ < max_shift && !stop) {
        T sp = greatest_neighbor(s[s.size() - 1]);
        double fsp = f(sp);
        double fs = f(s[0]);
        if (fsp < fs)
            s.clear();
        if (fsp <= fs)
            s.push_back(sp);
        if (fsp > fs)
            stop = true;
    }
    std::random_device rd;
    int i = rd() % s.size();
    return s[i];
}
