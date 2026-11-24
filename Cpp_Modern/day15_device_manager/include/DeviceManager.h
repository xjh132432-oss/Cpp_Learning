#pragma once
#include "Device.h"
#include<fstream>

class DeviceManager {
public:
    std::weak_ptr<Device> addDevice(
        int id,
        const std::string& name,
        double temperature
    );
    DeviceManager();

    bool removeDevice(int id);

    std::weak_ptr<Device> findDevice(int id) const;

    void printAll() const;

    void filterByTemperature(double threshold) const;

    std::size_t countOnline() const;

private:
    std::vector<std::shared_ptr<Device>> devices;
    std::ofstream logFile;
};