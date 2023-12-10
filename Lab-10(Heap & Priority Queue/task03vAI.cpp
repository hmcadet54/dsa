#include <iostream>
#include <queue>
#include <cstdlib>
#include <ctime>

struct Task {
    int priority;
    std::string name;
};

bool operator<(const Task& t1, const Task& t2) {
    return t1.priority < t2.priority;
}

int main() {
    std::priority_queue<Task> taskQueue;
    std::srand(std::time(0));

    // Generate tasks with random priorities
    for (int i = 1; i <= 10; i++) {
        Task task;
        task.priority = std::rand() % 10 + 1;
        task.name = "Task " + std::to_string(i);
        taskQueue.push(task);
    }

    // Process tasks in priority order
    while (!taskQueue.empty()) {
        Task task = taskQueue.top();
        taskQueue.pop();
        std::cout << "Processing task: " << task.name << std::endl;
    }

    return 0;
}
