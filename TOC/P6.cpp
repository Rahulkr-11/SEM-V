#include <iostream>
#include <string>
using namespace std;

class FA_L1 {
public:
    bool accepts(const string& input) {
        if (input.length() < 4) {
            return false;
        }
        string first_two = input.substr(0, 2);
        string last_two = input.substr(input.length() - 2, 2);
        return first_two == last_two;
    }
};

class FA_L2 {
public:
    bool accepts(const string& input) {
        return input.length() >= 2 && input[0] == 'a' && input[input.length() - 1] == 'b';
    }
};

bool unionFA(FA_L1& fa1, FA_L2& fa2, const string& input) {
    return fa1.accepts(input) || fa2.accepts(input);
}

bool intersectionFA(FA_L1& fa1, FA_L2& fa2, const string& input) {
    return fa1.accepts(input) && fa2.accepts(input);
}

bool concatenationFA(FA_L1& fa1, FA_L2& fa2, const string& input) {
    for (size_t i = 1; i < input.length(); ++i) {
        string first_part = input.substr(0, i);
        string second_part = input.substr(i);
        if (fa1.accepts(first_part) && fa2.accepts(second_part)) {
            return true;
        }
    }
    return false;
}

int main() {
    FA_L1 fa1;
    FA_L2 fa2;
    string user_input;

    while (true) {
        std::cout << "Enter a string over the alphabet {a, b} (or type 'exit' to quit): ";
        std::getline(std::cin, user_input);

        if (user_input == "exit") {
            break; // Exit the loop if the user types 'exit'
        }

        // Check if the input is valid (only contains 'a' and 'b')
        if (user_input.find_first_not_of("ab") == string::npos) {
            cout << "\nAnalyzing string: '" << user_input << "'" << endl;

            // Check union
            if (unionFA(fa1, fa2, user_input)) {
                cout << "Union: The string is accepted by L1 or L2." << endl;
            } else {
                cout << "Union: The string is rejected by both L1 and L2." << endl;
            }

            // Check intersection
            if (intersectionFA(fa1, fa2, user_input)) {
                cout << "Intersection: The string is accepted by both L1 and L2." << endl;
            } else {
                cout << "Intersection: The string is rejected by at least one of L1 or L2." << endl;
            }

            // Check concatenation
            if (concatenationFA(fa1, fa2, user_input)) {
                cout << "Concatenation: The string can be split into parts accepted by L1 and L2." << endl;
            } else {
                cout << "Concatenation: The string cannot be split into parts accepted by L1 and L2." << endl;
            }
        } else {
            cout << "Invalid input. Please enter a string containing only 'a' and 'b'." << endl;
        }
    }

    return 0;
}
