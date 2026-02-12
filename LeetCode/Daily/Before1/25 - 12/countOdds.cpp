#include <bits/stdc++.h>
using i64 = long long;
using namespace std;


int countOdds(int low, int high) {
    low -= low % 2;
    high += high % 2;
    return (high - low) / 2;    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
