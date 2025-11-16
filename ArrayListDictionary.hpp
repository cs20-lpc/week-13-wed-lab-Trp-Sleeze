#ifndef ARRAY_LIST_DICTIONARY_HPP
#define ARRAY_LIST_DICTIONARY_HPP

#include "Dictionary.hpp"
#include "ArrayList.hpp"
#include <iomanip>

template <typename Key, typename Val>
class ArrayListDictionary : public Dictionary<Key, Val> {
private:
    struct Record {
        Key k;
        Val v;

        Record() : k(Key()), v(Val()) {}
        Record(Key x, Val y) : k(x), v(y) {}

        bool operator<(Record& rightObj) const { return this->k < rightObj.k; }
        bool operator<=(Record& rightObj) const { return this->k <= rightObj.k; }
        bool operator>(Record& rightObj) const { return this->k > rightObj.k; }
        bool operator>=(Record& rightObj) const { return this->k >= rightObj.k; }
        bool operator==(Record& rightObj) const { return this->k == rightObj.k; }
        bool operator!=(Record& rightObj) const { return this->k != rightObj.k; }
    };

    ArrayList<Record>* list;

    void copy(const ArrayListDictionary<Key, Val>&);

public:
    ArrayListDictionary(int = 100);
    ArrayListDictionary(const ArrayListDictionary<Key, Val>&);
    ArrayListDictionary<Key, Val>& operator=(const ArrayListDictionary<Key, Val>&);
    virtual ~ArrayListDictionary();
    virtual void clear() override;
    virtual Val find(const Key&) const override;
    virtual unsigned getNumComps() const;
    virtual unsigned getNumSwaps() const;
    virtual void insert(const Key&, const Val&) override;
    virtual void remove(const Key&) override;
    virtual int size() const override;
    virtual void sort(int);

    template <typename T, typename U>
    friend ostream& operator<<(ostream&, const ArrayListDictionary<T, U>&);
};

#include "ArrayListDictionary.tpp"
#endif
