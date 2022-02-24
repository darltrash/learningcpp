#include <iostream>

int fib(int n) {
    if (n == 0)
        return 0;
    else if (n == 1) 
        return 1;

    return (fib(n-1) + fib(n-2));
}

int main() {
    // this cout thing is weird but i guess it
    // does make some sense
    std::cout << "Fibonacci: ";
    
    int i;
    for (i = 0; i < 10 ;i++)
        std::printf("%d ", fib(i));

    std::cout << "\n";
}