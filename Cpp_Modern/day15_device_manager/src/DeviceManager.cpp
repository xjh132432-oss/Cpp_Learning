#include "DeviceManager.h"

DeviceManager::DeviceManager()
    : logFile("log.txt", std::ios::app)
{}

std::weak_ptr<Device> DeviceManager::addDevice(
        int id,
        const std::string& name,
        double temperature
    ){  
    

        auto it=std::find_if(devices.begin(),devices.end(),[&id](const auto& p){
            return (*p).getId()==id;
        });

        if(it!=devices.end())
        {
             logFile<<"<WARN>\tAdd Device\tId Already Exists:\t"<<id<<'\n';
            
             return {};
        }
        else{
            auto device=std::make_shared<Device> (id,name,temperature);

            devices.push_back(device);

            std::weak_ptr<Device> weak=device;

            logFile<<"<INFO>\tAdd Device\tSuccessful Id:\t"<<id<<'\n';
            
            return weak;
        }
        
    }

    bool DeviceManager::removeDevice(int id){
        
        auto it=std::find_if(devices.begin(),devices.end(),[&id](const auto& p){
            return (*p).getId()==id;
        });
        if(it!=devices.end())
        {
            devices.erase(it);

            logFile<<"<INFO>\tRemove Device\tSuccessful Id:\t"
                                <<id<<'\n';
            return true;
        }
        else{
            logFile<<"<WARN>\tRemove Device\tId dose not exists:"
                                <<id<<'\n';

            return false;
        }
    }

    std::weak_ptr<Device> DeviceManager::findDevice(int id) const
    {   

         auto it=std::find_if(devices.begin(),devices.end(),[&id](const auto& p){
            return p->getId()==id;
        });
        if(it!=devices.end()){
            
            return *it;
        }
        else{
            return {};
        }
        
    }

    void DeviceManager::printAll() const{

        std::cout<<"ID\tname\ttemperature\tonline\n";

        for(const auto& device:devices)
        {   
            
            std::cout<<device->getId()<<"\t"
                    <<device->getName()<<"\t"
                    <<device->getTemperature()<<"\t"
                    <<device->isOnline()<<'\n';
        }

    }

    void DeviceManager::filterByTemperature(double threshold) const{
        
        std::for_each(devices.begin(),devices.end(),
        [threshold](const auto& device){
            if(device->getTemperature()>threshold){
                
                std::cout << "overheat: "
                          << device->getId() << '\n';
            
            }
        });
    }

    std::size_t DeviceManager::countOnline() const{
        bool online=true;
        size_t count=0;
        count=std::count_if(devices.begin(),devices.end(),
    [&online](const auto& device){
        return (*device).isOnline()==online;
    });

    return count;

    }