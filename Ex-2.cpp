#include <iostream>
#include <vector>
using std::cout, std::cin, std::endl;

/**
 * Create a simple student enrollment system using a menu.
 * 
 * You are given a pre-filled list of student names. Your program should allow the user
 * to manage this list by choosing options from a menu.
 * 
 * The program should support the following features:
 * 1. Add Student
 * 2. Remove Student
 * 3. Update Student
 * 4. Search Student
 * 5. Show All Students
 * 6. Show Total Students
 * 
 */

void addStudent(std::vector<std::string>& students) {
    std::string name;
    std::cin.ignore();
    std::cout << "Enter student name to add: ";
    std::getline(std::cin, name);
    
    /**
     * Add the entered student name from the user input into
     * the students vector and then display the succes message.
     */

    students.push_back(name);
    std::cout << name << " added to the list." << endl;
}

void searchStudent(const std::vector<std::string>& students) {
    std::string name;
    std::cin.ignore();
    std::cout << "Enter student name to search: ";
    std::getline(std::cin, name);

    /**
     * Search the student by name
     * - if found, show the position (e.g., "Student found at position X.")
     * - if not found, show "Student not found."
     * 
     * Use a loop or to check if the name exists in the vector
     */
    bool found = false;

    for (int i = 0; i < students.size(); i++) {
        if (name == students[i]) {
            found = true;
            cout << "Student found at position " << i + 1 << endl;
            break;
        }
    }
    if (!found) {
        cout << "Students not found." << endl;
    }
}

void removeStudent(std::vector<std::string>& students) {
    std::string name;
    std::cin.ignore();

    /**
     * Ask for the student name to remove from the list
     * - if found, show "Student removed successfully."
     * - if not found, show "Student not found."
     * 
     * Use a loop or to check if the name exists in the vector
     */
    std::cout << "Enter student name to remove: ";
    std::getline(std::cin, name);
    bool found = false;
    for (int i = 0; i < students.size(); i++) {
        if (name == students[i]) {
            students.erase(students.begin() + i);
            cout << name << " has been removed." << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Student not found. Request failed." << endl;
    }
    
}

void updateStudent(std::vector<std::string>& students) {
    std::string oldName, newName;
    std::cin.ignore();

    /**
     * Ask for the current student name to change and then check if the student
     * name exist. If found, ask for a new name and update the student’s name.
     */
    std::cout << "Enter student name that you want to update: ";
    std::getline(std::cin, oldName);
    bool found = false;
    for (int i = 0; i < students.size(); i++) {
        if (oldName == students[i]) {
            found = true;
            cout << "Enter NEW name for " << oldName << ":";
            std::getline(std::cin, newName);
            students[i] = newName;
            cout << oldName << " UPDATED to " << newName << "." << "Successfully." << endl;
            break;
        }
    }
    if (!found) {
        cout << "Student name not on the list. Request failed." << endl;
    }
}

void showAllStudents(const std::vector<std::string>& students) {
    /**
     * Check if the vector is empty
     * - If empty, show "No students enrolled yet."
     * Use a loop to print all student names with numbering
     * Example:
     * 1. Bunleap
     * 2. Deny
     */
    int size = students.size();
    if (size >= 1) {
        for (int i = 0; i < size; i++) {
            cout << i + 1 << ". " << students[i] << endl;
        }
    } else {
        cout << "No students enrolled yet.";
    }
}

void showTotalStudents(const std::vector<std::string>& students) {
    //  Show the number of students
    int size = students.size();
    cout << "Total: " << size << endl;
}

int main() {
    std::vector<std::string> students = {"Bunleap", "Deny", "Methy", "Seyha"};
    int choice; 

    do {
        std::cout << "\n===== Student Enrollment System =====\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. Remove Student\n";
        std::cout << "3. Update Student\n";
        std::cout << "4. Search Student\n";
        std::cout << "5. Show All Students\n";
        std::cout << "6. Show Total Students\n";
        std::cout << "0. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;

        switch (choice) {
            case 1: addStudent(students); break;
            case 2: removeStudent(students); break;
            case 3: updateStudent(students); break;
            case 4: searchStudent(students); break;
            case 5: showAllStudents(students); break;
            case 6: showTotalStudents(students); break;

            case 0: std::cout << "Exiting program. Goodbye!\n"; break;
            default: std::cout << "Invalid option. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}