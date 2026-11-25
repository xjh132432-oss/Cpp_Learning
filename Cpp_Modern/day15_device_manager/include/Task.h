#include "Device.h"
#include<functional>

class Task {
public:
    Task(
        std::string name,
        std::weak_ptr<Device> device,
        std::function<void(Device&)> callback
    );

    void execute() const;

private:
    std::string name;
    std::weak_ptr<Device> device;
    std::function<void(Device&)> callback;
};
