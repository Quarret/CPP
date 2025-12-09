#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

string getSmallestString(string s) {
    int n = s.size();
    string ans = s;
    
    for (int i = 0; i < n - 1; i++) {
        int c1 = s[i] - '0', c2 = s[i + 1] - '0';
        string tmp = s;
        if (c1 % 2 == c2 % 2) {
            swap(tmp[i], tmp[i + 1]);
        }
        ans = min(ans, tmp);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
