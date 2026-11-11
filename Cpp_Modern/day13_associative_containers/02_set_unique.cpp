#include<iostream>
#include<set>

int main()
{
    std::set<int> student{1,2,3,4,5};

    student.insert(9);
    student.insert(1);

    auto it = student.find(3);

    if (it != student.end())
    {
        std::cout << "Found: " << *it << '\n';
    }
    else
    {
        std::cout << "Not found\n";
    }

    student.erase(3);

    for(auto it=student.begin();it!=student.end();++it)
    {
        std::cout<<*it<<'\t';
    }

    return 0;
}