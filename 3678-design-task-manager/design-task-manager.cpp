#include <bits/stdc++.h>
using namespace std;

class TaskManager {
    struct Task {
        int userId;
        int taskId;
        int priority;
    };

    // Max-Heap: compare by priority, then taskId
    struct Compare {
        bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
            if (a.first != b.first) return a.first < b.first; // higher priority first
            return a.second < b.second; // higher taskId first
        }
    };

    priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> maxHeap;
    unordered_map<int, Task> taskMap; // taskId -> Task

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto &t : tasks) {
            add(t[0], t[1], t[2]);
        }
    }

    void add(int userId, int taskId, int priority) {
        Task newTask{userId, taskId, priority};
        taskMap[taskId] = newTask;
        maxHeap.push({priority, taskId});
    }

    void edit(int taskId, int newPriority) {
        if (taskMap.count(taskId)) {
            taskMap[taskId].priority = newPriority;
            maxHeap.push({newPriority, taskId});
        }
    }

    void rmv(int taskId) {
        taskMap.erase(taskId); // lazy deletion
    }

    int execTop() {
        while (!maxHeap.empty()) {
            auto [priority, taskId] = maxHeap.top();
            maxHeap.pop();
            if (taskMap.count(taskId) && taskMap[taskId].priority == priority) {
                int userId = taskMap[taskId].userId;
                taskMap.erase(taskId);
                return userId;
            }
        }
        return -1; // no valid tasks
    }
};