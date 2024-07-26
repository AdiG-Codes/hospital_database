
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

class Person {
public:
    string name;
    int age;
    char gender;
    double phone;
    string disease;

    // Default constructor
    Person() : name(""), age(0), gender(' '), phone(0.0), disease("") {}
};

class Doctor : public Person {
public:
    string type;

    Doctor() : type("") {}

    Doctor(const string& docName, double docPhone, const string& docType)
        : type(docType) {
        name = docName;
        phone = docPhone;
    }

    void displayDoctorInfo() {
        cout << "Doctor Name: " << name << "\nPhone: " << phone << "\nSpecialization: " << type << endl;
    }

   
    bool treatsDisease(const string& disease) const {
        return type == disease;
    }
};

class Patient : public Person {
public:
    string address;
    string bloodgrp;
    string assignedDoctorName;  
    Patient() :  address(""), bloodgrp(""), assignedDoctorName("") {}
};

class Clinic {
public:
    vector<Patient> patients;
    vector<Doctor> doctors;

    void addPatient(bool isCritical) {
        Patient p;
        cin.ignore();
        cout << "Enter patient name: "; getline(cin, p.name);
        cout << "Enter age: "; cin >> p.age;
        cout << "Enter gender: "; cin >> p.gender;
        cin.ignore();
        cout << "Enter address: "; getline(cin, p.address);
        cout << "Enter blood group: "; cin >> p.bloodgrp;

        
        do {
            cout << "Enter phone number: ";
            if (!(cin >> p.phone) || to_string(static_cast<long long>(p.phone)).length() != 10) {
                cout << "Invalid phone number. Please enter a 10-digit phone number." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                break;
            }
        } while (true);

        cout << "Enter patient's disease: "; cin >> p.disease;
        patients.push_back(p);
        cout << endl << "Patient added successfully. Enter next choice:\n";
    }
    void displayPatients() {
    cout << "Patient List:\n";
    cout << left << setw(20) << "Name" << setw(5) << "Age" << setw(20) << "Address"
         << setw(8) << "Gender" << setw(15) << "Phone" << setw(15) << "Blood Group"
         << setw(20) << "Disease" << endl;
    cout << setfill('-') << setw(135) << "-" << setfill(' ') << endl;

    cout << fixed << setprecision(0);
    for (const auto& patient : patients) {
        cout << left << setw(20) << patient.name 
             << setw(5) << patient.age << setw(20) << patient.address
             << setw(8) << patient.gender << setw(15) << patient.phone 
             << setw(15) << patient.bloodgrp << setw(20) << patient.disease << endl;
    }
    cout.unsetf(ios::fixed);
    cout << " DATA DISPLAYED IN TABLE, ENTER NEXT CHOICE\n";
}


    void displayDoctors() {
        cout << "Doctor List:\n";
        cout << left << setw(20) << "Name" << setw(15) << "Phone" << setw(20) << "Specialization" << endl;
        cout << setfill('-') << setw(55) << "-" << setfill(' ') << endl;

        cout << fixed << setprecision(0);
        for (const auto& doctor : doctors) {
            cout << left << setw(20) << doctor.name << setw(15) << doctor.phone << setw(20) << doctor.type << endl;
        }
        cout.unsetf(ios::fixed);
        cout<<endl;
        cout<<" DATA DISPLAYED IN TABLE,ENTER NEXT CHOICE\n";

    }

    

    
};

int main() {
    vector<Clinic> clinics{
        Clinic(), // General Clinic
        Clinic(), // Cardiologist Clinic
        Clinic(), // Lung Clinic
        Clinic(), // ENT Clinic
        Clinic()   // Surgeon
    };

    //  declared 5 doctors for each section.
    clinics[0].doctors.push_back(Doctor("Dr. Smith", 1234567890, "General Medicine"));
    clinics[1].doctors.push_back(Doctor("Dr. Johnson", 1234567891, "Cardiology"));
    clinics[2].doctors.push_back(Doctor("Dr. Wilson", 1234567892, "Pulmonology"));
    clinics[3].doctors.push_back(Doctor("Dr. Brown", 1234567893, "ENT"));
    clinics[4].doctors.push_back(Doctor("Dr. Davis", 1234567894, "Surgery"));

    int mainChoice;
    int clinicChoice;

    cout << endl << "|-o-|(^_^)(^_^)(^_^)(^_^)(^_^)(^_^)(^_^)(^_^)(^_^)|-o-|\n";
    cout << "|-o-|_____________APOLLO__________________________|-o-|\n";
    cout << "|-o-|____________________HOSPITAL_________________|-o-|\n";
    cout << "|-o-|___________________________PUNE______________|-o-|\n";
    cout << "|-o-|(^_^)(^_^)(^_^)(^_^)(^_^)(^_^)(^_^)(^_^)(^_^)|-o-|\n";

    do {
        cout << "*****our__hospital__departments*****\n";
        cout << endl << "---------Main_Menu---------\n";
        cout << "1: GENERAL CLINIC\n";
        cout << "2: CARDIOLOGIST CLINIC\n";
        cout << "3: LUNG CLINIC\n";
        cout << "4: ENT CLINIC\n";
        cout << "5: SURGEON\n";
        cout << "6: Exit\n\n";
        cout << "Enter your choice: "; cin >> mainChoice;

        if (mainChoice >= 1 && mainChoice <= 5) {
            Clinic& selectedClinic = clinics[mainChoice - 1];

            cout << "-------Clinic_Menu-------\n";
                cout << "1: Add  patient\n";
                cout << "3: Display patient list\n";
                cout << "5: Display doctor list\n";
                cout << "6: Exit\n\n";
                cout << "Enter your choice: "; 

            do {
                cin >> clinicChoice;

                switch (clinicChoice) {
                case 1: selectedClinic.addPatient(false); break;

                case 3: selectedClinic.displayPatients(); break;
                case 5: selectedClinic.displayDoctors(); break;
                case 6: break; // Exit clinic menu
                default: cout << "Invalid choice. Please enter a valid option.\n";
                }

            } while (clinicChoice != 6);
        }
        else if (mainChoice != 6) {
            cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (mainChoice != 6);

    cout << "Exiting Hospital Management System. Goodbye!\n";

    return 0;
}


 
 
 
 
 
 
 
 

 
 
 	  
 
 

