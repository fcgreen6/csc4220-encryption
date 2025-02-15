#include <string>
#include <iostream>
#include <fstream>

using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::ifstream;
using std::ofstream;

string GetFileName(string filePath);

int main(int argc, char* argv[]) {

    string userInput;

    cout << "Input \"1\" to encrypt a file. Input \"2\" to decrypt a file. Input \"3\" to quit the program.\n";
    cin >> userInput;
    cout << "\n";

    // Try to collect user input again if command is not recognised.
    while ((userInput != "1") && (userInput != "2") && (userInput != "3")) {

        cerr << "Error: Command not recognised. Please try again.\n";
        cout << "Input \"1\" to encrypt a file. Input \"2\" to decrypt a file. Input \"3\" to quit the program.\n";
        cin >> userInput;
        cout << "\n";
    }

    while ((userInput == "1") || (userInput == "2")) {

        if (userInput == "1") {

            cout << "Enter path to specified file:\n";

            cin >> userInput;
            cout << "\n";

            // Attempt to open specified file.
            ifstream encryptionFS;
            encryptionFS.open(userInput);

            while (!encryptionFS.is_open()) {

                // Reset state flags.
                encryptionFS.clear();

                cerr << "Error: File not recognised. Please try again.\n";
                cout << "Enter path to specified file:\n";

                cin >> userInput;
                cout << "\n";
                
                // Attempt to reopen the file.
                encryptionFS.open(userInput);
            }

            // TODO: Encryption code here...

            // Get the name of the file specified by the user. Create new file name for saving the decrypted product.
            string outFileName = GetFileName(userInput);
            outFileName = "./encrypted/" + outFileName + "-encrypted.txt";

            // Put decrypted product into this file stream to save in within the decryption folder.
            ofstream outputFS;
            outputFS.open(outFileName, std::ios::trunc); // Trunc trait removes any existing elements within the file.

            // Close file streams.
            encryptionFS.close();
            outputFS.close();
        } else {

            cout << "Enter path to specified file:\n";

            cin >> userInput;
            cout << "\n";

            // Attempt to open specified file.
            ifstream decryptionFS;
            decryptionFS.open(userInput);

            while (!decryptionFS.is_open()) {

                // Reset state flags.
                decryptionFS.clear();

                cerr << "Error: File not recognised. Please try again.\n";
                cout << "Enter path to specified file:\n";

                cin >> userInput;
                cout << "\n";
                
                // Attempt to reopen the file.
                decryptionFS.open(userInput);
            }

            // TODO: Decryption code here...

            // Get the name of the file specified by the user. Create new file name for saving the decrypted product.
            string outFileName = GetFileName(userInput);
            outFileName = "./decrypted/" + outFileName + "-decrypted.txt";

            // Put decrypted product into this file stream to save in within the decryption folder.
            ofstream outputFS;
            outputFS.open(outFileName, std::ios::trunc); // Trunc trait removes any existing elements within the file.

            // Close file streams.
            decryptionFS.close();
            outputFS.close();
        }

        cout << "Input \"1\" to encrypt a file. Input \"2\" to decrypt a file. Input \"3\" to quit the program.\n";
        cin >> userInput;
        cout << "\n";

        // Try to collect user input again if command is not recognised.
        while ((userInput != "1") && (userInput != "2") && (userInput != "3")) {

            cerr << "Error: Command not recognised. Please try again.\n";
            cout << "Input \"1\" to encrypt a file. Input \"2\" to decrypt a file. Input \"3\" to quit the program.\n";
            cin >> userInput;
            cout << "\n";
        }
    }
}

// GetFileName Function:
// - Purpose: Given a file path, return the name of the specified file ignoring the extension.
// - Parameters:
//   - filePath: A string containing the file path to the specified file.
// - Return: The name of the specified file. Example: Given filePath "./test.txt" the function should return "test".
string GetFileName(string filePath) {

    // Find the postions of the final backslash and period of the file path.
    size_t separatorOne = filePath.find_last_of("/");
    size_t separatorTwo = filePath.find_last_of(".");

    // If there is no backslask due to the file being relative, start the substring at index zero.
    if (separatorOne == string::npos) {

        return filePath.substr(0, separatorTwo);
    }

    return filePath.substr(separatorOne + 1, separatorTwo - separatorOne - 1);
}