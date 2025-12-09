#include <bits/stdc++.h>
using ll = long long;
using namespace std;

class TaskManager {
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, less<>> pq;
    unordered_map<int, int> taskId_To_Priority;
    unordered_map<int, int> taskId_To_UserId;
    public:
        TaskManager(vector<vector<int>>& tasks) {
            for (auto &e : tasks) {
                add(e[0], e[1], e[2]);
            }
        }
        
        void add(int userId, int taskId, int priority) {
            pq.emplace(priority, taskId, userId);
            taskId_To_Priority[taskId] = priority;
            taskId_To_UserId[taskId] = userId;
        }
        
        void edit(int taskId, int newPriority) {
            int userId = taskId_To_UserId[taskId];
            taskId_To_Priority[taskId] = newPriority;
            pq.emplace(newPriority, taskId, userId);
        }
        
        void rmv(int taskId) {
            taskId_To_Priority[taskId] = -1;
        }
        
        int execTop() {
            while (!pq.empty()) {
                auto [priority, taskId, userId] = pq.top();
                pq.pop();

                if (taskId_To_Priority[taskId] == priority && taskId_To_UserId[taskId] == userId) {
                    // 记得原操作调用
                    rmv(taskId);
                    return userId;
                }
            }

            return -1;
        }
    };
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
