#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int rangeBitwiseAnd(int left, int right) {
    int len = max(__bit_width(left), 1);
    
    if (right >= (1LL << len)) return 0;

    unsigned long long ans = 0;
    for (int i = len - 1; i >= 0; i--) {
        if ((left & (1 << i)) == (1 << i)) ans |= (1 << i);
        else if (right >= (ans | (1 << i)) ) break;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
