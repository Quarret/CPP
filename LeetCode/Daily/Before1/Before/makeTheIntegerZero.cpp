#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int makeTheIntegerZero(int num1, int num2) {
    long long val = num1, ans = -1, k = 0;

    while (1) {
        val = 1LL * val - 1LL * k * num2;
        if (val < 0 || val >= (1LL << 61)) break;
        int cnt = __builtin_popcountll(val);
    
        if (cnt == k) {
            ans = k;
            break;
        }
        
        k++;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
