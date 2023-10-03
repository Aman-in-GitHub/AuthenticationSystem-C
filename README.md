# Authentication System in C

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Usage](#usage)
- [File Structure](#file-structure)
- [How to Use](#how-to-use)
- [Note](#note)
- [Author](#author)
- [License](#license)

## Introduction

This is a simple command-line authentication system implemented in C. Users can sign up, log in, change their details, and delete their accounts. The system stores user information in a text file.

## Features

- **Sign Up**: Users can create an account by providing their name, username, contact number, address, email, and password.
- **Log In**: Users can log in using their username and password and view their account details.
- **Change Details**: Users can update their account information, including name, contact number, address, email, and password.
- **Delete Account**: Users can delete their account, and the system removes their information from the storage file.

## Usage

1. **Compile the Program**: Compile the C program using your preferred C compiler.

2. **Run the Program**: Run the compiled executable to launch the authentication system.

3. **Perform Actions**: Follow the on-screen prompts to perform actions such as signing up, logging in, changing details, or deleting your account.

## File Structure

- `main.c`: The main program source code.
- `login.txt`: A text file where user account information is stored.
- `temp.txt`: A temporary file used during the account deletion process.

## How to Use

1. When you run the program, you will be presented with a menu of options.

2. Choose an option by entering the corresponding number:
   - Option 1: Sign Up
   - Option 2: Change Details
   - Option 3: Log In
   - Option 4: Delete Account
   - Option 5: Exit
    
3. Follow the instructions for each option to perform the desired action.

## Note

- The user account information is stored in `login.txt`. Make sure this file is present in the same directory as the program.
- This is a basic authentication system and is not suitable for production use. It is intended for learning purposes and may not have robust security features.
