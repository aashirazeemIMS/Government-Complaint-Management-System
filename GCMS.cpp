#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// ANSI color codes
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"

// Complaint structure
struct Complaint {
    string govtID;
    string name;
    string complaint;
    string status;
};

// Function to register a user
void registerUser() {
    string username, password, role;
    ofstream outFile("users.txt", ios::app);

    cout << BOLD << CYAN << "Enter a Username: " << RESET;
    cin >> username;
    cout << BOLD << CYAN << "Enter a Password: " << RESET;
    cin >> password;
    cout << BOLD << CYAN << "Enter Role (citizen/official): " << RESET;
    cin >> role;

    outFile << username << "," << password << "," << role << endl;
    outFile.close();

    cout << GREEN << BOLD << "User registered successfully!\n" << RESET;
}

// Function to authenticate a user
string loginUser() {
    string username, password, fileUsername, filePassword, fileRole;
    ifstream inFile("users.txt");

    cout << BOLD << CYAN << "Enter Username: " << RESET;
    cin >> username;
    cout << BOLD << CYAN << "Enter Password: " << RESET;
    cin >> password;

    while (getline(inFile, fileUsername, ',') &&
           getline(inFile, filePassword, ',') &&
           getline(inFile, fileRole)) {
        if (username == fileUsername && password == filePassword) {
            inFile.close();
            return fileRole;
        }
    }

    inFile.close();
    return "invalid";
}

// Function to register a complaint
void registerComplaint() {
    Complaint c;
    ofstream outFile("complaints.txt", ios::app);

    cout << BOLD << YELLOW << "Enter your Government ID: " << RESET;
    cin >> c.govtID;
    cin.ignore();

    cout << BOLD << YELLOW << "Enter your Name: " << RESET;
    getline(cin, c.name);

    cout << BOLD << YELLOW << "Enter your Complaint: " << RESET;
    getline(cin, c.complaint);

    c.status = "Pending";

    outFile << c.govtID << "," << c.name << "," << c.complaint << "," << c.status << endl;
    outFile.close();

    cout << GREEN << BOLD << "Complaint Registered Successfully!\n" << RESET;
}

// Function to view complaints by Government ID
void viewMyComplaints() {
    string id;
    cout << BOLD << CYAN << "Enter your Government ID: " << RESET;
    cin >> id;

    ifstream inFile("complaints.txt");
    string govtID, name, complaint, status;
    bool found = false;

    cout << BOLD << "\nYour Complaints:\n" << RESET;
    while (getline(inFile, govtID, ',') &&
           getline(inFile, name, ',') &&
           getline(inFile, complaint, ',') &&
           getline(inFile, status)) {
        if (govtID == id) {
            cout << BOLD << BLUE << "Name: " << RESET << name << endl;
            cout << BOLD << BLUE << "Complaint: " << RESET << complaint << endl;
            cout << BOLD << BLUE << "Status: " << RESET << status << "\n\n";
            found = true;
        }
    }

    inFile.close();
    if (!found) {
        cout << RED << BOLD << "No complaints found for your Government ID!\n" << RESET;
    }
}

// Function to manage complaints (for officials)
void manageComplaints() {
    string govtID, name, complaint, status;
    ifstream inFile("complaints.txt");

    cout << BOLD << "\n--- All Complaints ---\n" << RESET;
    bool found = false;

    while (getline(inFile, govtID, ',') &&
           getline(inFile, name, ',') &&
           getline(inFile, complaint, ',') &&
           getline(inFile, status)) {
        cout << BOLD << CYAN << "Govt ID: " << RESET << govtID << endl;
        cout << BOLD << CYAN << "Name: " << RESET << name << endl;
        cout << BOLD << CYAN << "Complaint: " << RESET << complaint << endl;
        cout << BOLD << CYAN << "Status: " << RESET << status << "\n\n";
        found = true;
    }
    inFile.close();

    if (!found) {
        cout << RED << BOLD << "No complaints found!\n" << RESET;
        return;
    }

    cout << BOLD << "Enter the Government ID of the complaint to update status: " << RESET;
    string updateID;
    cin >> updateID;

    cout << BOLD << "Select new status:\n1. Pending\n2. In Progress\n3. Resolved\n" << RESET;
    int statusChoice;
    cin >> statusChoice;

    string newStatus;
    switch (statusChoice) {
        case 1: newStatus = "Pending"; break;
        case 2: newStatus = "In Progress"; break;
        case 3: newStatus = "Resolved"; break;
        default: cout << RED << BOLD << "Invalid choice!\n" << RESET; return;
    }

    ifstream tempIn("complaints.txt");
    ofstream tempOut("temp.txt");

    while (getline(tempIn, govtID, ',') &&
           getline(tempIn, name, ',') &&
           getline(tempIn, complaint, ',') &&
           getline(tempIn, status)) {
        if (govtID == updateID) {
            tempOut << govtID << "," << name << "," << complaint << "," << newStatus << endl;
        } else {
            tempOut << govtID << "," << name << "," << complaint << "," << status << endl;
        }
    }

    tempIn.close();
    tempOut.close();
    remove("complaints.txt");
    rename("temp.txt", "complaints.txt");

    cout << GREEN << BOLD << "\nComplaint status updated successfully!\n" << RESET;
}

// Main function
int main() {
    int choice;
    string role;

    while (true) {
        cout << BOLD << YELLOW << "\n--- Government Complaint Management System ---\n" << RESET;
        cout << BOLD << "1. Register as a New User\n2. Login\n3. Exit\n" << RESET;
        cout << BOLD << CYAN << "Enter your choice: " << RESET;
        cin >> choice;

        if (choice == 1) {
            registerUser();
        } else if (choice == 2) {
            role = loginUser();
            if (role == "citizen") {
                int userChoice;
                while (true) {
                    cout << BOLD << "\n--- Citizen Menu ---\n" << RESET;
                    cout << "1. Register Complaint\n2. View My Complaints\n3. Logout\n";
                    cout << BOLD << CYAN << "Enter your choice: " << RESET;
                    cin >> userChoice;

                    if (userChoice == 1) registerComplaint();
                    else if (userChoice == 2) viewMyComplaints();
                    else if (userChoice == 3) break;
                    else cout << RED << BOLD << "Invalid choice!\n" << RESET;
                }
            } else if (role == "official") {
                int officialChoice;
                while (true) {
                    cout << BOLD << "\n--- Official Menu ---\n" << RESET;
                    cout << "1. Manage Complaints\n2. Logout\n";
                    cout << BOLD << CYAN << "Enter your choice: " << RESET;
                    cin >> officialChoice;

                    if (officialChoice == 1) manageComplaints();
                    else if (officialChoice == 2) break;
                    else cout << RED << BOLD << "Invalid choice!\n" << RESET;
                }
            } else {
                cout << RED << BOLD << "Invalid credentials!\n" << RESET;
            }
        } else if (choice == 3) {
            cout << GREEN << BOLD << "Goodbye! Created by Aashir Ali - SE2\n" << RESET;
            return 0;
        } else {
            cout << RED << BOLD << "Invalid choice! Try again.\n" << RESET;
        }
    }
}
