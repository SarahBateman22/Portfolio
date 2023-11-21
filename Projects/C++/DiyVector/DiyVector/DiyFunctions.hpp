//
//  DiyFunctions.hpp
//  DiyVector
//
//  Created by Sarah Bateman on 9/12/23.
//

#ifndef DiyFunctions_hpp
#define DiyFunctions_hpp

#include <stdio.h>
#include <cassert>
#include <iostream>

#endif /* DiyFunctions_hpp */


template<typename T>
class myVector {
    
private:
    T* data_;
    size_t size_;
    size_t capacity_;
    
    void growVector();
        
public:
    myVector<T>(size_t initialSize); //constructor
    myVector<T>(); //constructor
    myVector<T>(myVector<T> const &myVec); //copy constructor
    ~myVector<T>(); //destructor
    void pushBack (T value);
    void popBack ();
    size_t getValue(size_t index);
    void setValue(size_t index, T newValue);
    size_t getSize();
    size_t getCapacity();
    void printVec();
    
    //STL updates
    T* begin();
    T* end();
    const T* begin() const;
    const T* end() const;
    
    myVector<T>& operator=(const myVector<T>& rhs);
    T& operator[](size_t index);
    const T& operator[] (size_t index) const;
    bool operator==(const myVector<T>& rhs);
    bool operator!=(const myVector<T>& rhs);
    bool operator<(const myVector<T>& rhs);
    bool operator>(const myVector<T>& rhs);
    bool operator<=(const myVector<T>& rhs);
    bool operator>=(const myVector<T>& rhs);
    myVector<T> operator+(const myVector<T>& rhs) const;
    
};

//STL updates
template<typename T>
T* myVector<T>::begin(){
    return data_;
}

template<typename T>
T* myVector<T>::end(){
    return (data_ + size_);
}

template<typename T>
const T* myVector<T>::begin() const{
    return data_;
}

template<typename T>
const T* myVector<T>::end() const{
    return (data_ + size_);
}

//constructor with an initial capacity input
template<typename T>
myVector<T>::myVector(size_t initialCapacity){
    assert(initialCapacity > 0 && "capacity is 0");
    capacity_ = initialCapacity;
    data_ = new T[capacity_];
    size_ = 0;
}

//constructor without an initial capacity input
template<typename T>
myVector<T>::myVector(){
    size_ = 0;
    capacity_ = 10;
    data_ = new T [capacity_];
}

//copy constructor
template<typename T>
myVector<T>::myVector(myVector<T> const &myVec){
    size_ = myVec.size_ * 2;
    capacity_ = size_ * 2;
    data_ = new T[capacity_];
    for(int i = 0; i < myVec.size_; i++){
        data_[i] = myVec.data_[i];
    }
}

//destructor
template<typename T>
myVector<T>::~myVector(){
    size_ = 0;
    capacity_ = 0;
    delete [] data_;
    data_ = nullptr;
}

//add more values to the end of the vector
template<typename T>
void myVector<T>::pushBack (T value){
    if(size_ == capacity_){
        growVector();
    }
    data_[size_] = value;
    size_++;
}

//clear the back value and decrease the size
template<typename T>
void myVector<T>::popBack (){
    assert(size_ != 0 && "vector is empty");
    size_--;
}

//return the appropriate value in the vector
template<typename T>
size_t myVector<T>::getValue(size_t index){
    assert(index <= size_ && "unknown index\n");
    return data_[index];
}

//set the appropriate value in the vector
template<typename T>
void myVector<T>::setValue(size_t index, T newValue){
    assert(index <= size_ && "unknown index\n");
    data_[index] = newValue;
}

//double the capacity of the vector
template<typename T>
void myVector<T>::growVector(){
    size_t newCapacity = capacity_ * 2;
    T* temp = new T [newCapacity];
    for(int i = 0; i < size_; i++){
        temp[i] = data_[i];
    }
    delete [] data_;
    data_ = temp;
    temp = nullptr;
}

//get size
template<typename T>
size_t myVector<T>::getSize(){
    return size_;
}

//get capacity
template<typename T>
size_t myVector<T>::getCapacity(){
    return capacity_;
}

//print vector
template<typename T>
void myVector<T>::printVec(){
    assert(size_ > 0 && "nothing in vector to print\n");
    for(int i = 0; i < size_; i++){
        std::cout << data_[i] << ' ';
    }
    std::cout << "\n";
}


//Operators -----------------------------------------------------

//= operator
template<typename T>
myVector<T>& myVector<T>::operator=(const myVector<T>& rhs){
    if(operator!= (rhs)){
        size_ = 0;
        capacity_ = 10;
        delete [] data_;
        data_ = new T [capacity_];
        for(int i = 0; i < rhs.size_; i++){
            pushBack(rhs.data_[i]);
        }
    }
    return *this;
}

//[] operator
template<typename T>
T& myVector<T>::operator[](size_t index){
    assert(index < size_ && "out of bounds in operator[]\n");
    return data_[index];
}

//[] operator but you can't change the value you're indexing into
template<typename T>
const T& myVector<T>::operator[] (size_t index) const{
    assert(index < size_ && "out of bounds in operator[]\n");
    return data_[index];
}

//== operator
template<typename T>
bool myVector<T>::operator==(const myVector<T>& rhs){
    if(size_ == rhs.size_){
        for(size_t i = 0; i < size_; i++){
            if(data_[i] != rhs.data_[i]){
                return false;
            }
        }
        return true;
    }
    return false;
}

// != operator
template<typename T>
bool myVector<T>::operator!=(const myVector<T>& rhs)
{
    return(! (operator== (rhs)) );
}

// > operator
template<typename T>
bool myVector<T>::operator>(const myVector<T>& rhs){
    if(size_ == rhs.size_){
        for(size_t i = 0; i < size_; i++){
            if(data_[i] > rhs.data_[i]){
                return true;
            }
            else if(data_[i] < rhs.data_[i]){
                return false;
            }
        }
    }
    return false;
}

// < operator
template<typename T>
bool myVector<T>::operator<(const myVector<T>& rhs){
    if(size_ == rhs.size_){
        if(!(operator> (rhs))){
            return true;
        }
    }
    return false;
}

// <= operator
template<typename T>
bool myVector<T>::operator<=(const myVector<T>& rhs){
    if(size_ == rhs.size_){
        if(operator== (rhs) || operator< (rhs)){
            return true;
        }
    }
    return false;
}

// >= operator
template<typename T>
bool myVector<T>::operator>=(const myVector<T>& rhs){
    if(size_ == rhs.size_){
        if(operator== (rhs) || operator> (rhs)){
            return true;
        }
    }
    return false;
}

// + operator
template<typename T>
myVector<T> myVector<T>::operator+(const myVector<T>& rhs) const{
    myVector<T> result;
    if(rhs.size_ == 0){
        result = *this;
        return result;
    }
    else{
        for(int i = 0; i < size_; i++){
            result.pushBack(data_[i]);
        }
        for(int i = 0; i < rhs.size_; i++){
            result.pushBack(rhs.data_[i]);
        }
        return result;
    }
}

