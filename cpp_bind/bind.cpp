#include <stdio.h>
#include <iostream>
#include <functional>

void test(int x, int y, int z) {
    std::cout << "x: " << x << " y: " << y << " z: " << z << std::endl;
}

void caller()

int main()
{
    test(1,2,3);
    auto fn_five = std::bind(test, 10, 2, 3);
    fn_five();

    auto fn_six = std::bind(test, 10, 2, std::placeholders::_1);
    fn_six(6);
    std::cout << typeid(fn_five).name() << std::endl;
    std::cout << typeid(fn_six).name() << std::endl;
    return 0;
}

