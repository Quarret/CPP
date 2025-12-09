#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int minLengthAfterRemovals(string s) {
    int cnt0 = 0, cnt1 = 0, n = s.size();
    for (char c : s) {
        (c == 'a' ? cnt0 : cnt1) += 1;
    }

    return n - 2 * min(cnt0, cnt1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
