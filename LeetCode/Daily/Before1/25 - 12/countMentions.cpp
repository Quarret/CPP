#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
    string MSG = "MESSAGE", ALL = "ALL", HERE = "HERE", OFF = "OFFLINE";
    vector<int> ans(numberOfUsers), time(numberOfUsers, 0);
    sort(events.begin(), events.end(), [&](auto &e1, auto&e2) {
        if (stoi(e1[1]) < stoi(e2[1])) return true;
        else if (stoi(e1[1]) == stoi(e2[1])) {
            if (e1[0] == OFF) return true;
            else return false;
        }
        return false;
    });
    
    for (auto &e : events) {
        string s1 = e[0], s2 = e[2];
        int timeStamp = stoi(e[1]);
        
        auto check = [&](int id) -> void {
                ans[id]++;
        };

        if (s1 == MSG) {
            if (s2 == ALL) {
                for (int i = 0; i < numberOfUsers; i++) {
                    ans[i]++;
                }
            } else if (s2 == HERE) {
                for (int i = 0; i < numberOfUsers; i++) {
                    if (time[i] > timeStamp) continue;
                    ans[i]++;
                }
            } else {
                string id = "";
                for (char c : s2) {
                    if (c >= '0' && c <= '9') {
                        id.push_back(c);
                    } else {
                        if (!id.empty()) check(stoi(id));
                        id.clear();
                    }
                }
                if (!id.empty()) check(stoi(id));
            }
        } else {
            time[stoi(s2)] = 60 + timeStamp;
        } 
    }

    return ans;
}

vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
    string OFF = "OFFLINE";
    vector<int> ans(numberOfUsers), time(numberOfUsers, 0);
    sort(events.begin(), events.end(), [&](auto &e1, auto&e2) {
        if (stoi(e1[1]) < stoi(e2[1])) return true;
        else if (stoi(e1[1]) == stoi(e2[1])) {
            if (e1[0] == OFF) return true;
        }
        return false;
    });
    
    for (auto &e : events) {
        string MSG = e[0], s = e[2]; 
        int timeStamp = stoi(e[1]);
        
        if (MSG == OFF) {
            time[stoi(s)] = 60 + timeStamp;
            continue;
        }

        if (s == "ALL") {
            for (int &x : ans) {
                x += 1;
            }
        } else if (s == "HERE") {
            for (int i = 0; i < numberOfUsers; i++) {
                if (timeStamp < time[i]) continue;
                ans[i]++; 
            }
         } else {
            int id = -1;
            for (char c : s) {
                if (c >= '0' && c <= '9') {
                    if (id == -1) id = 0;
                    id = id * 10 + c - '0';
                } else if (id != -1) {
                    ans[id]++;
                    id = -1;
                }
            }
            if (id != -1) ans[id]++;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
