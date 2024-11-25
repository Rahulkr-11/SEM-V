#include <iostream>
#include <string>
using namespace std;

bool finite_automaton(const std::string& input_string) {
    // States
    const int q0 = 0; // Initial state
    const int q1 = 1; // One '1' seen
    const int q2 = 2; // Two consecutive '1's seen
    const int q3 = 3; // Accepting state (three consecutive '1's)

    // Start at the initial state
    int current_state = q0;

    // Process each character in the input string
    for (char charac : input_string) {
        if (current_state == q0) {
            if (charac == '1') {
                current_state = q1;
            } else {
                current_state = q0;
            }
        } else if (current_state == q1) {
            if (charac == '1') {
                current_state = q2;
            } else {
                current_state = q0;
            }
        } else if (current_state == q2) {
            if (charac == '1') {
                current_state = q3; // Move to accepting state
            } else {
                current_state = q0;
            }
        } else if (current_state == q3) {
            // Once in the accepting state, remain there
            break;
        }
    }

    // Check if we are in the accepting state
    return current_state == q3;
}

int main() {
    string input_string;
    cout << "Enter a string of '0's and '1's: ";
    getline(std::cin, input_string);

    // Validate the input
    for (char c : input_string) {
        if (c != '0' && c != '1') {
            cout << "Invalid character: only '0' and '1' are allowed." << std::endl;
            return 1; // Return with an error code
        }
    }

    if (finite_automaton(input_string)) {
        cout << "Accepted" << std::endl;
    } else {
        cout << "Rejected" << std::endl;
    }

    return 0;
}
