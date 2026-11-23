#include "Device.h"

Device::Device(int id,std::string name,
    double temperature)
{
    this->id=id;
    this->name=name;
    this->temperature=temperature;
}

int Device::getId() const{
    return id;
}

const std::string& Device::getName() const{
    return name;
}

double Device::getTemperature() const{
    return temperature;
}

bool Device::isOnline() const{
    return online;
}

void Device::setTemperature(double other)
{
    this->temperature=other;
}

void Device::setOnline(bool other)
{
    this->online=other;
}