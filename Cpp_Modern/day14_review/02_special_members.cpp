#include<iostream>
#include<string>

class Student{

    public:

        std::string name;

        Student(const std::string& n) : name(n){
            std::cout<<"default constructor student\n";
            
        }

        Student(const Student& other) : name(other.name)
        {
            
            std::cout<<"Copy Constructor\n";
        }

        Student(Student&& other) noexcept
        {
            this->name=std::move(other.name);
            std::cout << "Move Constructor\n";
        }

        Student& operator=(const Student& other){
            this->name=other.name;
            std::cout<<"Copy Assignment\n";
            return *this;
        }

        Student& operator=(Student&& other) noexcept
        {
            this->name=std::move(other.name);
            std::cout << "Move Assignment\n";
            return *this;
        }

        ~Student(){
            std::cout<<"Desturctor:"<<name<<'\n';
        }
    

};

int main()
{
    Student a("Alice");

    std::cout<<"----------A copy constructor B-----------\n'";
    Student b=a;

    Student c("Charlie");

    std::cout<<"----------A copy Assignment c-----------\n'";
    c=a;

    std::cout<<"----------A move constructor D-----------\n'";
    Student d=std::move(a);

    std::cout<<"----------A move Assignment c-----------\n'";
    c=std::move(d);

    std::cout<<"A:"<<a.name<<'\n';
    std::cout<<"B:"<<b.name<<'\n';
    std::cout<<"C:"<<c.name<<'\n';
    std::cout<<"D:"<<d.name<<'\n';

    return 0;
}