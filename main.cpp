#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Student
{
public:
    int id;
    string name;
    string course;
    float marks;
};

// Save students to file
void saveStudents(vector<Student>& students)
{
    ofstream file("students.txt");

    for (int i = 0; i < students.size(); i++)
    {
        file << students[i].id << endl;
        file << students[i].name << endl;
        file << students[i].course << endl;
        file << students[i].marks << endl;
    }

    file.close();
}

// Load students from file
void loadStudents(vector<Student>& students)
{
    ifstream file("students.txt");

    Student s;

    while (file >> s.id)
    {
        file.ignore();

        getline(file, s.name);
        getline(file, s.course);
        file >> s.marks;

        students.push_back(s);
    }

    file.close();
}

// Add student
void addStudent(vector<Student>& students)
{
    Student s;

    cout << "\nEnter Student ID: ";
    cin >> s.id;

    cout << "Enter Name: ";
    cin >> s.name;

    cout << "Enter Course: ";
    cin >> s.course;

    cout << "Enter Marks: ";
    cin >> s.marks;

    students.push_back(s);

    saveStudents(students);

    cout << "\nStudent added successfully!\n";
}

// Display students
void displayStudents(vector<Student>& students)
{
    if (students.empty())
    {
        cout << "\nNo students found.\n";
        return;
    }

    cout << "\n===== STUDENT RECORDS =====\n";

    for (int i = 0; i < students.size(); i++)
    {
        cout << "\nStudent ID: " << students[i].id;
        cout << "\nName: " << students[i].name;
        cout << "\nCourse: " << students[i].course;
        cout << "\nMarks: " << students[i].marks;
        cout << "\n-------------------------\n";
    }
}

// Search student
void searchStudent(vector<Student>& students)
{
    int id;

    cout << "\nEnter Student ID to search: ";
    cin >> id;

    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].id == id)
        {
            cout << "\nStudent Found!\n";
            cout << "Name: " << students[i].name << endl;
            cout << "Course: " << students[i].course << endl;
            cout << "Marks: " << students[i].marks << endl;

            return;
        }
    }

    cout << "\nStudent not found.\n";
}

// Update student
void updateStudent(vector<Student>& students)
{
    int id;

    cout << "\nEnter Student ID to update: ";
    cin >> id;

    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].id == id)
        {
            cout << "Enter New Name: ";
            cin >> students[i].name;

            cout << "Enter New Course: ";
            cin >> students[i].course;

            cout << "Enter New Marks: ";
            cin >> students[i].marks;

            saveStudents(students);

            cout << "\nStudent updated successfully!\n";

            return;
        }
    }

    cout << "\nStudent not found.\n";
}

// Delete student
void deleteStudent(vector<Student>& students)
{
    int id;

    cout << "\nEnter Student ID to delete: ";
    cin >> id;

    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].id == id)
        {
            students.erase(students.begin() + i);

            saveStudents(students);

            cout << "\nStudent deleted successfully!\n";

            return;
        }
    }

    cout << "\nStudent not found.\n";
}

int main()
{
    vector<Student> students;

    // Load saved data when program starts
    loadStudents(students);

    int choice;

    do
    {
        cout << "\n===== STUDENT MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            addStudent(students);
        }
        else if (choice == 2)
        {
            displayStudents(students);
        }
        else if (choice == 3)
        {
            searchStudent(students);
        }
        else if (choice == 4)
        {
            updateStudent(students);
        }
        else if (choice == 5)
        {
            deleteStudent(students);
        }
        else if (choice == 6)
        {
            cout << "\nProgram ended.\n";
        }
        else
        {
            cout << "\nInvalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}
