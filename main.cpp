#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student
{
public:
    int id;
    string name;
    string course;
    float marks;
};

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

    cout << "\nStudent added successfully!\n";
}

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

int main()
{
    vector<Student> students;

    int choice;

    do
    {
        cout << "\n===== STUDENT MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Exit\n";

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
            cout << "\nProgram ended.\n";
        }
        else
        {
            cout << "\nInvalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
