#include <iostream>
#include <list>

// Define a structure to represent each task
struct Task {
    int taskID;
    int executionTime;
    int cpuUsage;
    int memory;
    int storage;
};

// Define a structure to represent each VM
struct VM {
    int cpu;
    int memory;
    int storage;
};

int main() {
    // Initialize the task queue
    std::list<Task> taskQueue = {
        {1, 20, 30, 512, 2},
        {2, 15, 20, 256, 1},
        {3, 25, 40, 768, 3},
        {4, 18, 25, 384, 2}
    };

    // Initialize the available virtual machines
    std::list<VM> vms = {
        {60, 1024, 5},
        {60, 1024, 5},
        {60, 1024, 5}
    };

    // Create a priority queue based on execution time
    taskQueue.sort([](const Task& task1, const Task& task2) {
        return task1.executionTime < task2.executionTime;
    });

    // Assign tasks to VMs
    while (!taskQueue.empty()) {
        Task currentTask = taskQueue.front();
        taskQueue.pop_front();
        
        // Find the VM with the most available resources
        auto bestVM = vms.begin();
        for (auto it = vms.begin(); it != vms.end(); ++it) {
            if (it->cpu >= currentTask.cpuUsage &&
                it->memory >= currentTask.memory &&
                it->storage >= currentTask.storage) {
                if (it->cpu > bestVM->cpu) {
                    bestVM = it;
                }
            }
        }

        // Execute the task on the selected VM
        std::cout << "Task " << currentTask.taskID << " is executed on VM " << bestVM->cpu << std::endl;
        bestVM->cpu -= currentTask.cpuUsage;
        bestVM->memory -= currentTask.memory;
        bestVM->storage -= currentTask.storage;
    }

    return 0;
}
