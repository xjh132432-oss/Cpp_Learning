#include "DeviceManager.h"
#include "TaskScheduler.h"

int main()
{

    DeviceManager devices;

    devices.addDevice(1,"a",25.2);
    devices.addDevice(2,"b",35.2);;


    std::function<void(Device&)> f=[](Device& x){
        x.setTemperature(50);
    };
    
    std::weak_ptr<Device> weak=devices.findDevice(1);

    Task task1("a",weak,f);

    task1.execute();

    std::cout<<"temperature:"<<(*weak.lock()).getTemperature()
    <<'\n';

    devices.removeDevice(1);
    if(weak.expired())
    {
        std::cout<<"not exists\n";
    }
    else{
        std::cout<<"exists\n";
    }

    task1.execute();

    std::weak_ptr<Device> weak2=devices.findDevice(2);

    if(!weak2.lock()){
    std::cout << "Device 2 does not exist\n";
    return 1;
    }

    std::function<void(Device&)> f2 = [](Device& x){
    x.setTemperature(x.getTemperature() + 5);
    };

    std::function<void(Device&)> f3 = [](Device& x){
        x.setTemperature(x.getTemperature() + 10);
    };

    Task task2("b",weak2,f2);
    Task task3("c",weak2,f3);
    TaskScheduler scheduler;


    scheduler.addTask(std::move(task1));
    scheduler.addTask(std::move(task2));
    scheduler.addTask(std::move(task3));


    std::cout << "-----------run all tasks-----------\n";
    scheduler.runAll();

    if(auto device = weak2.lock()){
        std::cout << "temperature: "
                << device->getTemperature() << '\n';
    }

    return 0;
}