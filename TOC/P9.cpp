#include <iostream>
#include <string>
using namespace std;

bool isAccepted(string tape) {
    int head = 0;
    int state = 0;
    bool foundMatch = false;

    while (true) {
        // Check if the string has been fully processed
        if (tape.find('a') == string::npos && tape.find('b') == string::npos && tape.find('c') == string::npos) {
            return true;
        }
        
        // Move through each state to match one 'a', one 'b', and one 'c'
        switch (state) {
            case 0:  // Find and mark an 'a'
                foundMatch = false;
                while (head < tape.size()) {
                    if (tape[head] == 'a') {
                        tape[head] = 'X';  // Mark 'a' as 'X'
                        state = 1;         // Move to state to find 'b'
                        foundMatch = true;
                        break;
                    }
                    head++;
                }
                if (!foundMatch) return false;  // Reject if no more 'a's to match
                head = 0;  // Reset head to beginning
                break;

            case 1:  // Find and mark a 'b' after 'X'
                foundMatch = false;
                while (head < tape.size()) {
                    if (tape[head] == 'b') {
                        tape[head] = 'Y';  // Mark 'b' as 'Y'
                        state = 2;         // Move to state to find 'c'
                        foundMatch = true;
                        break;
                    }
                    head++;
                }
                if (!foundMatch) return false;  // Reject if no more 'b's to match
                head = 0;  // Reset head to beginning
                break;

            case 2:  // Find and mark a 'c' after 'Y'
                foundMatch = false;
                while (head < tape.size()) {
                    if (tape[head] == 'c') {
                        tape[head] = 'Z';  // Mark 'c' as 'Z'
                        state = 0;         // Return to initial state to mark next 'a'
                        foundMatch = true;
                        break;
                    }
                    head++;
                }
                if (!foundMatch) return false;  // Reject if no more 'c's to match
                head = 0;  // Reset head to beginning
                break;
        }
    }
}

int main() {
    string input;
    cout << "Enter the input string (e.g., aabbcc): ";
    cin >> input;

    if (isAccepted(input)) {
        cout << "Accepted: The string is in the language a^n b^n c^n." << endl;
    } else {
        cout << "Rejected: The string is not in the language a^n b^n c^n." << endl;
    }

    return 0;
}
