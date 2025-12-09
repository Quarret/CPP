/*** 
 * @Author: Quarret
 * @Date: 2025-05-14 09:40:25
 * @LastEditTime: 2025-06-04 17:03:10
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

string s = "ckafnafqo";
int countPalindromicSubsequence(string s) {
    int n = s.size(), ans = 0;
    int cnt1[26]{}, cnt2[26]{}, cnt3[26]{};
    for (int i = 1; i < n; i++) cnt2[s[i] - 'a']++;
    cnt1[s[0] - 'a']++;
    unordered_map<string, int> mp;

    for (int i = 1; i < n - 1; i++) {//枚举中间字母
        cnt2[s[i] - 'a']--;
        if (!cnt2[s[i] - 'a']) cnt3[s[i] - 'a'] = 0;

        int l = s[i - 1] - 'a';
        cnt3[l] = min(cnt1[l], cnt2[l]);

        for (int j = 0; j < 26; j++) {
            if (cnt3[j]) {
                string tmp;
                tmp += (char)(j + 'a');
                tmp += s[i];

                if (!mp[tmp]) {
                    //cout << "l: " << (char)(j + 'a') << ' ' << "mid: " << s[i] << " mididx: " << i << '\n'; 
                    ans++;
                    mp[tmp] = 1;
                }
            }
        }

        cnt1[s[i] - 'a']++;
    }

    return ans;
}

/*
利用26 * 26的bool数组来记录每个回文字符串，bool数组的第二维用位运算压掉
*/
int countPalindromicSubsequence(string s) {
    int n = s.size();
    int pre[26]{}, suf[26]{}, hash[26]{};//hash数组代表中间为s[i]与其他字母组成字符串的情况
    for (int i = 1; i < n; i++) suf[s[i] - 'a']++;

    for (int mid = 1; mid < n - 1; mid++) {//枚举中间字母
        suf[s[mid] - 'a']--;
        pre[s[mid - 1] - 'a']++;

        for (int i = 0; i < 26; i++) {
            if (pre[i] && suf[i]) {
                hash[s[mid] - 'a'] |= 1 << i;//中间字符为s[mid],左右字符为(char)(i + 'a')
            }
        }
    }

    auto bitcount = [&](int x) -> int {
        int cnt = 0;
        while (x) {
            cnt += x & 1;
            x = x >> 1;
        }

        return cnt;
    };

    int ans = 0;
    for (int i = 0; i < 26; i++) ans += bitcount(hash[i]);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    countPalindromicSubsequence(s);

    return 0;
}
