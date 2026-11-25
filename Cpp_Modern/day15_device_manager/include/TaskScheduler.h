#include "Task.h"

class TaskScheduler {
public:
    void addTask(Task task);

    void runAll() const;

private:
    std::vector<Task> tasks;
};
