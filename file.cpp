#include <iostream>
#include <fstream>

int main() {
    // what is even going on in here?
    std::ofstream o("hello");

    o << "coalio sucks further." << std::endl;

    return 0;
}