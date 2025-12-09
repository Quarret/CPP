#include <bits/stdc++.h>
using ll = long long;
using namespace std;

/*
重建栈
记录最右出现字母的出现次数，到达k次，删除
*/
string removeDuplicates(string s, int k) {
    int n = s.size();
    vector< pair<char, int> > st;

    for (int i = 0; i < n; i++) {
        if (st.empty() || s[i] != st.back().first) st.push_back({s[i], 1});
        else if (++st.back().second == k) st.pop_back();
    }

    string ans;
    for (auto& it : st) {
        ans += string(it.second, it.first);

    }
    
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
