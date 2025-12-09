#include <bits/stdc++.h>
using ll = long long;
using namespace std;

/*
O(2 * k + n)
*/
int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
    vector<int> prel(k + 1), prer(k + 1);
    unordered_map<int, int> mp;
    for (auto &e : fruits) {
        int pos = e[0], c = e[1];
        mp[pos] = c;
    }

    for (int len = 0; len <= k; len++) {
        prel[len + 1] = prel[len] + mp[startPos - len];
        prer[len + 1] = prer[len] + mp[startPos + len];        
    }

    int ans = 0;
    for (int len = 0; len <= k; len++) {
        int l = len;
        int r = max(0, k - 2 * len);
        ans = max(ans, prel[l + 1] + prer[r + 1] - mp[startPos]);
        ans = max(ans, prer[l + 1] + prel[r + 1] - mp[startPos]);
    }
}

/*
sliding window by 0x3f
- first left then right
start - fruit[left][0] + fruit[right][0] - fruit[left][1]

- first right then left
fruit[right][0] - start + fruit[right][0] - fruit[left][0]
*/
int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
    //struct lower_bound
    // ranges::lower_bound(struct arr, goal, comparator(default less{}), which demos to compare)
    int left = ranges::lower_bound(fruits, startPos - k, {}, [](auto &f) {return f[0];}) - fruits.begin();

    int ans = 0, s = 0, n = fruits.size();
    for (int right = left; right < n && fruits[right][0] <= startPos + k; right++) {
        s += fruits[right][1];

        while (fruits[right][0] - 2 * fruits[left][0] + startPos > k 
            && 2 * fruits[right][0] - fruits[left][0] - startPos > k) {//any direction first ok is alright {
            s -= fruits[left][1];
            left++;
        }
        ans = max(ans, s);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    return 0;
}
