#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minBitFlips(int start, int goal) {
    int cnt = 0;
    for (int i = 0; i <= 31; i++) {
        if ((start & (1 << i)) != (goal & (1 << i))) cnt++;
    }

    return cnt;   
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
