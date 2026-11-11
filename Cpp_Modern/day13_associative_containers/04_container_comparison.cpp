#include<set>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<iostream>

int main()
{
    std::map<int,std::string> mp;
    std::set<int> st;
    std::unordered_map<int,std::string> unmp;
    std::unordered_set<int> unst;

    mp.insert({1,"a"});
    mp.insert({3,"b"});
    mp.insert({2,"c"});
    mp.insert({6,"d"});

    unmp.insert({1,"a"});
    unmp.insert({3,"b"});
    unmp.insert({2,"c"});
    unmp.insert({6,"d"});

    st.insert(1);
    st.insert(3);
    st.insert(2);
    st.insert(6);

    unst.insert(1);
    unst.insert(3);
    unst.insert(2);
    unst.insert(6);

    std::cout<<"------------mp--------"<<'\n';
    for(auto x:mp)
    {
        std::cout<<x.first<<" "<<x.second<<'\n';
    }

    std::cout<<"------------unmp--------"<<'\n';
    for(auto x:unmp)
    {
        std::cout<<x.first<<" "<<x.second<<'\n';
    }

    std::cout<<"------------st--------"<<'\n';
    for(auto x:st)
    {
        std::cout<<x<<'\n';
    }

    std::cout<<"------------unst--------"<<'\n';
    for(auto x:unst)
    {
        std::cout<<x<<'\n';
    }
    
    return 0;
}