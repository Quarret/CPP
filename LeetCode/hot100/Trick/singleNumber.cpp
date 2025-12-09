#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int singleNumber(vector<int>& nums) {
    int ans = 0;
    for (int x : nums) ans ^= x;

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
