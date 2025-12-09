#include <bits/stdc++.h>
using ll = long long;
using namespace std;

bool hasTrailingZeros(vector<int>& nums) {
    int cnt = 0;
    for (int x: nums) {
        if (x % 4 == 0) cnt++;
    }       

    return cnt >= 2;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
