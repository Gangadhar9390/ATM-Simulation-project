# ATM-Simulation-project
ATM SIMULATION SYSTEM IN C

Project Overview:
-----------------
This project simulates an Automated Teller Machine (ATM) using the C programming language.
It allows users to perform operations like:
- Check balance
- Deposit money
- Withdraw money
- Change PIN

The data is stored in a CSV file (`users.csv`), simulating real-time account handling.

Language: C
Data Storage: users.csv (text-based)

-------------------------------------------------
File Structure:
-------------------------------------------------
main.c              - Entry point of the ATM system
atm.h               - Header file with struct and function declarations
atm_defination.c    - Function definitions for ATM operations
users.csv           - Stores user data (name, account no, pin, balance)
README.md           - Project description and usage guide

-------------------------------------------------
Features:
-------------------------------------------------
- Login using 11-digit Account Number and 4-digit PIN
- 3 login attempts before account is blocked
- Menu-driven UI with the following options:
    1. Check Balance
    2. Deposit Money (₹100, ₹200, ₹500 denominations only)
    3. Withdraw Money (within ₹50,000 limit)
    4. Change PIN
    5. Exit
- Transaction receipt with:
    - Date & Time
    - Name
    - Account Number
    - Transaction Type
    - Amount
    - Updated Balance
- Persistent data handling with file read/write

-------------------------------------------------
Sample CSV Format (users.csv):
-------------------------------------------------
Gangadhar,12345678901,1234,10000.00
Hari,98765432109,4321,15000.00

Each line contains:
Name,Account Number, PIN, Balance

-------------------------------------------------
How to Run:
-------------------------------------------------
1. Compile the project:
   gcc main.c atm_defination.c -o atm

2. Run the executable:
   ./atm

Make sure the users.csv file is in the same directory before running.

-------------------------------------------------
Sample Output 
-------------------------------------------------
<img width="1606" height="574" alt="Screenshot 2025-07-31 134431" src="https://github.com/user-attachments/assets/6daa5666-f261-4de2-bea7-40d86556e12c" />
<img width="1207" height="680" alt="Screenshot 2025-07-31 135642" src="https://github.com/user-attachments/assets/af2d5b53-8105-4a9d-92c1-10c31dd5e2cc" />
<img width="889" height="494" alt="Screenshot 2025-07-31 135911" src="https://github.com/user-attachments/assets/098252d3-b27a-4826-9ef0-d3e0977c9464" />
<img width="679" height="445" alt="Screenshot 2025-07-31 140054" src="https://github.com/user-attachments/assets/e4a5bb59-7904-42d5-b8a0-05ceb81db061" />
<img width="591" height="540" alt="Screenshot 2025-07-31 141417" src="https://github.com/user-attachments/assets/840b7316-45a2-4711-b149-5b29264369bc" />

------------------------------------------------
Demo video
------------------------------------------------
video link:https://drive.google.com/file/d/1BVFSmkP85RSBEb1Ii-iJjFJxSJpS5865/view?usp=sharing
-------------------------------------------------
C Concepts Used:
-------------------------------------------------
- Structures
- File Handling (fopen, fscanf, fprintf)
- Modular programming
- Input Validation
- Terminal UI enhancements with sleep() for delay

-------------------------------------------------
Future Enhancements:
-------------------------------------------------
- Masked input for PIN
- Admin interface to add/remove accounts
- GUI frontend using Python/C++
- Encrypt stored PINs

-------------------------------------------------
Author Info:
-------------------------------------------------
Name: Guruginzakunta Gangadhar
LinkedIn:https://www.linkedin.com/in/gangadhar-guruginzakunta
Date: July 2025

-------------------------------------------------
Thank You for Visiting This Project Repo!
If you find it helpful, feel free to ⭐ the repository!
