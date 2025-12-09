#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minimumDeleteSum(string s1, string s2) {
    int n = s1.size(), m = s2.size();
    vector<int> f(m + 1);
    
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int topleft = f[0];
        sum += s1[i];
        for (int j = 0; j < m; j++) {
            int tmp = f[j + 1];
            f[j + 1] = s1[i] == s2[j] ? topleft + 2 * s1[i] : max(f[j], f[j + 1]);
            topleft = tmp;
        }
    }

    for (char c : s2) sum += c;
    return sum - f[m];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
