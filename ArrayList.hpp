#ifndef ARRAY_LIST_HPP
#define ARRAY_LIST_HPP

#include "List.hpp"
#include <iostream>
using namespace std;

template <typename T>
class ArrayList : public List<T> {
private:
    T* buffer;
    int maxSize;

    void copy(const ArrayList<T>&);
    void swap(int, int);

    void bubbleSort();
    void selectionSort();
    void insertionSort();

    static unsigned numComps, numSwaps;

public:
    ArrayList(int = 100);
    ArrayList(const ArrayList<T>&);
    ArrayList<T>& operator=(const ArrayList<T>&);
    virtual ~ArrayList();

    virtual void append(const T&) override;
    virtual void clear() override;
    virtual T getElement(int) const override;
    virtual int getLength() const override;

    int getMaxSize() const;
    static unsigned getNumComps();
    static unsigned getNumSwaps();

    virtual void insert(int, const T&) override;
    virtual bool isEmpty() const override;
    bool isFull() const;
    virtual void remove(int) override;
    virtual void replace(int, const T&) override;

    virtual void sort(int);

    template <typename U>
    friend ostream& operator<<(ostream&, const ArrayList<U>&);
};

#include "ArrayList.tpp"
#endif
