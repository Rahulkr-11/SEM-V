#include <iostream>
#include <vector>
#include <string>

class TuringMachine {
public:
    TuringMachine() : state(0), tape(""), head(0) {}

    void setInput(const std::string& input) {
        tape = input + "#"; // Add a blank symbol at the end
        head = 0;
        state = 0;
    }

    bool simulate() {
        while (true) {
            char currentSymbol = tape[head];
            switch (state) {
                case 0: // q0
                    if (currentSymbol == 'a') {
                        tape[head] = 'X'; // Mark 'a'
                        head++;
                        state = 1; // Move to q1
                    } else if (currentSymbol == '#') {
                        return true; // Accept if we reach the end
                    } else {
                        return false; // Reject
                    }
                    break;
                case 1: // q1
                    if (currentSymbol == 'a') {
                        head++;
                    } else if (currentSymbol == 'b') {
                        tape[head] = 'Y'; // Mark 'b'
                        head++;
                        state = 2; // Move to q2
                    } else {
                        return false; // Reject
                    }
                    break;
                case 2: // q2
                    if (currentSymbol == 'b') {
                        head++;
                    } else if (currentSymbol == 'c') {
                        tape[head] = 'Z'; // Mark 'c'
                        head++;
                        state = 3; // Move to q3
                    } else {
                        return false; // Reject
                    }
                    break;
                case 3: // q3
                    if (currentSymbol == 'c') {
                        head++;
                    } else if (currentSymbol == '#') {
                        return true; // Accept if we reach the end
                    } else {
                        return false; // Reject
                    }
                    break;
            }
        }
    }

private:
    int state;
    std::string tape;
    int head;
};

int main() {
    TuringMachine tm;
    std::string input;

    std::cout << "Enter a string of the form anbncn (e.g., aaabbbccc): ";
    std::cin >> input;

    tm.setInput(input);
    if (tm.simulate()) {
        std::cout << "Accepted\n";
    } else {
        std::cout << "Rejected\n";
    }

    return 0;
}
