#include <bits/stdc++.h>
using ll = long long;
using namespace std;

// [1, 3, 5]
long long MOD = 1e9 + 7;
vector<int> arr = {1,3,5};
int numOfSubarrays(vector<int>& arr) {
    int n = arr.size(), ans = 0;
    long long cnt[2]{};
    vector<int> pre(n + 1, 0);

    for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + arr[i];

    for (int j = 1; j <= n; j++) {
        for (int i = 0; i < j; i++) {
            if ((pre[j] - pre[i]) % 2 == 1) ans++;
        }
    }

    return ans;
}

int numOfSubarrays(vector<int>& arr) {
    int n = arr.size(), ans = 0;
    long long cnt[2]{};
    /*
    要想把任意子数组都表示成两个前缀和的差，必须添加 pre[0]=0，否则当子数组是前缀时，没法减去一个数
    */
    cnt[0] = 1;// 前缀和计算需要pre[0] = 0, 即初始化一个偶数
    vector<int> pre(n + 1, 0);

    for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + arr[i];

    for (int j = 1; j <= n; j++) {
        ans = (ans + cnt[1 - (pre[j] % 2)]) % MOD;
        cnt[pre[j] % 2] = (cnt[pre[j] % 2] + 1) % MOD;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    numOfSubarrays(arr);

    return 0;
}
