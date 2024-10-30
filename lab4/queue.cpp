#include <iostream>

class Deque {
private:
    int *elements;
    int capacity;
    int frontIndex;
    int backIndex;
    int size;

    void resize() {
        int newCapacity = capacity * 2;
        int *newElements = new int[newCapacity];
        for (int i = 0; i < size; ++i) {
            newElements[i] = elements[(frontIndex + i) % capacity];
        }
        frontIndex = 0;
        backIndex = size - 1;
        capacity = newCapacity;
        delete[] elements;
        elements = newElements;
    }

public:
    Deque() : capacity(10), frontIndex(0), backIndex(-1), size(0) {
        elements = new int[capacity];
    }
    ~Deque(){
        delete[] elements;
    }
    void push_front(int value) {
        if(capacity==size) {
            resize();
        }
        frontIndex = (frontIndex - 1 + capacity) % capacity;
        elements[frontIndex];
        size++;
    }
    void pop_front(){
        
    }


};
