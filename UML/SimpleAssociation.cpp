// Simple assocaition means that one class is connected with the another class but not with the strong ownership
// Exmple Teacher -> Teaches the Student

#include <bits/stdc++.h>
using namespace std;

class Student{
private:
    string name;
public:
    Student(string name) : name(name){}
    void display(){
        cout<<this->name<<" ";
    }
};

class Teacher{
private:
    vector<Student*>student;
    string teacherName;
public:

    Teacher(string name):teacherName(name){} // Constructor

    void displayTeacherName(){cout<<this->teacherName<<endl;}

    void addStudent(Student *student){
        this->student.push_back(student);
    }

    void showStudents() {
        cout << "Teacher: " << teacherName << " teaches:" << endl;
        for (auto s : student) {
            s->display();
        }
    }
};

int main()
{
    Student *s1 = new Student("Ankur");
    Student *s2 = new Student("Hitesh");
    Teacher *t1 = new Teacher("Mr.Sharma");

    t1->addStudent(s1) , t1->addStudent(s2);
    t1->displayTeacherName() , t1->showStudents();
}