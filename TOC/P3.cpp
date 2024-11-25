#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class FiniteAutomaton {
public:
    // Constructor not needed for state; keep it simple
    FiniteAutomaton() {}

    bool processString(const std::string& inputString) {
        // Ensure the input string is of valid length
        if (inputString.length() < 4) {
            return false;  // Automatically reject if length is less than 4
        }

        // Store the first two characters
        char first1 = inputString[0];
        char first2 = inputString[1];

        // Variables to track the last two characters
        char last1, last2;

        // Iterate over the input string starting from the third character
        for (size_t i = 2; i < inputString.length(); ++i) {
            char charac = inputString[i];

            if (charac != 'a' && charac != 'b') {
                throw std::invalid_argument("Input string must contain only 'a' and 'b'");
            }

            // Update the last two characters
            last2 = last1;  // Shift last1 to last2
            last1 = charac; // Update last1 to the current character
        }

        // Check if the first two characters match the last two characters
        return (first1 == last2 && first2 == last1);
    }
};

// Main program
int main() {
    // Instantiate the FA
    FiniteAutomaton fa;

    // User input
    string inputString;
    cout << "Enter a string over {a, b} of length 4 or more: ";
    getline(std::cin, inputString);

    // Process and display the result
    try {
        string result = fa.processString(inputString) ? "Accepted" : "Rejected";
        cout << "String: " << inputString << " -> " << result << std::endl;
    } catch (const std::invalid_argument& e) {
        cout << e.what() << std::endl;
    }

    return 0;
}
