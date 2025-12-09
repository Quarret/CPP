#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    string start = "", end = "";
    for (int x : nums1) {
        start += x + '0';
    }

    for (int x : nums2) {
        end += x + '0';
    }
    
    unordered_map<string, int> vis;
    queue<string> q;
    q.push(start);
    vis[start] = 1;

    int d = 0;
    while (!q.empty()) {
        int t = q.size();
        d++;

        for (int i = 0; i < t; i++) {
            string u = q.front();
            q.pop();
            if (u == end) return d - 1;

            for (int l = 0; l < n; l++) {
                for (int r = l; r < n; r++) {
                    string utmp = u;
                    string s1 = utmp.substr(l, r - l + 1);
                    string s2 = utmp.erase(l, r - l + 1);
                    string v1 = s1 + s2, v2 = s2 + s1;
                    if (!vis[v1]) {
                        q.push(v1);
                        vis[v1] = 1;
                    }

                    if (!vis[v2]) {
                        q.push(v2);
                        vis[v2] = 1;
                    }
                }
            }
        }
    }

    return 0;
}

int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    set<vector<int>> vis = {nums1};
    vector<vector<int>> q = {nums1};
    
    for (int ans = 0; ; ans++) {
        vector<vector<int>> nxt;
        for (auto &a : q) {
            if (a == nums2) return ans;
        
            
            for (int l = 0; l < n; l++) {
                for (int r = l + 1; r <= n; r++) {
                    auto b = a;
                    vector<int> sub(b.begin() + l, b.begin() + r);
                    b.erase(b.begin() + l, b.begin() + r);

                    for (int i = 0; i <= b.size(); i++) {
                        auto c = b;
                        c.insert(c.begin() + i, sub.begin(), sub.end());
                        if (vis.insert(c).second) {
                            nxt.emplace_back(c);
                        }
                    }
                }
            }
        }
        q = move(nxt);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
