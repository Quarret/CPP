#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long MOD = 1e9 + 7;
vector<int> nums = {3,5};
int maxProfit(vector<int>& inventory, int orders) {
    int n = inventory.size();
    priority_queue<int, vector<int>, less<int>> pq;

    for (int i = 0; i < n; i++) pq.push(inventory[i]);

    auto sum = [&](int num, int cnt) -> long long {
        return ((num - cnt + 1 + num) % MOD) * (cnt % MOD) / 2 % MOD;
    };

    long long ans = 0;
    int num = pq.top();
    pq.pop();

    if (n == 1) ans = sum(num, orders);

    while (orders) {
        int cnt = min(num - pq.top() + 1, orders);
        ans += sum(num, cnt);
        num = num - cnt;

        pq.push(num);
        num = pq.top();
        pq.pop();
        orders -= cnt;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    maxProfit(nums, 6);

    return 0;
}
