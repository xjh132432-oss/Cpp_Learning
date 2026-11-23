#include "Device.h"

int main()
{
    Device a(1,"a",25.2);
    Device b(2,"b",25.2);

    std::cout<<"id:"<<a.getId()<<'\n'
            <<"name:"<<a.getName()<<'\n'
            <<"temperature:"<<a.getTemperature()<<'\n'
            <<"onlice:"<<a.isOnline()<<'\n';

    std::cout<<"id:"<<b.getId()<<'\n'
            <<"name:"<<b.getName()<<'\n'
            <<"temperature:"<<b.getTemperature()<<'\n'
            <<"onlice:"<<b.isOnline()<<'\n';

    return 0;
}