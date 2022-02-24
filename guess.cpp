#include <iostream>
#include <chrono>

int main() {
    int num, input, tries = 0;

    // std::chrono::system_clock::now() is horrible,
    // why so much abstraction for something so simple?
    srand(time(NULL));
    num = rand() % (10);

    std::cout << "Guess the number between 0 and 9!\n\n";
    do {
        if (tries > 2) {
            std::cout << "Too much attempts, you lose...\n";
            break;
        }
        
        // cin makes sense considering that cout exists but...
        // why can it magically convert input strings into ints
        // implicitly?
        std::cout << "Number: ";
        std::cin >> input;

        if (input == num) {
            std::cout << "That was correct! You win!\n";
            break;

        } else {
            std::printf("Number too %s! Try again\n\n", 
                (input > num) ? "small" : "big");

        }

        tries++;
    } while (true);
}