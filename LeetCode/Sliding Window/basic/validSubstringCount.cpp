#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long validSubstringCount(string word1, string word2) {
        long long n = word1.size(), m = word2.size(), l = 0, ans = 0, num = 0;
        unordered_map<char, int> mp;

        for (int i = 0; i < m; i++) mp[word2[i]]++;
        int k = mp.size();

        for (int r = 0; r < n; r++) {
            mp[word1[r]]--;
            if (!mp[word1[r]]) num++;

            while (num == k) {
                if (!mp[word1[l]]) num--;
                mp[word1[l]]++;
                l++;
            }

            ans += l;
        }

        return ans;
}

/*
以数组来优化map
提升时间和空间
*/
long long validSubstringCount(string word1, string word2) {
    long long n = word1.size(), m = word2.size(), l = 0, ans = 0, num = 0, k = 0;
    vector<int> mp(26, 0);

    for (int i = 0; i < m; i++) {
        if (!mp[word2[i] - 'a']) k++;
        mp[word2[i] - 'a']++;
    }

    for (int r = 0; r < n; r++) {
        mp[word1[r] - 'a']--;
        if (!mp[word1[r] - 'a']) num++;

        while (num == k) {
            if (!mp[word1[l] - 'a']) num--;
            mp[word1[l] - 'a']++;
            l++;
        }

        ans += l;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
