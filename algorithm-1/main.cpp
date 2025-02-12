#include <string>
#include <iostream>
#include <fstream>

using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::ifstream;
using std::ofstream;

int main(int argc, char* argv[]) {

    string userInput;

    cout << "Input \"1\" to encrypt a file. Input \"2\" to decrypt a file. Input \"3\" to quit the program.\n";
    cin >> userInput;
    cout << "\n";

    while ((userInput != "1") && (userInput != "2") && (userInput != "3")) {

        cerr << "Error: Command not recognised. Please try again.\n";
        cout << "Input \"1\" to encrypt a file. Input \"2\" to decrypt a file. Input \"3\" to quit the program.\n";
        cin >> userInput;
        cout << "\n";
    }

    while ((userInput == "1") || (userInput == "2")) {

        if (userInput == "1") {

            cout << "Enter path to specified file.\n";

            // TODO: Remove this print statement (debug).
            cout << "(Encryption)\n";
            
            cin >> userInput;
            cout << "\n";
            
            //---- Potential code that we can use to open files. ----//
            // ifstream encryptionFS;
            // encryptionFS.open(userInput);

            // while (!encryptionFS.is_open()) {

            //     cerr << "Error: File not recognised. Please try again.\n"
            //     cout << "Enter path to specified file:\n"

            //     cin >> userInput;
            //     cout << "\n";

            //     encryptionFS.close();
            //     encryptionFS.open(userInput);
            // }
        } else {

            cout << "Enter path to specified file.\n";

            // TODO: Remove this print statement (debug).
            cout << "(Decryption)\n";

            cin >> userInput;
            cout << "\n";

            //---- Potential code that we can use to open files. ----//
            // ifstream decryptionFS;
            // decryptionFS.open(userInput);

            // while (!decryptionFS.is_open()) {

            //     cerr << "Error: File not recognised. Please try again.\n"
            //     cout << "Enter path to specified file:\n"

            //     cin >> userInput;
            //     cout << "\n";

            //     decryptionFS.close();
            //     decryptionFS.open(userInput);
            // }
        }

        cout << "Input \"1\" to encrypt a file. Input \"2\" to decrypt a file. Input \"3\" to quit the program.\n";
        cin >> userInput;
        cout << "\n";

        while ((userInput != "1") && (userInput != "2") && (userInput != "3")) {

            cerr << "Error: Command not recognised. Please try again.\n";
            cout << "Input \"1\" to encrypt a file. Input \"2\" to decrypt a file. Input \"3\" to quit the program.\n";
            cin >> userInput;
            cout << "\n";
        }
    }
}