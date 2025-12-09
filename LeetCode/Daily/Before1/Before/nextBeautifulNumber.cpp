#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int nextBeautifulNumber(int n) {
    while (1) {
        n++;

        int cnt[10]{};
        for (int x = n; x > 0; x /= 10) {
            cnt[x % 10]++;
        }

        bool ok = true;
        for (int x = n; x > 0; x /= 10) {
            if (cnt[x % 10] != x % 10) {
                ok = false;
                break;
            }
        }

        if (ok) {
            return n;
        }
    }       
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
