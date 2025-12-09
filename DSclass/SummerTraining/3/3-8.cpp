#include <bits/stdc++.h>
using ll = long long;
using namespace std;

map<char, int> mp;
set<char> st;
void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    
    for (int i = 0; i < s2.size(); i++) {
        mp[s2[i]]++;
        st.insert(s2[i]);
    }
    
    
    int cnt = 0, cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < s1.size(); i++) {
        if (mp[s1[i]] == NULL) {
            cnt++;
        } else {
            mp[s1[i]]--;
        }
    }
    
    bool flag = 0;
    for (auto &it : mp) {
        if (it.second < 0) {
            cnt1 -= it.second;
        } else if (it.second > 0) {
            flag = 1;
            cnt2 += it.second;
        }
    }

    if (flag) {
        cout << "No " << cnt2 << '\n';
        return;
    }

    cout << "Yes " << cnt1 + cnt << '\n';

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie();

    solve();
}
