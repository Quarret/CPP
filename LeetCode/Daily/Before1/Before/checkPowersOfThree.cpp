#include <bits/stdc++.h>
using ll = long long;
using namespace std;

bool checkPowersOfThree(int n) {
    while (n) {
        if (n % 3 > 1) return false;
        n /= 3;
    }
    
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
