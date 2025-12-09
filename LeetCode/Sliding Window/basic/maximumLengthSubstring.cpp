#include <bits/stdc++.h>
using ll = long long;
using namespace std;

/*
不定长滑动窗口的特点:
1. 连续
2. 只改变头尾元素
*/
int maximumLengthSubstring(string s) {
    int n = s.size();

    int ans = 0, l = 0;
    unordered_map<char, int> mp;
    
    for (int r = 0; r < n; r++) {
        mp[s[r]]++;

        while (mp[s[r]] > 2) {
            mp[s[l]]--;
            l++;
        }

        ans = max(ans, r - l + 1);
    }

    return ans; 
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
