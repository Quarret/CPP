#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int minimumBuckets(string hamsters) {
    int n = hamsters.size();
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (hamsters[i] == 'H') {
            if ((i - 1 >= 0 && hamsters[i - 1] == 'B') || (i + 1 < n && hamsters[i + 1] == 'B')) {
                continue;
            }

            if (i + 1 < n && hamsters[i + 1] == '.') {
                hamsters[i + 1] = 'B';
                ans++;
                continue;
            }

            if (i - 1 >= 0 && hamsters[i - 1] == '.') {
                hamsters[i - 1] = 'B';
                ans++;
                continue;
            }

            return -1;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
