#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int maximumXOR(vector<int>& nums) {
    int ans = 0;
    for (int i = 0; i <= 31; i++) {
        int cnt = 0;
        for (int x: nums) {
            if (((1 << i) & x) == 1 << i) {
                ans += 1 << i;
                break;
            }
        }
        //if (cnt != 0) ans += 1 << i;
    }

    return ans;
}

/*
只要数位上有1即可
num & (num ^ x)只能减小数位上的1，不能增加1
*/

int maximumXOR(vector<int>& nums) {
    int ans = 0;
    for (int x: nums) ans |= x;
    
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
