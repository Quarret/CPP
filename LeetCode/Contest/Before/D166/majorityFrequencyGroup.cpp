#include <bits/stdc++.h>
using ll = long long;
using namespace std;

string majorityFrequencyGroup(string s) {
    unordered_map<char, int> cnt;
    unordered_map<int, unordered_set<char>> mp;
    
    for (char c : s) {
        cnt[c]++;
    }

    for (auto &[c, count] : cnt) {
        mp[count].insert(c);
    }

    pair<int, int> maxx = {0, 0};
    for (auto &[k, st] : mp) {
        maxx = max(maxx, pair<int, int>(st.size(), k));
    }

    string ans = "";
    for (auto c : mp[maxx.second]) {
        ans += c;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
