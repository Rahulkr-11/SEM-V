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
            if (state == "q0" && (c == 'a' || c == 'b')) {
                state = "q1";
                stack.push(c);  // Push each character of w onto the stack
            }
            else if (state == "q1" && (c == 'a' || c == 'b')) {
                stack.push(c);  // Continue pushing each character of w onto the stack
            }
            else if (state == "q1" && c == 'X') {
                state = "q2";  // Transition to q2 upon encountering the separator X
            }
            else if (state == "q2" && (c == 'a' || c == 'b')) {
                if (!stack.empty() && stack.top() == c) {
                    stack.pop();  // Pop matching characters for w^R
                    state = "q3";
                } else {
                    return false;
                }
            }
            else if (state == "q3" && (c == 'a' || c == 'b')) {
                if (!stack.empty() && stack.top() == c) {
                    stack.pop();  // Continue popping matching characters for w^R
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }

        // Final acceptance condition: q3 state with only the bottom marker in stack
        if (state == "q3" && stack.size() == 1 && stack.top() == 'Z') {
            return true; // Accept state
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
        cout << "Enter a string to test (wXwr pattern): ";
        cin >> input;

        if (pda.process(input)) {
            cout << input << " -> Accepted\n";
        } else {
            cout << input << " -> Rejected\n";
        }

        cout << "Do you want to test another string? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Program terminated.\n";
    return 0;
}
