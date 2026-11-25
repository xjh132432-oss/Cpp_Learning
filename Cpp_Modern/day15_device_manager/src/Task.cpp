#include "Task.h"

Task::Task(
        std::string name,
        std::weak_ptr<Device> device,
        std::function<void(Device&)> callback
    ) :
    name(std::move(name)),
    device(std::move(device)),
    callback(std::move(callback))
    {}

void Task::execute() const
{
    if(!callback)
    {
        return;
    }
    
    auto DevicePtr=device.lock();

    if(!DevicePtr)
    {
        std::cout<<"This Device Does Not Exists\n";
        return;
    }

    callback(*DevicePtr);
}