#include <iomanip>
#include <algorithm>
#include <iostream>
#include <random>
#include <thread>
#include <functional>

std::uniform_int_distribution<int> random_range(17, 255);

void displayLandfil(unsigned short landfil[], short len) {
    for (unsigned int a = 0; a < len; a++ ) {
        if (a % 8 == 0) 
            std::cout << std::hex << "\n*\t";

        std::cout << landfil[a];
        std::cout << " ";
    }
}

void fillFromTo(unsigned short landfil[], short from, short to) {
    std::mt19937 random_number_engine; 
    auto dice_roller = std::bind(random_range, random_number_engine);

    for (int a = from; a < to; a++ ) {
        landfil[a] = (unsigned short)(dice_roller());
    }
}

int main() {
    unsigned short landfil[8*8];
    std::fill(landfil, landfil+(8*8), 0);

    std::cout << "\n> Unfilled Memory:";
    displayLandfil(landfil, 8*8);

    std::cout << "\n\n> Single thread filled Memory:";
    fillFromTo(landfil, 0, 8*8);
    displayLandfil(landfil, 8*8);

    std::cout << "\n\n> 4 thread filled Memory:";
    std::thread threads[4];
    int size = (8*8)/4;
    for (int i = 0; i < 4; i++) {
        threads[i] = std::thread(fillFromTo, landfil, i*size, (i*size)+size);
    }
    for (int i = 0; i < 4; i++) {
        threads[i].join();
    }
    displayLandfil(landfil, 8*8);

    std::cout << "\n\n";
}