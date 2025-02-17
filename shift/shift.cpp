/*-------------------------------------------------------------------------------------------
Shift Encryption Algorithm
Authors: Fletcher Green, Alex Chan, and Joyce Tang
-------------------------------------------------------------------------------------------*/

#include <string>
#include <iostream>
#include <fstream>

using std::cerr;
using std::cin;
using std::cout;
using std::ifstream;
using std::ofstream;
using std::string;

// shiftEncrypt Function:
// - Purpose: Encrypt a specified file by shifting the ascii of characters.
// - Parameters:
//   - inputFile: File path to the file undergoing encryption.
//   - outputFile: File path to store the product of decryption.
//   - key: Integer by which to shift the given input.
void shiftEncrypt(const string &inputFile, const string &outputFile, int key) {
    
    ifstream inFile(inputFile, std::ios::binary);
    ofstream outFile(outputFile, std::ios::binary);
    char ch;
    
    while (inFile.get(ch)) {
        
        // Unshift current char by the key integer.
        outFile.put(static_cast<char>(ch + key));
    }

    // Close files after use.
    inFile.close();
    outFile.close();

    cout << "Operation completed! Output saved to: " << outputFile << "\n\n";
}

// shiftDecrypt Function:
// - Purpose: Decrypt a file that has undergone shift encryption.
// - Parameters:
//   - inputFile: File path to the file undergoing encryption.
//   - outputFile: File path to store the product of decryption.
//   - key: Integer by which to unshift the given input.
void shiftDecrypt(const string &inputFile, const string &outputFile, int key) {
    
    ifstream inFile(inputFile, std::ios::binary);
    ofstream outFile(outputFile, std::ios::binary);
    char ch;
    
    while (inFile.get(ch)) {

        // Unshift current char by the key integer.
        outFile.put(static_cast<char>(ch - key));
    }

    // Close files after use.
    inFile.close();
    outFile.close();

    cout << "Operation completed! Output saved to: " << outputFile << "\n\n";
}

// getValidUserChoice Function:
// - Purpose: Query the user until a number between one and three is received.
// - Return: A number between one and three as specified by the user.
string getValidUserChoice() {
    
    string choice;
    cout << "Input \"1\" to encrypt a file. Input \"2\" to decrypt a file. Input \"3\" to quit the program.\n";
    cin >> choice;
    cout << "\n";

    // Try to collect user input again if command is not recognised.
    while ((choice != "1") && (choice != "2") && (choice != "3")) {

        cerr << "Error: Command not recognised. Please try again.\n";
        cout << "Input \"1\" to encrypt a file. Input \"2\" to decrypt a file. Input \"3\" to quit the program.\n";
        cin >> choice;
        cout << "\n";
    }

    return choice;
}

// GetFileName Function:
// - Purpose: Given a linux file path, return the name of the specified file ignoring the extension.
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

// getValidFilePath Function::
// - Purpose: Query the user until a valid file path is received.
// - Return: Linux file path.
string getValidFilePath() {
    
    string filePath;
    ifstream file;

    cout << "Enter the path to the specified file:\n";
    cin >> filePath;
    cout << "\n";

    // Attempt to open the file specified by the user. If the file cannot be opened, try again.
    file.open(filePath);
    while (!file.is_open())
    {
        cerr << "Error: File not recognised. Please try again.\n";
        cout << "Enter path to specified file:\n";
        cin >> filePath;
        cout << "\n";
        file.open(filePath);
    }

    // Close the file and return the path to the file.
    file.close();
    return filePath;
}

int main() {
    
    // Shift encryption key.
    int key = 4;

    // Gets menu choice from user.
    string userChoice = getValidUserChoice();

    while (userChoice != "3") { // Keep running until user chooses to exit.

        // Get input file path and input file name.
        string inputFile = getValidFilePath();
        string fileName = GetFileName(inputFile);
        string outputFile;

        if (userChoice == "1") // Encryption.
        {
            outputFile = "./encrypted/" + fileName + ".enc"; // Save encrypted file with .enc extension.
            shiftEncrypt(inputFile, outputFile, key);
        }
        else if (userChoice == "2") // Decryption.
        {
            outputFile = "./decrypted/" + fileName + ".dec"; // Save decrypted file with .dec extension.
            shiftDecrypt(inputFile, outputFile, key);
        }

        // Ask user for next action.
        userChoice = getValidUserChoice();
    }

    cout << "Program exited.\n";
    return 0;
}