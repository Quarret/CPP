/*** 
 * @Author: Quarret
 * @Date: 2025-07-10 09:40:41
 * @LastEditTime: 2025-07-10 15:49:20
 */


#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
    int n = s.size();
    vector<vector<int>> ans;
    for (auto& arr: queries) {
        int l = arr[0], r = arr[1];
        unsigned int num = r ^ l, len = max(__bit_width(num), 1);
        string str = bitset<32>(num).to_string().substr(32 - len);

        int t = str.size();
        int pos = s.find(str);//每次find时间是O(n),铁定超时
        if (pos != s.npos) {
            ans.push_back({pos, pos + t - 1});
        } else ans.push_back({-1, -1});
    }
    
    return ans;
}

/*
灵神思路
预处理一下s，找出其中的所有数字
*/
vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
    unordered_map<int, pair<int, int>> mp;
    vector<vector<int>> ans;

    auto it0 = s.find('0');
    if (it0 != s.npos) mp[0] = {it0, it0};

    for (int l = 0, n = s.size(); l < n; l++) {//从左向右找s中的1
        if (s[l] == '0') continue;

        for (int r = l, x = 0; r < min(l + 30, n); r++) {//从右到左枚举值
            x = (x << 1) | (s[r] & 1);
            if (!mp.contains(x)) mp[x] = {l, r};
        }
    }

    for (auto& q: queries) {
        auto it = mp.find(q[0] ^ q[1]);
        if (it != mp.end()) {
            ans.push_back({it->second.first, it->second.second});
        } else ans.push_back({-1, -1});
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s = "0101";
    vector<vector<int>> query = {{12, 8}};

    substringXorQueries(s, query);

    return 0;
}
