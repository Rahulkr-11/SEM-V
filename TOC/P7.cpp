#include <iostream>
#include <stack>
#include <string>
using namespace std;

class PDA {
private:
    stack<char> stack;
    string state;

public:
    // Initialize PDA
    PDA() {
        stack.push('Z');  // Initial stack with bottom marker
        state = "q0";     // Start state
    }

    // Reset the PDA for a new input
    void reset() {
        while (!stack.empty()) stack.pop();
        stack.push('Z');  // Reinitialize stack with bottom marker
        state = "q0";     // Reset state to start
    }

    // Process the input string
    bool process(const std::string& input) {
        for (char c : input) {
            if (state == "q0" && c == 'a') {
                state = "q1";
                stack.push('A');  // Push 'A' for each 'a'
            }
            else if (state == "q1" && c == 'a') {
                stack.push('A');  // Continue pushing 'A' for each 'a'
            }
            else if (state == "q1" && c == 'b') {
                if (!stack.empty() && stack.top() == 'A') {
                    stack.pop();   // Pop 'A' for first 'b'
                    state = "q2";
                } else {
                    return false;
                }
            }
            else if (state == "q2" && c == 'b') {
                if (!stack.empty() && stack.top() == 'A') {
                    stack.pop();   // Pop 'A' for each 'b'
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }

        // Final acceptance condition: q2 state with only the bottom marker in stack
        if (state == "q2" && stack.size() == 1 && stack.top() == 'Z') {
            state = "q3"; // Accept state
            return true;
        }
        return false;
    }
};

int main() {
    PDA pda;
    string input;
    char choice;

    do {
        pda.reset();  // Reset the PDA for each new input
        cout << "Enter a string to test (anbn pattern): ";
        cin >> input;

        if (pda.process(input)) {
            std::cout << input << " -> Accepted\n";
        } else {
            cout << input << " -> Rejected\n";
        }

        cout << "Do you want to test another string? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Program terminated.\n";
    return 0;
}
