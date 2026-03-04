#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> partitionLabels(string s) {
    vector<int> mx(26);
    for (int i = 0; i < s.size(); i++) {
        int c = s[i] - 'a';
        mx[c] = max(mx[c], i);
    }
    
    int cur_i = 0, cnt = 0;
    vector<int> ans;
    for (int i = 0; i < s.size(); i++) {
        cnt++;
        cur_i = max(cur_i, mx[s[i] - 'a']);
        if (i == cur_i) {
            ans.push_back(cnt);
            cnt = 0;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}