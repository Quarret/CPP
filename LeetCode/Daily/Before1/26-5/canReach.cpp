#include <bits/stdc++.h>
using ll = long long;
using namespace std;


bool canReach(vector<int>& arr, int start) {
    int n = arr.size();
    
    vector<int> vis(n);
    queue<int> q;
    q.push(start);
    vis[start] = 1;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        if (arr[cur] == 0) return true;

        int nxt1 = cur + arr[cur], nxt2 = cur - arr[cur];
        if (nxt1 < n && !vis[nxt1]) {
            q.push(nxt1);
            vis[nxt1] = 1;
        }
        if (nxt2 >= 0 && !vis[nxt2]) {
            q.push(nxt2);
            vis[nxt2] = 1;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}