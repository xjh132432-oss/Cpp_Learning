#include<string>
#include<vector>
#include<iostream>
#include<algorithm>

class Student{
    public:
        std::string name;
        int score;

    Student(const std::string& name,const int& score)
    : name(name),score(score) {};
};

int main()
{
    std::vector<Student> students{{"Alice",80},
                    {"Bob",85},
                    {"Mike",90},
                    {"Charile",70},
                    {"Marry",95}};

    std::for_each(students.begin(),students.end(),
    [](const Student& x){
        std::cout<<x.name<<" :"<<x.score<<'\n';
    });
    
    std::cout<<"-----------find-------------\n";

    int score=90;
    auto it=std::find_if(students.begin(),students.end(),
    [score](const Student& x){
        return x.score>=score;
    });

    if (it != students.end())
    {
        std::cout<<"first greater than 90:"<<it->name<<'\n';
    }
    
    std::cout<<"------------pass count------------\n";

    int pass=60;
    int count=0;
    count=std::count_if(students.begin(),students.end(),
    [pass](const Student& x){
        return x.score>=pass;
    });

    std::cout<<"pass count:"<<count<<'\n';

    std::cout<<"-------------plus 5---------------\n";

    int threshold=85;
    std::for_each(students.begin(),students.end(),
    [&threshold](Student& x){
        if(x.score>threshold)
        x.score+=5;
    });

    std::for_each(students.begin(),students.end(),
    [](const Student& x){
        std::cout<<x.name<<" :"<<x.score<<'\n';
    });

    std::cout<<"---------------sort------------\n";

    std::sort(students.begin(),students.end(),
    [](const Student& a,const Student& b){
        return a.score>b.score;
    });

    std::for_each(students.begin(),students.end(),
    [](const Student& x){
        std::cout<<x.name<<" :"<<x.score<<'\n';
    });

    return 0;
}