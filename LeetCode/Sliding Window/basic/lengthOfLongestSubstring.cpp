#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.size();

    if (n == 1) return 1;
    
    int ans = 0;
    string substr;
    unordered_map<char, int> mp;
    
    for (int i = 0; i < n; i++) {
        substr += s[i];

        mp[s[i]]++;

        if (mp[s[i]] != 2) {
            int m = substr.size();
            ans = max(ans, m);
        }

        while (mp[s[i]] == 2) {
            mp[substr[0]]--;
            substr.erase(0, 1);
        }
    }

    return ans;
}
/*
不必创建一个substr，只看头尾字符就行
只要字符串符合规则，就记录长度

两种取max方式，其实操作数差的不多，选好理解的那种来取
*/

int lengthOfLongestSubstring(string s) {
    int n = s.size();

    int ans = 0, l = 0;
    unordered_map<char, int> mp;
    
    for (int r = 0; r < n; r++) {
        mp[s[r]]++;

        while (mp[s[r]] > 1) {
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

    string s1 = "au";
    cout << lengthOfLongestSubstring(s1);

    return 0;
}
