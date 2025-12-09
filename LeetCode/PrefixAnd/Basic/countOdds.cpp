#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int countOdds(int low, int high) {
    int cnt = high - low + 1;

    if (low % 2 & low % 2) return cnt / 2 + 1;
    else if (low % 2 | high % 2) return cnt / 2;
    else return cnt / 2;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
