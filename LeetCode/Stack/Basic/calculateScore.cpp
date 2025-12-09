#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long calculateScore(string s) {
    int n = s.size();
    vector<stack<int>> idx(26);
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        if (!idx[25 - (s[i] - 'a')].empty()) {
            ans += i - idx[25 - (s[i] - 'a')].top();
            idx[25 - (s[i] - 'a')].pop();
        } else idx[s[i] - 'a'].push(i);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
