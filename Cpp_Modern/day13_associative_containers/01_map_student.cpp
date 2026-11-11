#include<iostream>
#include<map>
#include<string>

int main()
{
    std::map<int,std::string> students;

    students.insert({01,"Alice"});
    students.insert({02,"Bob"});
    students.insert({03,"Charile"});
    students.insert({04,"Mike"});

    std::cout<<"01:"<<students[01]<<'\n';

    
    std::cout<<"05:"<<students[05]<<'\n';

    students.erase(04);

    for(std::map<int,std::string>::iterator it=students.begin();
        it!=students.end();++it)
        {
            std::cout<<it->first<<'\t'<<it->second<<'\n';
        }
    
    
    return 0;
}