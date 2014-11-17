#pragma once

#include <stdexcept>

template <typename T>
T& min(T& a, T& b)
{
    return (a < b) ? a : b;
}

template <typename T>
class vector
{
    T* arr;
    size_t n;

public:
    vector()
    {
        arr = nullptr;
        n = 0;
    }

    explicit vector(size_t n)
    {
        this->n = n;
        arr = new T[n];
    }

    vector(size_t n, const T& val)
    {
        this->n = n;
        arr = new T[n];
        for (size_t i = 0; i < n; i++)
            arr[i] = val;
    }

    vector(const vector<T>& other) :
        n(other.n), arr(new T[n])
    {
        for (size_t i = 0; i < n; i++)
            arr[i] = other.arr[i];
    }

    vector<T>& operator=(const vector<T>& other)
    {
        if (this == &other)
            return *this;

        n = other.n;
        delete[] arr;
        arr = new T[n];
        for (size_t i = 0; i < n; i++)
            arr[i] = other.arr[i];

        return *this;
    }

    size_t size() const { return n; }
    bool empty() const { return n == 0; }

    T& operator[](size_t i)
    {
        return arr[i];
    }

    const T& operator[](size_t i) const
    {
        return arr[i];
    }

    void resize(size_t i)
    {
        T* temp = new T[i];

        for (size_t j = 0; j < min(i, n); j++)
            temp[j] = arr[j];

        delete[] arr;
        arr = temp;
        n = i;
    }

    ~vector()
    {
        delete[] arr;
    }
};

template <typename T>
class matrix
{
    vector<vector<T>> vec;

public:
    matrix(size_t m, size_t n) :
        vec(m, vector<T>(n))
    { }

    size_t sizem() const { return vec.size(); }
    size_t sizen() const { return vec.empty() ? 0 : vec[0].size(); }

    void resizem(size_t m) { vec.resize(m); }
    void resizen(size_t n)
    {
        for (size_t i = 0; i < vec.size(); i++)
            vec[i].resize(n);
    }

    vector<T>& operator[](size_t i)
    {
        return vec[i];
    }

    const vector<T>& operator[](size_t i) const
    {
        return vec[i];
    }

    T& at(size_t i, size_t j)
    {
        if (i >= sizem() || j >= sizen())
            throw std::invalid_argument("Out of range");

        return vec[i][j];
    }

    const T& at(size_t i, size_t j) const
    {
        if (i >= sizem() || j >= sizen())
            throw std::invalid_argument("Out of range");

        return vec[i][j];
    }
};