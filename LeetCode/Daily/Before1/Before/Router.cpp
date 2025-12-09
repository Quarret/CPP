#include <bits/stdc++.h>
using ll = long long;
using namespace std;

class Router {
    public:
        unordered_map<int, unordered_map<int, unordered_set<int>>> vis;
        queue<tuple<int, int, int>> q;
        int maxlen;
        Router(int memoryLimit) {
            maxlen = memoryLimit;
        }
        
        bool addPacket(int source, int destination, int timestamp) {
            if (vis[destination][source].contains(timestamp)) return false;
            vis[destination][source].insert(timestamp);

            if (q.size() == maxlen) {
                auto [s, d, t] = q.front();
                vis[d][s].erase(t);
                q.pop();
            }
            q.emplace(source, destination, timestamp);

            return true;
        }
        
        vector<int> forwardPacket() {
            vector<int> ans;
            if (q.empty()) return ans;
            else {
                auto [source, dest, timestamp] = q.front();
                q.pop();

                vis[dest][source].erase(timestamp);
                ans.push_back(source);
                ans.push_back(dest);
                ans.push_back(timestamp);
            }

            return ans;
        }
        
        int getCount(int destination, int startTime, int endTime) {
            int ans = 0;
            for (auto [_, st] : vis[destination]) {
                auto it1 = lower_bound(st.begin(), st.end(), startTime);
                auto it2 = lower_bound(st.begin(), st.end(), endTime + 1);

                int pos1 = distance(st.begin(), it1);
                int pos2 = distance(st.begin(), it2) - 1;
                ans += pos2 - pos1 + 1;
            }

            return ans;
        }
};

class Router {
    int memory_limit;
    queue<tuple<int, int, int>> packet_q;

    set<tuple<int, int, int>> packet_set;
    // 用deque方便二分
    unordered_map<int, deque<int>> dest_to_timestamps;
public:
    Router(int memoryLimit) {
        memory_limit = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        auto packet = tuple(source, destination, timestamp);
        if (packet_set.contains(packet)) return false;

        if (packet_q.size() == memory_limit) {
            forwardPacket();
        }

        packet_q.push(packet);
        packet_set.insert(packet);
        dest_to_timestamps[destination].push_back(timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        if (packet_q.empty()) return {};

        auto packet = packet_q.front();
        packet_q.pop();
        packet_set.erase(packet);

        auto [source, dest, timestamp] = packet;
        dest_to_timestamps[dest].pop_front();
        return {source, dest, timestamp};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto &timestamps = dest_to_timestamps[destination];
        auto left = ranges::lower_bound(timestamps, startTime);
        auto right = ranges::lower_bound(timestamps, endTime);

        return right - left;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
