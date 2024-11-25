#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
using namespace std;

class FiniteAutomaton {
public:
    FiniteAutomaton() {
        reset();  // Initialize
    }

    void reset() {
        // Reset the automaton to the start state
        first_two.clear();
        last_two.clear();
    }

    bool accepts(const std::string& inputString) {
        reset();  // Reset to the start state
        if (inputString.length() < 4) {
            return false;  // Reject if the length is less than 4
        }

        for (size_t i = 0; i < inputString.length(); ++i) {
            char charac = inputString[i];
            if (charac != 'a' && charac != 'b') {
                throw std::invalid_argument("Input string must contain only 'a' and 'b'");
            }

            transition(charac);
        }

        // Check if the first two characters match the last two characters
        return (first_two.size() == 2 && last_two.size() == 2 && first_two == last_two);
    }

private:
    vector<char> first_two;  // To store the first two characters
    vector<char> last_two;   // To store the last two characters

    void transition(char charac) {
        if (first_two.size() < 2) {
            first_two.push_back(charac);  // Store the first two characters
        } else {
            last_two.push_back(charac);  // Record the last two characters
            if (last_two.size() > 2) {
                last_two.erase(last_two.begin());  // Keep only the last two characters
            }
        }
    }
};

// Main program
int main() {
    FiniteAutomaton fa;

    while (true) {
        string inputString;
        cout << "Enter a string over the alphabet {a, b} (or type 'exit' to quit): ";
        getline(std::cin, inputString);
        if (inputString == "exit") {
            break;  // Exit the loop if the user types 'exit'
        }

        try {
            if (fa.accepts(inputString)) {
                cout << "The string '" << inputString << "' is accepted." << std::endl;
            } else {
                cout << "The string '" << inputString << "' is rejected." << std::endl;
            }
        } catch (const std::invalid_argument& e) {
            cout << e.what() << std::endl;
        }
    }

    return 0;
}
