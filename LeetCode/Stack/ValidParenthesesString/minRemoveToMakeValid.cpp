#include <bits/stdc++.h>
using ll = long long;
using namespace std;

string minRemoveToMakeValid(string s) {
    int n = s.size();
    vector<int> idx;

    for (int i = 0; i < n; i++) {
        if (s[i] == ')') {
            if (idx.size() && s[idx.back()] == '(') idx.pop_back();
            else idx.push_back(i);
        } else if (s[i] == '(') idx.push_back(i);
    }

    int cnt = n, m = idx.size();
    if (m) cnt = 0;
    
    string ans;
    for (int i = 0; i < n; i++) {
        if (cnt >= m || i != idx[cnt]) ans.push_back(s[i]);
        else cnt++;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
