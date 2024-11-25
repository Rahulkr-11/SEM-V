#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

bool simulate_even_even(const std::string& input_string) {
    // States
    int q0 = 0;  // even a's, even b's
    int q1 = 1;  // odd a's, even b's
    int q2 = 2;  // even a's, odd b's
    int q3 = 3;  // odd a's, odd b's

    // Start at the initial state
    int current_state = q0;

    // Process each character in the input string
    for (char charac : input_string) {
        if (current_state == q0) {
            if (charac == 'a') {
                current_state = q1;  // even a's to odd
            } else if (charac == 'b') {
                current_state = q2;  // even b's to odd
            }
        } else if (current_state == q1) {
            if (charac == 'a') {
                current_state = q0;  // odd a's to even
            } else if (charac == 'b') {
                current_state = q3;  // odd a's to odd b's
            }
        } else if (current_state == q2) {
            if (charac == 'a') {
                current_state = q3;  // even a's to odd
            } else if (charac == 'b') {
                current_state = q0;  // odd b's to even
            }
        } else if (current_state == q3) {
            if (charac == 'a') {
                current_state = q2;  // odd a's to even
            } else if (charac == 'b') {
                current_state = q1;  // odd b's to odd a's
            }
        } else {
            std::cerr << "Invalid state." << std::endl;
            return false;
        }
    }

    // Check if we are in the accepting state
    return current_state == q0;
}

int main() {
    string input_string;
    cout << "Enter a string of 'a's and 'b's: ";
    cin >> input_string;

    // Validate the input
    for (char c : input_string) {
        if (c != 'a' && c != 'b') {
            cout << "Invalid character: only 'a' and 'b' are allowed." << std::endl;
            return 1;
        }
    }

    if (simulate_even_even(input_string)) {
        cout << "Accepted" << std::endl;
    } else {
        cout << "Rejected" << std::endl;
    }

    return 0;
}
