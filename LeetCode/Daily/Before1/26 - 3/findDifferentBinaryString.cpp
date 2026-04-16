#include <bits/stdc++.h>
using ll = long long;
using namespace std;

string findDifferentBinaryString(vector<string>& nums) {
    unordered_map<int, int> mp;
    for (string s : nums) {
        int x = 0;
        for (char c : s) {
            x = (x << 1) | (c & 1);
        }
        mp[x] = 1;
    }

    int n = nums.size(), x = 0;
    for (; x < (1 << n); x++) {
        if (!mp[x]) break;
    }

    string ans(n, '0');
    for (int i = 0; i < n; i++) {
        if (x >> i & 1) ans[n - 1 - i] = '1';
    }
    return ans;
}

// 库函数写法
string findDifferentBinaryString(vector<string>& nums) {
    unordered_set<int> st;
    for (string s : nums) {
        // stoi 可以转换二进制
        st.insert(stoi(s, nullptr, 2)); 
    }

    int x = 0;
    while (st.contains(x)) {
        x++;
    }

    int n = nums.size();
    string ans = bitset<32>(x).to_string().substr(32 - n);
    return ans;
}

// 构造一个 ans 与每个 s 都有不同
string findDifferentBinaryString(vector<string>& nums) {
    int n = nums.size();
    string ans(n, '0');
    for (int i = 0; i < n; i++) {
        ans[i] = nums[i][i] ^ 1;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}