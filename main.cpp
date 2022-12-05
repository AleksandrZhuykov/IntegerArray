#include <iostream>
#include "IntegerArray.h"

void show(const  integerArray& arr)
{
    for (const auto& i : arr)
        std::cout << i << " ";
    std::cout << std::endl;
}

int main()
{
    integerArray arr(10);

    arr[0] = 2;
    arr[1] = 5;
    arr[2] = 6;
    arr[3] = 6;
    arr[4] = 7;
    arr[5] = 8;
    arr[6] = 9;
    arr[7] = 1;
    arr[8] = 3;
    arr[9] = 9;
    try {
        arr[10] = 7;
    }
    catch (bad_range& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        arr.resize(-1);
    }
    catch (bad_length& e) {
        std::cout << e.what() << std::endl;
    }

    arr.resize(11);
    arr[10] = 8;

    show(arr);

    arr.insert_at_end(9);
    show(arr);

    std::cout << arr.get_size() << std::endl;

    try {
        arr.insert_before(10, 8);
    }
    catch (bad_range& e) {
        std::cout << e.what() << std::endl;
    }
}