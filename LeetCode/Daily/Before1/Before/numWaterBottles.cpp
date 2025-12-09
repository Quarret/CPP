#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int numWaterBottles(int numBottles, int numExchange) {
    int empty = numBottles, ans = numBottles;
    
    while (empty >= numExchange) {
        ans += empty / numExchange;
        empty = empty / numExchange + (empty % numExchange);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
