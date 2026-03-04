#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int scoreDifference(vector<int>& nums) {
    int p1 = 0, p2 = 0;
    int turn = 0, n = nums.size();
    for (int i = 0; i < n; i++) {
        turn ^= nums[i] % 2;
        turn ^= (((i + 1) % 6) == 0);
        (turn ? p2 : p1) += nums[i];
    }
    
    return p1 - p2;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}