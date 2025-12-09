#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<string> buildArray(vector<int>& target, int n) {
    int m = target.size(), idx = 0;
    vector<string> ans;

    for (int i = 1; i <= n; i++) {
        if (idx == m - 1) break;
        
        ans.push_back("Push");
        if (i == target[idx]) {
            idx++;
        } else ans.push_back("Pop");
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
