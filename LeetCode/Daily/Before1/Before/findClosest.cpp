#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int findClosest(int x, int y, int z) {
    int d1 = abs(x - z), d2 = abs(y - z);
    
    if (d1 == d2) return 0;
    return d1 > d2 ? 2 : 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
