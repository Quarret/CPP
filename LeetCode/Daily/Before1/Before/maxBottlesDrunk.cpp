#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int maxBottlesDrunk(int numBottles, int numExchange) {
    int ans = numBottles, empty = numBottles;
    
    while (empty >= numExchange) {
        ans += 1;
        empty -= numExchange - 1;
        numExchange++;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
