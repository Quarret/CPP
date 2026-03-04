#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int firstUniqueFreq(vector<int>& nums) {
    unordered_map<int, int> cnt, mp;
    for (int x : nums) {
        cnt[x]++;
    }

    for (auto &[_, c] : cnt) {
        mp[c]++;
    }

    for (int x : nums) {
        if (mp[cnt[x]] == 1) {
            return x;
        }
    }

    return -1;
} 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}