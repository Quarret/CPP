#include <bits/stdc++.h>
using ll = long long;
using namespace std;

string sortVowels(string s) {
    int n = s.size();

    unordered_map<char, int> cnt;
    unordered_map<char, int> idxs;
    idxs['a'] = idxs['o'] = idxs['i'] = idxs['e'] = idxs['u'] = n;
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            if (idxs[c] == n) idxs[c] = i;
            cnt[c]++;
        }
    }
    
    vector<char> a = {'a', 'e', 'i', 'o', 'u'};
    sort(a.begin(), a.end(), [&](char &x, char &y) {
        if (cnt[x] > cnt[y]) return true;
        else if (cnt[x] == cnt[y]) {
            return idxs[x] < idxs[y];
        } else return false;
    });

    // for (char c : a) {
    //     cout << c << '\n';
    // }

    string res;
    for (char c : a) {
        res += string(cnt[c], c);
    }
    // cout << res << '\n';

    int p = 0;
    for (char &c : s) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            c = res[p++];
        }
    }

    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}