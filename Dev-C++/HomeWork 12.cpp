#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
using namespace std;
class Student{
public:
    char name[51];
    int id;
    int age;
    float gpa;
    Student(const char*name,int id,int age,float gpa){
        strncpy(this->name,name,50);
        this->name[50]='\0';
        this->id=id;
        this->age=age;
        this->gpa=gpa;
    }
    Student(){
        name[0]='\0';
        id=0;
        age=0;
        gpa=0.0;
    }
    void display()const{
        cout<<"Name: "<<name<<", ID: "<<id<<", Age: "<<age<<", GPA: "<<gpa<<endl;
    }
};
class StudentDataManager{
private:
    vector<Student>students;
public:
    void add_student(){
        char name[51];
        int id;
        int age;
        float gpa;
        cout<<"Enter student's name (up to 50 characters): ";
        cin.ignore();
        cin.getline(name, 51);
        cout<<"Enter student's identification number: ";
        cin>>id;
        cout<<"Enter student's age: ";
        cin>>age;
        cout<<"Enter student's GPA: ";
        cin>>gpa;
        students.push_back(Student(name,id,age,gpa));
        cout<<"Student "<<name<<" added successfully."<<endl;
    }
    void print_student_list()const{
        if(students.empty()){
            cout<<"No students to display."<<endl;
            return;
        }
        for(size_t i=0;i<students.size();i++){
            students[i].display();
        }
    }
    void save_data_to_file(const string&filename)const{
        ofstream outFile(filename.c_str(),ios::binary);
        if(!outFile){
            cerr<<"Error opening file for writing: "<<filename<<endl;
            return;
        }
        size_t size=students.size();
        outFile.write(reinterpret_cast<const char*>(&size),sizeof(size));
        for(size_t i=0;i<students.size();i++){
            outFile.write(reinterpret_cast<const char*>(&students[i]),sizeof(Student));
        }
        outFile.close();
        cout<<"Data saved to "<<filename<<" successfully."<<endl;
    }
    void load_data_from_file(const string&filename){
        ifstream inFile(filename.c_str(),ios::binary);
        if(!inFile){
            cerr<<"Error opening file for reading: "<<filename<<endl;
            return;
        }
        size_t size;
        inFile.read(reinterpret_cast<char*>(&size), sizeof(size));
        students.clear();
        for(size_t i=0;i<size;i++){
            Student student;
            inFile.read(reinterpret_cast<char*>(&student),sizeof(Student));
            students.push_back(student);
        }
        inFile.close();
        cout<<"Data loaded from "<<filename<<" successfully."<<endl;
    }
};
int main(){
    StudentDataManager manager;
    int choice;
    string filename;
    while(true){
        cout<<"\n1. Add Student"<<endl;
        cout<<"2. Print Student List"<<endl;
        cout<<"3. Save Data to File"<<endl;
        cout<<"4. Load Data from File"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                manager.add_student();
                break;
            case 2:
                manager.print_student_list();
                break;
            case 3:
                cout<<"Enter filename to save data: ";
                cin>>filename;
                manager.save_data_to_file(filename);
                break;
            case 4:
                cout<<"Enter filename to load data from: ";
                cin>>filename;
                manager.load_data_from_file(filename);
                break;
            case 5:
                return 0;
            default:
                cout<<"Invalid choice. Please try again."<<endl;
        }
    }
}
