#pragma once
#include<memory>
#include<string>
#include<iostream>
#include<utility>

class Device {
public:
    Device(int id, std::string name, double temperature);

    int getId() const;
    const std::string& getName() const;
    double getTemperature() const;
    bool isOnline() const;

    void setTemperature(double temperature);
    void setOnline(bool online);

private:
    int id;
    std::string name;
    double temperature;
    bool online = true;
};