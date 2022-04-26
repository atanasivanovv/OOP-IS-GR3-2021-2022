#include <iostream>
#include <cstring>
#include "dynamic_arr.h"
 
using namespace std;

int main() {
    std::cout << std::endl;
    DynamicArray arr;
    arr.push_back(2);
    arr.push_back(5);
    arr.push_back(6);

    const int first = arr[0];
    int second = arr[1];
    arr.print();
    std::cout << arr[0] << std::endl;
    std::cout << arr[1] << std::endl;
    std::cout << arr[2] << std::endl;
}