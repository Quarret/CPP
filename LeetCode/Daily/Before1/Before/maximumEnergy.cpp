#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int maximumEnergy(vector<int>& energy, int k) {
    int n = energy.size();
    vector<int> f(n + k, 0);
    
    int ans = -1e9;
    for (int i = n - 1; i >= 0; i--) {
        f[i] = f[i + k] + energy[i];
        ans = max(ans, f[i]);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
