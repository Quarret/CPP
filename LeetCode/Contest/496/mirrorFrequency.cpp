#include <bits/stdc++.h>
using ll = long long;
using namespace std;


int mirrorFrequency(string s) {
    int num_cnt[10], char_cnt[26];
    for (char c : s) {
        if (c >= '0' && c <= '9') num_cnt[c - '0']++;
        else char_cnt[c - 'a']++;
    }

    int ans = 0;
    for (int i = 0; i <= 4; i++) {
        ans += abs(num_cnt[i] - num_cnt[9 - i]);
    }

    for (int i = 0; i <= 12; i++) {
        ans += abs(char_cnt[i] - char_cnt[25 - i]);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}