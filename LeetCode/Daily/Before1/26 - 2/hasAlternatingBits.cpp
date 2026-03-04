#include <bits/stdc++.h>
using ll = long long;
using namespace std;

bool hasAlternatingBits(int n) {
    uint32_t x = n ^ (n >> 1);
    return ((x + 1) & x) == 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}