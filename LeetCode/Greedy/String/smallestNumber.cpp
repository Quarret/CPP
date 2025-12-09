#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

string smallestNumber(string pattern) {
    int n = pattern.size();
    string ans = "";
    for (int i = 1; i <= n + 1; i++) {
        ans += '0' + i;
    }
    
    for (int i = 0; i < n; i++) {
        if (pattern[i] == 'I') continue;
        int end = i;
        while (end < n && pattern[end] == 'D') {
            end++;
        }

        
        string s1 = ans.substr(i, end - i + 1);
        ranges::reverse(s1);
        ans.replace(i, end - i + 1, s1);
        i = end;
    }
    
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
