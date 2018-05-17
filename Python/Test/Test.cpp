//
// Created by ruby on 29.03.18.
//
#include <iostream>

#define EQUAL(val1, val2) equal(val1, val2, __func__, __LINE__)

template <typename T>
bool equal(T val1, T val2, const char* name, int line){
    if(val1 !=  val2){
        std::cout << val1 << std::endl;
        std::cout << val2 << std::endl;
        std::cout << name << std::endl;
        std::cout << line << std::endl;
        return false;
    }
    return true;
}

int add(int a, int b){
    return a+b;
}

int main(){
    EQUAL(add(2, 3), 6);
}