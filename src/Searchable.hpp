//
// Created by daftmat on 02/12/19.
//

#ifndef METAHEURISTICS_SEARCHABLE_HPP
#define METAHEURISTICS_SEARCHABLE_HPP


#include <functional>
#include <vector>

template <class T>
class Searchable {
public:
    explicit Searchable(std::function<double(T)> fs) : f { fs } {}

    virtual T generate() const = 0;
    virtual T greatest_neighbor(const T&) const = 0;
    virtual T greatest_neighbor_not_taboo(const T&, const std::vector<T>&) const = 0;
    virtual std::vector<T> neighbors(const T&) const = 0;
    virtual std::vector<T> neighbors_not_taboo(const T&, const std::vector<T>&) const = 0;
    double apply_f(const T &x) const { return f(x); }
    T steepest_hill_climbing(T s, int max_shift, int max_tries, int p = 0) const;
    T _steepest_hill_climbing(T _s, int max_shift, int &n_shift, int p = 0) const;
    T taboo(T &_s, int max_shift, int max_size) const;

private:

protected:
    std::function<double(T)> f;
};

#include <Searchable.inl>

#endif //METAHEURISTICS_SEARCHABLE_HPP
