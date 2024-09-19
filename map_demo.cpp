#include <iostream>
#include <map>
#include <string>

using namespace std;

// Function prototypes
void displayMenu();
void addDepartment(map<string, string>& campusMap);
void removeDepartment(map<string, string>& campusMap);
void queryDepartment(const map<string, string>& campusMap);

int main() {
    // Create a map from departments to buildings
    map<string, string> campusMap = {
        {"Mathematics", "Ransom Hall"},
        {"Computer Science", "Sam Mather Hall"},
        {"Biology", "Olin Science Center"},
        {"Physics", "Hunt Hall"},
        {"Chemistry", "Hunt Hall"}
    };

    int choice;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore newline character left in the input buffer

        switch (choice) {
            case 1:
                addDepartment(campusMap);
                break;
            case 2:
                removeDepartment(campusMap);
                break;
            case 3:
                queryDepartment(campusMap);
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}

void displayMenu() {
    cout << "\n--- College Campus Map Menu ---\n";
    cout << "1. Add Department\n";
    cout << "2. Remove Department\n";
    cout << "3. Query Department\n";
    cout << "4. Exit\n";
}

void addDepartment(map<string, string>& campusMap) {
    string department, building;
    cout << "Enter the department name: ";
    getline(cin, department);
    cout << "Enter the building name: ";
    getline(cin, building);

    // Add or update the mapping
    campusMap[department] = building;
    cout << "Department added/updated successfully." << endl;
}

void removeDepartment(map<string, string>& campusMap) {
    string department;
    cout << "Enter the department name to remove: ";
    getline(cin, department);

    auto it = campusMap.find(department);
    if (it != campusMap.end()) {
        campusMap.erase(it);
        cout << "Department removed successfully." << endl;
    } else {
        cout << "Department not found." << endl;
    }
}

void queryDepartment(const map<string, string>& campusMap) {
    string department;
    cout << "Enter the department name to query: ";
    getline(cin, department);

    auto it = campusMap.find(department);
    if (it != campusMap.end()) {
        cout << "Department " << department << " is located in " << it->second << "." << endl;
    } else {
        cout << "Department not found." << endl;
    }
}
