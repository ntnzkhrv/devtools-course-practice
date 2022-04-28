  // Copyright 2022 Ustiuzhanin Nikita

#ifndef MODULES_USTIUZHANIN_N_HASHMAP_INCLUDE_HASHMAP_H_
#define MODULES_USTIUZHANIN_N_HASHMAP_INCLUDE_HASHMAP_H_

const int default_size = 101;

#include <exception>
#include <string>

#include <iostream>

template<class T, class K>
class Record {
 public:
    explicit Record(T mKey = T(), K mValue = K()) :
        key(mKey), value(mValue), isDeleted(false) {}
    Record(const Record<T, K>& rec) {
        key = rec.key;
        value = rec.value;
        isDeleted = false;
    }

    ~Record() {}

    void setKey(T newKey) {
        key = newKey;
    }

    T getKey() const {
        return key;
    }

    void setValue(K newValue) {
        value = newValue;
    }

    K getValue() const {
        return value;
    }

    bool isDel() {
        return isDeleted;
    }

    void setDel(bool b) {
        isDeleted = b;
    }

    bool operator==(const Record<T, K>& rec) {
        return key == rec.key;
    }

    bool operator<(const Record<T, K>& rec) {
        return key < rec.key;
    }

    bool operator>(const Record<T, K>& rec) {
        return key > rec.key;
    }

    Record<T, K>& operator=(const Record<T, K>& rec) {
        key = rec.key;
        value = rec.value;
        return *this;
    }

    void clear() {
        key = T();
        value = K();
    }

 private:
    T key;
    K value;
    bool isDeleted;
};

template<class T, class K>
class Hashmap {
 public:
    Hashmap() {
         maxSize = default_size;
         _size = 0;
         data = new Record<T, K>[maxSize];
    }

    explicit Hashmap(int size) {
        maxSize = size;
        _size = 0;
        data = new Record<T, K>[maxSize];
    }

    virtual ~Hashmap() {
        delete[] data;
    }

    size_t hash(T key) {
        return std::hash<T>{}(key) % maxSize;
    }

    int size() const {
        return _size;
    }

    bool isEmpty() const {
        return _size == 0;
    }

    bool isFull() {
        return _size == maxSize;
    }

    Hashmap& resize(int newSize) {
        if (newSize <= maxSize)
            throw std::string("Resize: new size less or equal current size");

        Hashmap<T, K> result(newSize);
        result._size = this->size();
        for (int i = 0; i < this->maxSize; i++) {
            result.data[i] = this->data[i];
        }

        *this = result;
        return *this;
    }

    void insert(const Record<T, K>& rec) {
        // если таблица заполнена > 75% -> resize(maxSize * 2)
        if (static_cast<double>(this->_size) / this->maxSize > 0.75)
            resize(this->maxSize * 2);

        size_t index = hash(rec.getKey());

        while (this->data[index].getKey() != T()) {
            if (this->data[index].getKey() == rec.getKey()) {
                throw std::string("Record with this key already exist");
            }
            index += prime;
        }

        this->data[index] = rec;
        this->data[index].setDel(false);
        this->_size++;
        return;
    }

    void insert(T key = T(), K value = K()) {
        Record<T, K> rec(key, value);
        insert(rec);
    }

    void erase(T key) {
        if (this->isEmpty())
            throw std::string("Erase from empty table");

        size_t index = hash(key);
        while (this->data[index].getKey() != key) {
            if (this->data[index].getKey() == T())
                throw std::string("Erase: Wrong key");
            index += prime;
        }

        this->data[index].clear();
        this->data[index].setDel(true);
        this->maxSize--;
    }

    K operator[](T key) {
        size_t index = hash(key);
        while (this->data[index].getKey() != key) {
            if (this->data[index].getKey() == T() &&
                !this->data[index].isDel())
                throw std::string("Access: Wrong key");

            index += prime;
            index %= this->maxSize;
        }

        return this->data[index].getValue();
    }

    Hashmap& operator=(const Hashmap& rv) {
        if (this == &rv) {
            return *this;
        }

        _size = rv._size;
        maxSize = rv.maxSize;

        delete[] data;
        data = new Record<T, K>[maxSize];

        for (int i = 0; i < maxSize; i++) {
            data[i] = rv.data[i];
        }

        return *this;
    }

 private:
    Record<T, K>* data;
    int _size;
    int maxSize;

    const int prime = 1;
};

#endif  // MODULES_USTIUZHANIN_N_HASHMAP_INCLUDE_HASHMAP_H_
