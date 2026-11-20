#include<memory>
#include<iostream>

struct Device{
    Device(){
        std::cout<<"Device creat"<<'\n';
    }
    ~Device(){
        std::cout<<"Device destoyed\n";
    }

};

int main(){
    
    std::unique_ptr<Device> a;
    auto b=std::make_unique<Device> ();

    std::cout<<"---------before move---------------\n";
    std::cout<<"a:"<<a.get()<<'\n';
    std::cout<<"b:"<<b.get()<<'\n';

    a=std::move(b);

    std::cout<<"---------after move---------------\n";
    std::cout<<"a:"<<a.get()<<'\n';
    std::cout<<"b:"<<b.get()<<'\n';

    auto c=std::make_shared<Device>();

    std::cout<<c.use_count()<<'\n';
    
    auto c2=c;
    
    std::cout<<c.use_count()<<'\n';

    std::weak_ptr<Device> w=c;

    std::cout<<"before reset:"<<w.expired()<<'\n';

    c.reset();
    c2.reset();

    std::cout<<"after reset:"<<w.expired()<<'\n';


    return 0;
}   