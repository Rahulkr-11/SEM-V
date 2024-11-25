#include <iostream>
#include <string>
using namespace std;

class FiniteAutomaton {
public:
    FiniteAutomaton() : count(0) {}  // Initialize count of '1's to 0

    bool processString(const std::string& inputString) {
        // Process each character in the input string
        for (char charac : inputString) {
            if (charac != '0' && charac != '1') {
                throw std::invalid_argument("Input string must contain only '0' and '1'");
            }
            if (charac == '1') {
                count++;
                // If we exceed 3 '1's, we can immediately reject
                if (count > 3) {
                    return false;
                }
            }
        }
        
        // Accept if we have exactly 2 or exactly 3 '1's
        return count == 2 || count == 3;
    }

private:
    int count; // Count of '1's encountered
};

// Main program
int main() {
    // Instantiate the FA
    FiniteAutomaton fa;

    // User input
    string inputString;
    cout << "Enter a binary string: ";
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
