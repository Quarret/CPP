#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int m = s.size(), ans = 0;
        for (int n = minSize; n <= maxSize; n++) {
            unordered_map<string, pair<int, int> > mp;//map<s, difchar, freq>

            int num = 0;
            string tmp = "";
            for (int i = 0; i < m; i++) {
                tmp += s[i];
                if (tmp.find(s[i]) != -1 && tmp.size() >= n) mp[tmp].first++;

                if (i < n - 1) continue;

                
                mp[tmp].second++;

                cout << tmp << ": " << mp[tmp].first << ' ' << mp[tmp].second << '\n';
                if (mp[tmp].first >= maxLetters) num = max(num, mp[tmp].second);
                string tmp1 = tmp;
                tmp.erase(tmp.begin());
                if (tmp.find(s[i - n + 1]) != -1) mp[tmp1].first--; 
            }
            
            ans = max(ans, num);
            mp.clear();
        }

        return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    
    maxFreq("aababcaab", 2, 3, 4);
    return 0;
}
