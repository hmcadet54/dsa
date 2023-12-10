#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Task {
public:
    string name;
    int priority;

    Task(string name, int priority){
        name=this->name;
        priority=this->priority;
    }

    //for sorting
    bool operator<(const Task& other) const {
        return priority > other.priority; 
    }
};

void scheduleTasks(vector<Task>& tasks) {
    sort(tasks.begin(), tasks.end());

    for (const Task& task : tasks) {
        cout << "Scheduled task " << task.name << " with priority " << task.priority << endl;
    }
}

int main() {
    
    vector<Task> tasks = {{"t1", 8}, {"t2", 5}, {"t3", 10}, {"t4", 2}, {"t5", 7}};

    scheduleTasks(tasks);

    return 0;
}
