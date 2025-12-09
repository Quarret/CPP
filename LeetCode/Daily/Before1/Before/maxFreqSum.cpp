#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int maxFreqSum(string s) {
    unordered_map<char, int> mp;
    pair<int ,char> p1, p2;
    p1.first = 0, p2.first = 0;
    
    for (char c : s) {
        mp[c]++;

        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            p1 = max(p1, pair<int, char>(mp[c], c));
        } else {
            p2 = max(p2, pair<int, char>(mp[c], c));
        }
    }

    return p1.first + p2.first;
}

// bit优化
int maxFreqSum(string s) {
    const int VOWEL_MASK = 0x104111;
    int cnt[26]{};
    int max_cnt[2]{};

    for (char c : s) {
        c -= 'a';
        int bit = VOWEL_MASK >> c & 1;

        cnt[c]++;
        max_cnt[bit] = max(max_cnt[bit], cnt[c]);
    }

    return max_cnt[0] + max_cnt[1];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
