#include <string>
#include <iostream>
#include <fstream>

using std::cerr;
using std::cin;
using std::cout;
using std::ifstream;
using std::ofstream;
using std::string;

// Shift encryption function
void shiftEncrypt(const string &inputFile, const string &outputFile, int key) {
    ifstream inFile(inputFile, std::ios::binary);
    ofstream outFile(outputFile, std::ios::binary);
    char ch;
    // XOR each character in the file with the key
    while (inFile.get(ch))
    {
        outFile.put(static_cast<char>(ch + key));
    }

    inFile.close();
    outFile.close();

    cout << "Operation completed! Output saved to: " << outputFile << "\n\n";
}

// Shift decryption function
void shiftDecrypt(const string &inputFile, const string &outputFile, int key) {
    ifstream inFile(inputFile, std::ios::binary);
    ofstream outFile(outputFile, std::ios::binary);
    char ch;
    // XOR each character in the file with the key
    while (inFile.get(ch))
    {
        outFile.put(static_cast<char>(ch - key));
    }

    inFile.close();
    outFile.close();

    cout << "Operation completed! Output saved to: " << outputFile << "\n\n";
}

bool manageFiles(const string &inputFile, const string &outputFile) {
    ifstream inFile(inputFile, std::ios::binary);
    if (!inFile) {
        cerr << "Error: Cannot open file " << inputFile << "\n";
        return false;
    }

    ofstream outFile(outputFile, std::ios::binary);
    if (!outFile) {
        cerr << "Error: Cannot create file " << outputFile << "\n";
        return false;
    }
    return true;
}
// Function to get valid user input (1, 2, or 3)
string getValidUserChoice()
{
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

// Function to extract only the filename from a full path
string getFilenameFromPath(const string &fullPath)
{
    size_t pos = fullPath.find_last_of("\\/");
    return (pos == string::npos) ? fullPath : fullPath.substr(pos + 1);
}

// Function to extract the directory path from the full path
string getDirectoryFromPath(const string &fullPath)
{
    size_t pos = fullPath.find_last_of("\\/"); // in case of format like C:\path\to\file
    return (pos == string::npos) ? "" : fullPath.substr(0, pos + 1);
}

// Function to get a valid file path from the user
string getValidFilePath()
{
    string filePath;
    ifstream file;

    cout << "Enter the path to the specified file:\n";
    cin >> filePath;
    cout << "\n";

    file.open(filePath);
    while (!file.is_open())
    {
        cerr << "Error: File not recognised. Please try again.\n";
        cout << "Enter path to specified file:\n";
        cin >> filePath;
        cout << "\n";
        file.open(filePath);
    }
    file.close();
    return filePath;
}

int main()
{
    int key = 4; // Shift encryption key
    string userChoice = getValidUserChoice();

    while (userChoice != "3") // Keep running until user chooses to exit
    {
        string inputFile = getValidFilePath();
        string filename = getFilenameFromPath(inputFile);   // Extracts only filename
        string directory = getDirectoryFromPath(inputFile); // Extracts the directory path
        string outputFile;

        if (userChoice == "1") // Encryption
        {
            outputFile = inputFile + ".enc"; // Save encrypted file with .enc extension
            shiftEncrypt(inputFile, outputFile, key);
        }
        else if (userChoice == "2") // Decryption
        {
            outputFile = directory + "decrypted_" + filename; // Save decrypted file correctly
            shiftDecrypt(inputFile, outputFile, key);
        }

        // Ask user for next action
        userChoice = getValidUserChoice();
    }

    cout << "Program exited.\n";
    return 0;
}
