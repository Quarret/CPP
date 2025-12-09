#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minOperations(string s) {
    sort(s.begin(), s.end());

    int ans = 0;
    for (char c : s) {
        if (c != 'a') {
            ans = 'z' - c + 1;
            return ans;
        }
    }

    return ans;
}

int minOperations(string s) {
    int mp[26]{};
    for (char c : s) mp[c - 'a']++;
    for (int i = 1; i < 26; i++) {
        if (mp[i] > 0) return 26 - i;
    }
    
    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
