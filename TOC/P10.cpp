#include <iostream>
#include <string>
using namespace std;

enum class State {
    q0,      // Initial state
    q1,      // Carry state
    qAccept, // Accepting state
};

void incrementBinary(string& tape) {
    size_t head = tape.length() - 1; // Start at the rightmost bit
    State state = State::q0;          // Initial state

    while (state != State::qAccept) {
        char currentSymbol = (head < tape.length()) ? tape[head] : '_'; // Use '_' for blank

        switch (state) {
            case State::q0:
                if (currentSymbol == '0') {
                    tape[head] = '1'; // Change '0' to '1'
                    state = State::qAccept; // Go to accepting state
                } else if (currentSymbol == '1') {
                    tape[head] = '0'; // Change '1' to '0' (carry)
                    head--; // Move left
                    state = State::q1; // Go to carry state
                } else {
                    state = State::qAccept; // If blank, go to accept (but should not happen here)
                }
                break;

            case State::q1:
                if (currentSymbol == '0') {
                    tape[head] = '1'; // Change '0' to '1' and accept
                    state = State::qAccept; // Go to accepting state
                } else if (currentSymbol == '1') {
                    tape[head] = '0'; // Change '1' to '0' and continue carrying
                    head--; // Move left
                } else { // Reached blank
                    // This handles the case where we need to add '1' to the front
                    tape.insert(tape.begin(), '1'); // Prepend '1'
                    state = State::qAccept; // Accept
                }
                break;

            default:
                state = State::qAccept; // If in any unknown state, go to accept
                break;
        }
    }
}

int main() {
    string input;
    cout << "Enter a binary number: ";
    cin >> input;

    // Validate input
    for (char ch : input) {
        if (ch != '0' && ch != '1') {
            cout << "Invalid input! Only binary digits (0 or 1) are allowed." << endl;
            return 1;
        }
    }

    incrementBinary(input);

    cout << "Incremented binary number: " << input << endl;

    return 0;
}