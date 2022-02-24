#include <iostream>

unsigned char memory[255];
unsigned char pointer = 0;

void process_block(std::string code) {
    int pos = 0;

    while (pos < code.length()) {
        switch (code.at(pos)) {
            case '>':
                ++pointer;
                break;

            case '<':
                --pointer;
                break;

            case '+':
                ++memory[pointer];
                break;

            case '-':
                --memory[pointer];
                break;

            case '.':
                putchar(memory[pointer]);
                break;

            case ',':
                memory[pointer] = getchar();
                break;

            case '[':
                // pretty abstract but i guess indeed necessary.
                auto end = code.find_first_of(']');
                std::string subcode = code.substr(pos+1, end);

                // the auto thing is pretty useful 👍
                auto current_pointer = pointer;
                while (memory[current_pointer])
                    process_block(subcode);
                    
                pos = end;
        }
        pos++;
    }
}

int main() {
    // the following snippet of brainf*ck is from https://en.wikipedia.org/wiki/Brainfuck
    std::string code = "++++++++++[>+++++++>++++++++++>+++++++++++>+++>+<<<<<-]>++.>>+.---.<---.>>++.<+.++++++++.-------.<+++.>+.>+.>.";

    process_block(code);
}