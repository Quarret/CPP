#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

string lexSmallest(string s) {
    string ans = s;
    int n = s.size();
    for (int k = 1; k <= n; k++) {
        string s1 = s.substr(0, k), s2 = s.substr(k);
        string s3 = s.substr(0, n - k), s4 = s.substr(n- k);
        reverse(s1.begin(), s1.end());
        reverse(s4.begin(), s4.end());
        ans = min({ans, s1 + s2, s3 + s4});
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
