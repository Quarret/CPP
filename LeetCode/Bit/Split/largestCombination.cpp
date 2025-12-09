#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int largestCombination(vector<int>& candidates) {
    int ans = 0;
    int cnt[35]{};
    
    for (int i = 0; i <= 31; i++) {
        for (int x : candidates) {
            if ((x & (1 << i)) == (1 << i)) ans = max(ans, ++cnt[i]);
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
