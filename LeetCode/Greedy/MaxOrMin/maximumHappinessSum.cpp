#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

long long maximumHappinessSum(vector<int>& happiness, int k) {
    sort(happiness.begin(), happiness.end(), greater());
    
    long long ans = 0;
    for (int i = 0; i < k; i++) {
        ans += 1LL * max(happiness[i] - i, 0);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
