// Copyright 2021 MalininDmitry
#ifndef INCLUDE_MYSTACK_H_
#define INCLUDE_MYSTACK_H_

template <class T>
class MyStack{
 private:
    int size;
    int current;
    T * mass;

 public:
    explicit MyStack(int s = 10) {
        size = s;
        mass = new T[size];
    }

    MyStack(const MyStack &other) {
        this->size = other->size;
        this->mass = new T[other->size];
        for (int i = 0; i < other->size; i++) {
            this->mass[i] = other->mass[i];
        }
    }

    ~MyStack() {
        size = 0;
        current = 0;
        delete[] mass;
    }

    T get() const {
        if (!isEmpty()) {
            return mass[current-1];
        } else {
            throw "Can not get a stack item because the stack is empty";
        }
    }

    T pop() {
        if (!isEmpty()) {
            return mass[--current];
        } else {
            throw "Can not get a stack item because the stack is empty";
        }
    }

    void push(T a) {
        if (!isFull()) {
            mass[current] = a;
            current++;
        } else {
            throw "It is impossible to add item.Stack is overflowed";
        }
    }

    [[nodiscard]] bool isFull() const {
        if (current == size)
            return true;
        return false;
    }

    [[nodiscard]] bool isEmpty() const {
        if (current == 0)
            return true;
        return false;
    }
};

#endif  // INCLUDE_MYSTACK_H_
