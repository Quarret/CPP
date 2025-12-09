#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int minimumRounds(vector<int>& tasks) {
    unordered_map<int, int> cnt;
    for (int t : tasks) {
        cnt[t]++;
    }

    int ans = 0;
    for (auto [_, c] : cnt) {
        int res = INT_MAX;
        for (int i =  c / 3; i >= 0; i--) {
            int num1 = c - i * 3;
            if ((c - num1) % 2 == 0) {
                res = i + (c - num1) / 2;
                break;
            }
        }

        if (res == INT_MAX) {
            return -1;
        }
        ans += res;
    }

    return ans;
}

int minimumRounds(vector<int>& tasks) {
    unordered_map<int, int> cnt;
    for (int t : tasks) {
        cnt[t]++;
    }

    int ans = 0;
    for (auto [_, c] : cnt) {
        if (c == 1) {
            return -1;
        }
        ans += (c + 2) / 3;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
