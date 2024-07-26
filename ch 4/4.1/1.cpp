#include <iostream>
#include <string.h>
using namespace std;

class Student
{
private:
        int  stu_id;
        char stu_name[20];
        int  stu_age;
        char stu_course[20];
        char stu_city[20];
        char stu_email[20];
        char stu_college[20];

public:

       //setter
       void setData(int stu_id,
        char stu_name[],
        int  stu_age,
        char stu_course[],      
        char stu_city[],
        char stu_email[],
        char stu_college[])
       {
                this->stu_id = stu_id;
                strcpy(this->stu_name,stu_name);
                this->stu_age = stu_age;
                strcpy(this->stu_course,stu_course);
                strcpy(this->stu_city,stu_city);
                strcpy(this->stu_email,stu_email);
                strcpy(this->stu_college,stu_college);
       }
       //getter
       void getData()
       {
        cout << "Id => " << this-> stu_id << "Name => " << this->stu_name << "Age => " << this->stu_age
        << "Course => " << this-> stu_course << "City => " << this->stu_city << "Email => " << this->stu_email <<
        "College => " << this->stu_college << endl;
       }
};

int main()
{
    Student s1,s2,s3,s4,s5;

    s1.setData(101,"vraj dholariya",18,"B.tech","surat","vrajdholariya@gmail.com","nirma");
    s2.setData(102,"ansh satasiya",18,"B.tech","surat","xyz@gmail.com","nirma");
    s3.setData(103,"henil moradiya",18,"B.tech","surat","abc@gmail.com","nirma");
    s4.setData(104,"zeel patel",18,"B.tech","surat","pqr@gmail.com","nirma");
    s5.setData(105,"prit rakholiya",18,"B.tech","surat","vwx@gmail.com","nirma");
         
         //strcpy(s1.stu_name,"raj");
    s1.getData();
    s2.getData();
    s3.getData();
    s4.getData();
    s5.getData();
}