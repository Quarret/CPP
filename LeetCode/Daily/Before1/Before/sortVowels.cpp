#include <bits/stdc++.h>
using ll = long long;
using namespace std;

string sortVowels(string s) {
    unordered_map<char, int> mp;
    mp['a'] = 1, mp['A'] = 1;
    mp['e'] = 1, mp['E'] = 1;
    mp['i'] = 1, mp['I'] = 1;
    mp['o'] = 1, mp['O'] = 1;
    mp['u'] = 1, mp['U'] = 1;
    
    vector<char> vowel;
    vector<int> idx;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (mp[c]) {
            vowel.push_back(c);
            idx.push_back(i);
        }
    }
    sort(vowel.begin(), vowel.end());

    for (int i = 0; i < idx.size(); i++) {
        int j = idx[i];
        s[j] = vowel[i];
    }
    return s;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
