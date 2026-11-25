#include "TaskScheduler.h"

void TaskScheduler::addTask(Task task){
    tasks.push_back(std::move(task));
}

void TaskScheduler::runAll() const{
    for(const auto& task:tasks){
        task.execute();
    }
}