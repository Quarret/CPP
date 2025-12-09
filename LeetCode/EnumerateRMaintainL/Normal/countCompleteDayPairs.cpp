#include <bits/stdc++.h>
using ll = long long;
using namespace std;

long long countCompleteDayPairs(vector<int>& hours) {
    int n = hours.size();
    unordered_map<int, int> mp;
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        int num = hours[i] % 24;

        if (num) ans += mp[24 - num];
        else ans += mp[0];

        mp[num]++;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
