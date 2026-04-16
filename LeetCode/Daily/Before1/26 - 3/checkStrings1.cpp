#include <bits/stdc++.h>
using ll = long long;
using namespace std;

bool checkStrings(string s1, string s2) {
    unordered_map<char, int> s1_odd, s1_even;
    unordered_map<char, int> s2_odd, s2_even;
    for (int i = 0; i < s1.size(); i++) {
        char c =  s1[i];
        if (i % 2) s1_odd[c]++;
        else s1_even[c]++;
    }

    for (int i = 0; i < s2.size(); i++) {
        char c =  s2[i];
        if (i % 2) s2_odd[c]++;
        else s2_even[c]++;
    }

    return s1_odd == s2_odd && s1_even == s2_even;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}