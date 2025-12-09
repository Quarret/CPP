#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minimumRecolors(string blocks, int k) {
    int n = blocks.size(), ans = 105, num = 0;
    for (int i = 0; i < n; i++) {
        if (blocks[i] == 'W') num++;

        if (i < k - 1) continue;

        ans = min(ans, num);
        if (blocks[i - k + 1] == 'W') num--;
    }       

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
