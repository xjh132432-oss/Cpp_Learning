cmake_minimum_required(VERSION 3.20)

project(Device_manager)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(main src/main.cpp)

add_library(Device_lib STATIC 
    src/Device.cpp
    src/DeviceManager.cpp
    src/Task.cpp
    src/TaskScheduler.cpp
)

target_include_directories(Device_lib PUBLIC
 ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(main PRIVATE Device_lib)