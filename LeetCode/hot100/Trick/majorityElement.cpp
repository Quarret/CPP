#include <bits/stdc++.h>
using ll = long long;
using namespace std;

// 擂台法
int majorityElement(vector<int>& nums) {
    int ans = 0, hp = 0;
    for (int x : nums) {
        if (hp == 0) {
            ans = x;
            hp++;
        } else {
            hp += ans == x ? 1 : -1;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}