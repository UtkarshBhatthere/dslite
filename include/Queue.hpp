/**
 * Copyright 2019 Utkarsh Bhatt
 * Author : Utkarsh Bhatt
 * Date   : 06/10/2019  (6th October 2019)
 * Struct : Singular Queue
 * Using  : Dynamic Array
 * Type   : Generic (Templated)
 */

#ifndef INCLUDE_QUEUE_HPP_
#define INCLUDE_QUEUE_HPP_

#include <sstream>
#include <iostream>
#include <string>

template <typename T>
class queue {
 protected:
    T* queue_root;
    T* front;
    T* back;
    int size;
    int capacity;

 public:
    explicit queue(int required_capacity) {
        this -> capacity = required_capacity;
        this -> queue_root = new T[this->capacity];
        this -> size = 0;
        this -> front   = this -> queue_root;
        this -> back    = this -> queue_root;
    }

    ~queue(void) {
        delete[] this -> queue_root;
    }

    void reset(void) {
        this -> front = this -> queue_root;
        this -> back  = this -> queue_root;
        this -> size  = 0;
    }

    bool enqueue(T object) {
        if (this -> size == this -> capacity) {
            return false;
        }

        *this -> back++ = object;
        this -> size++;

        return true;
    }

    T dequeue(void) {
        if (this -> size == 0) {
            return (T)NULL;
        }

        T ret = *this -> front++;

        this -> size--;

        if (this->size == 0)
            this -> reset();

        return ret;
    }

    T peek(void) {
        if (this -> size == 0) {
            return (T)NULL;
        }

        T ret = *this -> front;
        return ret;
    }

    int queue_size(void) {
        return this -> size;
    }

    std::string flatten(void) {
        T* object_ptr = this -> front;
        std::stringstream queue_str;

        queue_str << "Queue Size : " << this ->size << std::endl;
        queue_str << "Queue Content : " << std::endl;
        if (this -> size == 0) {
            queue_str << "NULL" << std::endl;
            return queue_str.str();
        }

        try {
            queue_str << "--> " << *object_ptr++ << " <-- Front" << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << e.what() << '\n';
            return e.what();
        }

        // Since this is the secondth element to be printed.
        for (int i = 2; i < this-> size; i++) {
            queue_str << "--> " << *object_ptr++ << std::endl;
        }

        if (this -> size > 1)
            queue_str << "--> " << *object_ptr << " <-- Back" << std::endl;

        return queue_str.str();
    }
};
#endif  // INCLUDE_QUEUE_HPP_
