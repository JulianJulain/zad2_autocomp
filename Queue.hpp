#include <iostream>
#include <list>
#include <string>
#include <stdexcept>

using namespace std;

template <typename T>

class Queue {
private:
    list<T> kolejka;  
public:
    void enqueue(const T& czesc) {
        kolejka.push_back(czesc);
    }
    T dequeue() {
        if (kolejka.empty()) {
            throw out_of_range("Kolejka pusta");
        }
        T element = kolejka.front();
        kolejka.pop_front();
        return element;
    }

    bool isEmpty() const {
        return kolejka.empty();
    }
    size_t size() const {
        return kolejka.size();
    }
    T front() const {
        if (kolejka.empty()) {
            throw out_of_range("Kolejka jest pusta");
        }
        return kolejka.front();
    }
};