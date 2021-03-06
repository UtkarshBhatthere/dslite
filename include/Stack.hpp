/**
 * Copyright 2019 Utkarsh Bhatt
 * Author : Utkarsh Bhatt
 * Date   : 05/10/2019  (5th October 2019)
 * Struct : Stack
 * Using  : Dynamic Array
 * Type   : Generic (Templated)
 */

#ifndef INCLUDE_STACK_HPP_
#define INCLUDE_STACK_HPP_

#include <sstream>
#include <iostream>
#include <string>
template <typename T>
class stack {
 protected:
    T*  stack_root;
    T*  top_ptr;
    int size;
    int capacity;

 public:
    explicit stack(int required_capacity) {
        this -> size       = 0;
        this -> capacity   = 0;
        this -> capacity   = required_capacity;
        this -> stack_root = new T[this->capacity];
        this -> top_ptr    = this -> stack_root - 1;
    }

    ~stack(void) {
        delete[] this->stack_root;
    }

    bool push(T object) {
        if (this->size == this->capacity) {
            return false;
        }

        this -> top_ptr++;
        *(this -> top_ptr) = object;

        this -> size++;
        return true;
    }

    int print_size(void) {
        return this->size;
    }

    T pop(void) {
        if (this -> size == 0) {
            return (T)NULL;
        }
        T ret = *this -> top_ptr--;
        this -> size--;
        return ret;
    }

    T top(void) {
        if (this -> size == 0) {
            return (T)NULL;
        }
        T ret = *this -> top_ptr;
        return ret;
    }

    bool isEmpty(void) {
        return (this -> size == 0);
    }

    bool isFull(void) {
        return (this -> size == this -> capacity);
    }

    std::string flatten(void) {
        T* object_ptr = this->top_ptr;
        std::stringstream stack_str;
        stack_str << "Stack Size : "<< this -> size<< std::endl;
        stack_str << "Stack Content : "<< std::endl;
        try {
            stack_str << "--> " << *object_ptr-- << " <-- TOP" << std::endl;
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << '\n';
            return e.what();
        }

        while (object_ptr >= this->stack_root) {
            stack_str << "--> " <<  *object_ptr-- << std::endl;
        }
        return stack_str.str();
    }
};
#endif  // INCLUDE_STACK_HPP_
