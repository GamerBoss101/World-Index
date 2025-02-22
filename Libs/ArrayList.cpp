#pragma once

#include <iostream>

template <typename T> class ArrayList {
    private:
        T* data;
        int size;
        int capacity;

        void resize(int newCapacity);

    public:

        ArrayList();
        ArrayList(int initialCapacity);
        ~ArrayList();
        int getSize();
        int getCapacity();
        bool isEmpty();
        void add(int index, T element);
        void addFirst(T element);
        void addLast(T element);
        T get(int index);
        T getFirst();
        T getLast();
        void set(int index, T element);
        bool contains(T element);
        int find(T element);
        T remove(int index);
};

template <typename T> void ArrayList<T>::resize(int newCapacity) {
    T* newData = new T[newCapacity];
    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    data = newData;
    capacity = newCapacity;
}

template <typename T> ArrayList<T>::ArrayList() {
    data = new T[10];
    size = 0;
    capacity = 10;
}

template <typename T> ArrayList<T>::ArrayList(int initialCapacity) {
    data = new T[initialCapacity];
    size = 0;
    capacity = initialCapacity;
}

template <typename T> ArrayList<T>::~ArrayList() {
    delete[] data;
}

template <typename T> int ArrayList<T>::getSize() {
    return size;
}

template <typename T> int ArrayList<T>::getCapacity() {
    return capacity;
}

template <typename T> bool ArrayList<T>::isEmpty() {
    return size == 0;
}

template <typename T> void ArrayList<T>::add(int index, T element) {
    if (index < 0 || index > size) {
        throw std::invalid_argument("Add failed. Index is illegal.");
    }

    if (size == capacity) {
        resize(2 * capacity);
    }

    for (int i = size - 1; i >= index; i--) {
        data[i + 1] = data[i];
    }

    data[index] = element;
    size++;
}

template <typename T> void ArrayList<T>::addFirst(T element) {
    add(0, element);
}

template <typename T> void ArrayList<T>::addLast(T element) {
    add(size, element);
}

template <typename T> T ArrayList<T>::get(int index) {
    if (index < 0 || index >= size) {
        throw std::invalid_argument("Get failed. Index is illegal.");
    }

    return data[index];
}

template <typename T> T ArrayList<T>::getFirst() {
    return get(0);
}

template <typename T> T ArrayList<T>::getLast() {
    return get(size - 1);
}

template <typename T> void ArrayList<T>::set(int index, T element) {
    if (index < 0 || index >= size) {
        throw std::invalid_argument("Set failed. Index is illegal.");
    }

    data[index] = element;
}

template <typename T> bool ArrayList<T>::contains(T element) {
    for (int i = 0; i < size; i++) {
        if (data[i] == element) {
            return true;
        }
    }

    return false;
}

template <typename T> int ArrayList<T>::find(T element) {
    for (int i = 0; i < size; i++) {
        if (data[i] == element) {
            return i;
        }
    }

    return -1;
}

template <typename T> T ArrayList<T>::remove(int index) {
    if (index < 0 || index >= size) {
        throw std::invalid_argument("Remove failed. Index is illegal.");
    }

    T ret = data[index];

    for (int i = index + 1; i < size; i++) {
        data[i - 1] = data[i];
    }

    size--;

    if (size == capacity / 4 && capacity / 2 != 0) {
        resize(capacity / 2);
    }

    return ret;
}