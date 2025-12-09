#include <bits/stdc++.h>
#define ll long long
using namespace std;

int a, b, n;
vector<int> adj[200005];
vector<int> input,ans, relorder(200007);
//int input[200005], ans[200005], relorder[200005];
bool cmp(int x, int y) {
    return relorder[x] < relorder[y];
}
void solve() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        cin >> a;
        input.push_back(a);
        relorder[input[i]] = i;
    }

    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end(), cmp);
    }

    queue<int> q;
    q.push(1);
    bool vis[200005] = {0};
    
    while (!q.empty()) {
        queue<int> temp;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            ans.push_back(x);
            vis[x] = 1;
            for (int j = 0; j < adj[x].size(); j++) {
                if (!vis[adj[x][j]]) {
                    temp.push(adj[x][j]);
                }
            }
        }
        q = temp;
    }

    for (int i = 0; i < n; i++) {
        if (ans[i] != input[i]) {
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";

    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    solve();
}
