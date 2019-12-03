//
// Created by daftmat on 02/12/19.
//

#ifndef METAHEURISTICS_SEARCHABLE_HPP
#define METAHEURISTICS_SEARCHABLE_HPP


#include <functional>

template <class T>
class Searchable {
public:
    explicit Searchable(std::function<double(T)> fs) : f { fs } {}

    virtual T generate() const = 0;
    virtual T greatest_neighbor(const T&) const = 0;
    T steepest_hill_climbing(int max_shift, int max_tries) const;
    //T taboo() const;

private:
    T _steepest_hill_climbing(int max_shift) const;

protected:
    std::function<double(T)> f;
};

#include <Searchable.inl>

#endif //METAHEURISTICS_SEARCHABLE_HPP
