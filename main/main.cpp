#include <iostream>
using namespace std;
struct Student {
    string name;
    int age;
    bool scolarship;

};

Student create_student(string name,int age,bool scolarship) {
    Student student;
    student.name = name;
    student.age = age;
    student.scolarship = scolarship;
    return student;
}

void print_student(Student student) {
    cout<<"Name: "<<student.name<<endl;
    cout<<"Age: "<<student.age<<endl;
    cout<<"Scolarship: "<<student.scolarship<<endl;
    cout<<endl;
}

int main() {



    Student student = create_student("Student",10,true);
    print_student(student);

    Student student2[3] = {
        create_student("Denys " , 18 , false),
           create_student("Zhenya " , 18 , false),
           create_student("Vania" , 18 , true )
    };
    for (int i=0;i<3;i++) {
        print_student(student2[i]);
    }


    return 0;
}
