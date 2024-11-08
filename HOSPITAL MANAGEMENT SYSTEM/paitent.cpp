 #include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Patient {
    string name;
    int age;
    string gender;
    string address;
    string disease;
    string doctor;
    string admissionDate;
    string dischargeDate;
    bool isDischarged;
};

void addPatient(vector<Patient>& patients);
void displayPatients(const vector<Patient>& patients);
void searchPatient(const vector<Patient>& patients);
void updatePatient(vector<Patient>& patients);
void dischargePatient(vector<Patient>& patients);
void savePatientsToFile(const vector<Patient>& patients, const string& filename);
vector<Patient> loadPatientsFromFile(const string& filename);

int main() {
    vector<Patient> patients = loadPatientsFromFile("patients.txt"); // Load patients from file

    int choice;
    do {
        cout << "\nHospital Management System\n";
        cout << "1. Add Patient\n";
        cout << "2. Display Patients\n";
        cout << "3. Search Patient\n";
        cout << "4. Update Patient\n";
        cout << "5. Discharge Patient\n";
        cout << "6. Exit\n";
        cout << "Enter your choice :  ";
        cin >> choice;

        switch (choice) {
            case 1:
            

    addPatient(patients);
                break;
            case 2:
                displayPatients(patients);
                break;
            case 3:
                searchPatient(patients);
                break;
            case 4:
                updatePatient(patients);
                break;
            case 5:
                dischargePatient(patients);
                break;
            case 6:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    savePatientsToFile(patients, "patients.txt"); 

    return 0;
}


void addPatient(vector<Patient>& patients) {
    Patient newPatient;
    cout << "\nEnter Patient Details:\n";
    cout << "Name: ";
    cin.ignore(); 
    getline(cin, newPatient.name);
    cout << "Age: ";
    cin >> newPatient.age;
    cout << "Gender: ";
    cin.ignore();
    getline(cin, newPatient.gender);
    cout << "Address: ";
    getline(cin, newPatient.address);
    cout << "Disease: ";
    getline(cin, newPatient.disease);
    cout << "Doctor: ";
    getline(cin, newPatient.doctor);
    cout << "Admission Date (YYYY-MM-DD): ";
    getline(cin, newPatient.admissionDate);
    newPatient.isDischarged = false;
    newPatient.dischargeDate = "";

    

patients.push_back(newPatient);
    cout << "Patient added successfully!\n";
}


void displayPatients(const vector<Patient>& patients) {
    if (patients.empty()) {
        cout << "No patients found.\n";
        return;
    }

    cout << "\nPatient Records:\n";
    cout << "-------------------------------------------------------------------------------------\n";
    cout << left << setw(15) << "Name" 
         << setw(5) << "Age" 
         << setw(10) << "Gender" 
         << setw(20) << "Address" 
         << setw(15) << "Disease" 
         << setw(15) << "Doctor" 
         << setw(15) << "Admission Date" 
         << setw(15) << "Discharge Date" 
         << setw(15) << "Status\n";
    cout << "-------------------------------------------------------------------------------------\n";

    for (const auto& patient : patients) {
        cout << left << setw(15) << patient.name 
             << setw(5) << patient.age 
             << setw(10) << patient.gender 
             << setw(20) << patient.address 
             << setw(15) << patient.disease 
             << setw(15) << patient.doctor 
             << setw(15) << patient.admissionDate 
             << setw(15) << patient.dischargeDate 
             << setw(15) << (patient.isDischarged ? "Discharged" : "Admitted") << endl;
    }
    cout << "-------------------------------------------------------------------------------------\n";
}


void searchPatient(const vector<Patient>& patients) {
    string searchName;
    cout << "Enter patient name to search: ";
    cin.ignore();
    getline(cin, searchName);

    bool found = false;
    for (const auto& patient : patients) {
        if (patient.name == searchName) {
            


cout << "\nPatient Found:\n";
            cout << "-------------------------------------------------------------------------------------\n";
            cout << left << setw(15) << "Name" 
                 << setw(5) << "Age" 
                 << setw(10) << "Gender" 
                 << setw(20) << "Address" 
                 << setw(15) << "Disease" 
                 << setw(15) << "Doctor" 
                 << setw(15) << "Admission Date" 
                 << setw(15) << "Discharge Date" 
                 << setw(15) << "Status\n";
            cout << "-------------------------------------------------------------------------------------\n";
            cout << left << setw(15) << patient.name 
                 << setw(5) << patient.age 
                 << setw(10) << patient.gender 
                 << setw(20) << patient.address 
                 << setw(15) << patient.disease 
                 << setw(15) << patient.doctor 
                 << setw(15) << patient.admissionDate 
                 << setw(15) << patient.dischargeDate 
                 << setw(15) << (patient.isDischarged ? "Discharged" : "Admitted") << endl;
            cout << "-------------------------------------------------------------------------------------\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Patient not found.\n";
    }
}


void updatePatient(vector<Patient>& patients) {
    string updateName;
    cout << "Enter patient name to update: ";
    cin.ignore();
    getline(cin, updateName);

    bool found = false;
    for (auto& patient : patients) {
        if (patient.name == updateName) {
            cout << "\nEnter updated details:\n";
            cout << "Name (leave blank to keep current): ";
            getline(cin, updateName);
            if (!updateName.empty()) {
                patient.name = updateName;
            }
      


      cout << "Age (leave blank to keep current): ";
            string ageInput;
            getline(cin, ageInput);
            if (!ageInput.empty()) {
                patient.age = stoi(ageInput);
            }
            cout << "Gender (leave blank to keep current): ";
            getline(cin, updateName);
            if (!updateName.empty()) {
                patient.gender = updateName;
            }
            cout << "Address (leave blank to keep current): ";
            getline(cin, updateName);
            if (!updateName.empty()) {
                patient.address = updateName;
            }
            cout << "Disease (leave blank to keep current): ";
            getline(cin, updateName);
            if (!updateName.empty()) {
                patient.disease = updateName;
            }
            cout << "Doctor (leave blank to keep current): ";
            getline(cin, updateName);
            if (!updateName.empty()) {
                patient.doctor = updateName;
            }
            cout << "Admission Date (YYYY-MM-DD, leave blank to keep current): ";
            getline(cin, updateName);
            if (!updateName.empty()) {
                patient.admissionDate = updateName;
            }
            cout << "Discharge Date (YYYY-MM-DD, leave blank to keep current): ";
            getline(cin, updateName);
            if (!updateName.empty()) {
                patient.dischargeDate = updateName;
            }
            cout << "Patient details updated successfully!\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Patient not found.\n";
    }
}





void dischargePatient(vector<Patient>& patients) {
    string dischargeName;
    cout << "Enter patient name to discharge: ";
    cin.ignore();
    getline(cin, dischargeName);

    bool found = false;
    for (auto& patient : patients) {
        if (patient.name == dischargeName) {
            if (patient.isDischarged) {
                cout << "Patient is already discharged!\n";
            } else {
                cout << "Enter discharge date (YYYY-MM-DD): ";
                getline(cin, patient.dischargeDate);
                patient.isDischarged = true;
                cout << "Patient discharged successfully.\n";
            }
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Patient not found.\n";
    }
}


void savePatientsToFile(const vector<Patient>& patients, const string& filename) {
    ofstream outfile(filename);
    if (outfile.is_open()) {
        for (const auto& patient : patients) {
            outfile << patient.name << ","
                    << patient.age << ","
                    << patient.gender << ","
                    << patient.address << ","
                    << patient.disease << ","
                    << patient.doctor << ","
                    << patient.admissionDate << ","
                    << patient.dischargeDate << ","
                    << patient.isDischarged << endl;
        }
        outfile.close();
        cout << "Patient data saved to file.\n";
    } else {
        cout << "Error opening file for saving.\n";
    }
}


vector<Patient> loadPatientsFromFile(const string& filename) {
    vector<Patient> patients;
    ifstream infile(filename);
    if (infile.is_open()) {
        string line;
        while (getline(infile, line)) {
            Patient patient;
            size_t pos = 0;
            string token;

            pos = line.find(',');
            patient.name = line.substr(0, pos);
            line = line.substr(pos + 1);

            pos = line.find(',');
            patient.age = stoi(line.substr(0, pos));
            line = line.substr(pos + 1);

            pos = line.find(',');
            patient.gender = line.substr(0, pos);
            line = line.substr(pos + 1);

            pos = line.find(',');
            patient.address = line.substr(0, pos);
            line = line.substr(pos + 1);

            pos = line.find(',');
            patient.disease = line.substr(0, pos);
            line = line.substr(pos + 1);

            pos = line.find(',');
            patient.doctor = line.substr(0, pos);
            line = line.substr(pos + 1);

            pos = line.find(',');
            patient.admissionDate = line.substr(0, pos);
            line = line.substr(pos + 1);

            pos = line.find(',');
            patient.dischargeDate = line.substr(0, pos);
            line = line.substr(pos + 1);

            patient.isDischarged = (line == "1");

            patients.push_back(patient);
        }
        infile.close();
        cout << "Patient data loaded from file.\n";
    } else {
     


   cout << "Error opening file for loading.\n";
    }
    return patients;
}
