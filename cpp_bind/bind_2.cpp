#include <stdio.h>
#include <functional>

std::function<void(void)> try_this() {
    int x = 10;
    std::function<void(int)> lambda = [](int x) { printf("hello %d\n", x); };
    std::function<void(void)> lambda_2 = std::bind(lambda, x);
    return lambda_2;
}

int main()
{
    std::function<void(void)> l = try_this();
    l();

    return 0;
}
