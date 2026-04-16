#include <bits/stdc++.h>
using ll = long long;
using namespace std;


struct cmp {
    bool operator()(pair<int, int> &a, pair<int, int> &b) {
    if (a.first < b.first) return true;
    else if (a.first == b.first) {
        return a.second > b.second; 
    }
    return false;
    };
};

class EventManager {
    unordered_map<int, int> id_to_priority;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
public:
    EventManager(vector<vector<int>>& events) {
        for (auto &p : events) {
            int id = p[0], prior = p[1];
            id_to_priority[id] = prior;
            pq.emplace(prior, id);
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        id_to_priority[eventId] = newPriority;
        pq.emplace(newPriority, eventId);
    }
    
    int pollHighest() {
        while (!pq.empty() && id_to_priority[pq.top().second] != pq.top().first) {
            pq.pop();
        }

        if (!pq.empty()) {
            auto [_, id] = pq.top();
            id_to_priority[id] = -1;
            pq.pop();
            return id;
        }

        return -1;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}