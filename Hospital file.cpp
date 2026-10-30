#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Patient class to encapsulate patient details
class Patient {
private:
    int patientID;
    string name;
    int age;
    string disease;

public:
    // Constructor
    Patient(int id, string n, int a, string d) {
        patientID = id;
        name = n;
        age = a;
        disease = d;
    }

    // Getters
    int getID() { return patientID; }
    string getName() { return name; }
    int getAge() { return age; }
    string getDisease() { return disease; }

    // Display single patient profile
    void displayPatient() {
        cout << "\n-----------------------------------" << endl;
        cout << "Patient ID: " << patientID << endl;
        cout << "Name:       " << name << endl;
        cout << "Age:        " << age << endl;
        cout << "Condition:  " << disease << endl;
        cout << "-----------------------------------" << endl;
    }
};

// Hospital Management Controller Class
class Hospital {
private:
    vector<Patient> patients;

public:
    // 1. Register a new patient
    void registerPatient() {
        int id, age;
        string name, disease;

        cout << "\nEnter Patient ID (Numbers only): ";
        cin >> id;
        cin.ignore();
        cout << "Enter Patient Name: ";
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cin.ignore();
        cout << "Enter Current Symptoms/Disease: ";
        getline(cin, disease);

        Patient newPatient(id, name, age, disease);
        patients.push_back(newPatient);
        cout << "\n[Success] Patient registered successfully!" << endl;
    }

    // 2. View all admitted/registered patients
    void viewAllPatients() {
        if (patients.empty()) {
            cout << "\n[Info] No current patient records found." << endl;
            return;
        }

        cout << "\n====== CURRENT PATIENT DATABASE ======" << endl;
        for (int i = 0; i < patients.size(); i++) {
            patients[i].displayPatient();
        }
    }

    // 3. Discharge or Search patient by ID
    void searchPatient() {
        if (patients.empty()) {
            cout << "\n[Info] Database is empty." << endl;
            return;
        }

        int id;
        cout << "\nEnter Patient ID to search: ";
        cin >> id;

        for (int i = 0; i < patients.size(); i++) {
            if (patients[i].getID() == id) {
                cout << "\n[Record Found] Details below:";
                patients[i].displayPatient();
                return;
            }
        }
        cout << "\n[Error] Patient with ID " << id << " not found." << endl;
    }
};

int main() {
    Hospital system;
    int choice;

    while (true) {
        cout << "\n=========================================" << endl;
        cout << "     HOSPITAL MANAGEMENT SYSTEM (C++)    " << endl;
        cout << "=========================================" << endl;
        cout << "1. Register New Patient" << endl;
        cout << "2. View Admitted Patients List" << endl;
        cout << "3. Search Patient by ID" << endl;
        cout << "4. Exit Application" << endl;
        cout << "Academic Status: 3rd Semester (ADP CS)" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                system.registerPatient();
                break;
            case 2:
                system.viewAllPatients();
                break;
            case 3:
                system.searchPatient();
                break;
            case 4:
                cout << "\nExiting system. Stay safe and healthy!" << endl;
                return 0;
            default:
                cout << "\n[Invalid Choice] Please select between 1 and 4." << endl;
        }
    }
    return 0;
}
