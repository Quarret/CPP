#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int minOperations(int k) {
    int ans = INT_MAX;
    for (int i = 0; i < k; i++) {
        int x = i + 1;
        ans = min(ans, i + (k - 1) / x);
    }
    
    return ans;
}

// 数学
int minOperations(int k) {
    int rt = max((int) sqrt(k - 1), 1);
    return min(rt - 1 + (k - 1) / rt, rt + (k - 1) / (rt + 1));        
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
