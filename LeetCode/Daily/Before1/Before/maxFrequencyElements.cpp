#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int maxFrequencyElements(vector<int>& nums) {
    unordered_map<int, int> freq;
    unordered_map<int, int> cnt;

    int mx = 0;
    for (int x : nums) {
        freq[x]++;
        cnt[freq[x]]++;

        mx = max(mx, freq[x]);
    }

    return cnt[mx] * mx;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
