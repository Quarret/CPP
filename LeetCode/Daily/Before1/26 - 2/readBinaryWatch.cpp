#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<string> readBinaryWatch(int turnedOn) {
    unordered_map<int, vector<string>> hour, minute;
    for (int x = 0; x < 12; x++) {
        int cnt = __builtin_popcount(x);
        string s = to_string(x);
        s.push_back(':');
        hour[cnt].push_back(s);
        // cout << s << '\n';
    }
    
    for (int y = 0; y < 60; y++) {
        int cnt = __builtin_popcount(y);
        string s = (y < 10 ? "0" : "") + to_string(y);
        minute[cnt].push_back(s);
        // cout << s << '\n';
    }

    vector<string> ans;
    for (int i = 0; i <= turnedOn; i++) {
        for (string s : hour[i]) {
            for (string s1 : minute[turnedOn - i]) {
                ans.push_back(s + s1);
            }
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}