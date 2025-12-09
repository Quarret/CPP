#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

string getSmallestString(int n, int k) {
    string ans(n, 'a');
    k -= n;
    for (int i = n - 1; i >= 0 && k; i--) {
        ans[i] += min(25, k);
        k -= min(25, k);
    }
    
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
