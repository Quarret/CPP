/*** 
 * @Author: Quarret
 * @Date: 2025-06-12 10:17:46
 * @LastEditTime: 2025-06-12 11:01:48
 */
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int MOD = 1e9 + 7;
vector<int> productQueries(int n, vector<vector<int>>& queries) {
    vector<int> powers, ans;
    int x = n, cnt = 0;
    while (x) {
        int num = (x & 1) << cnt;
        if (num) powers.push_back(num % MOD);
        cnt++;
        x >>= 1;
    }

    int m = powers.size();
    vector<long long> pre(m + 1, 1);
    for (int i = 0; i < m; i++) pre[i + 1] = (1LL * pre[i] * powers[i]) % MOD;
    
    for (auto& it: queries) {
        int l = it[0], r = it[1];
        ans.push_back(pre[r + 1] / pre[l]);
    }

    return ans;
}

/*
预处理2的幂次
*/
int MOD = 1e9 + 7;

vector<int> productQueries(int n, vector<vector<int>>& queries) {
    vector<int> powers, ans;
    int x = n, cnt = 0;
    powers.push_back(0);
    while (x) {
        int num = x & 1;
        if (num) powers.push_back(powers.back() + num);
        cnt++;
        x >>= 1;
    }

    vector<int> pow2(500, 1);
    for (int i = 1; i < 500; i++) {
        pow2[i] = pow2[i - 1] * 2 % MOD;
    }

    for (auto& it: queries) {
        int l = it[0], r = it[1];
        ans.push_back(pow2[powers[r + 1] - powers[l]]);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
