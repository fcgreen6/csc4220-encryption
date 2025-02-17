# csc4220-encryption
### Description:
- This repository contains two implementations of encryption algorithms.
- **XOR encryption** applies the **exclusive or** operator to the bits of each character in a file. By the same process, encrypted files can be decrypted.
- **Shift encryption** shifts the ascii value of each character in a file by an integer value. By the same process, encrypted files can be decrypted.
### How to Run:
- Install WSL (or just have Linux OS) and a cpp compiler such as MinGW.
- Clone the repo and navigate to the program directory.
- Compile the cpp file in each sub-directory.
- Run the executable files.
  - Each file uses the same menu.
  - Step One:
    - Enter **"1"** to encrypt a file. Enter **"2"** to decrypt a file. Enter **"3"** to quit the program.
  - Step Two:
    - Enter the Linux file path or relative path to the file you want to encrypt/decrypt.
    - After you specify a valid file, the result will be sored in a relative directory.
    - Encrypted files are stored with the **.enc** extension and decrypted files are stored with the **.dec** extension.
