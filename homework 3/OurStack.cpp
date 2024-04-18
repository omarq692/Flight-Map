//
// Created by Omar Q on 2/21/24.
//

#ifndef CSC326_LAB_3_OURSTACK_H
#define CSC326_LAB_3_OURSTACK_H

#include "StackInterface.h"
#include <stack>
#include <string>

template<class T>
class OurStack : public StackInterface<T> {
private:
    std::stack<T> items;
public:
    bool isEmpty() const;

    bool push(const T& enEntry);

    bool pop();

    T peek() const;

    ~OurStack();
};

template<class T>
bool OurStack<T>::isEmpty() const {
    return items.empty();
}

template<class T>
bool OurStack<T>::push(const T& enEntry) {

    items.push(enEntry);
    return true;
}

template<class T>
bool OurStack<T>::pop() {
    if (items.empty()) {
        return false;
    }
    items.pop();
    return true;
}

template<class T>
T OurStack<T>::peek() const {
    return items.top();
}

template<class T>
OurStack<T>::~OurStack<T>() {
    //std::cout << "destructor before clear size=" << items.size() << std::endl;
    for (; !items.empty(); items.pop());
    //std::cout << "destructor after clear size=" << items.size() << std::endl;
}

#endif //CSC326_LAB_3_OURSTACK_H