#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minOperations(string s) {
    int cnt1 = 0, cnt2 = 0, mask = 0;
    for (char c : s) {
        cnt1 += (c & 1) == mask ? 0 : 1;
        cnt2 += (c & 1) == mask ? 1 : 0; 
        mask ^= 1;
    }

    return min(cnt1, cnt2);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}