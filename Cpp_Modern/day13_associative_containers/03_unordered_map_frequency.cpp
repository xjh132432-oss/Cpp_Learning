#include<iostream>
#include<unordered_map>
#include<string>

int main()
{
    std::vector<std::string> words{
    "apple", "banana", "apple",
    "orange", "banana", "apple"
    };

    std::unordered_map<std::string,int> frequency;
    for(auto x:words)
    {
        frequency[x]++;
    }

    for(auto x:frequency)
    {
        std::cout<<x.first<<" "<<x.second<<'\n';
    }

    std::cout<<"------------------------"<<'\n';
    
    std::cout<<frequency["apple"]<<'\n';

    frequency.erase("orange");

    for(auto x:frequency)
    {
        std::cout<<x.first<<" "<<x.second<<'\n';
    }

    return 0;
}