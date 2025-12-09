#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int evenNumberBitwiseORs(vector<int>& nums) {
    int ans = 0;
    for (int x : nums) {
        if (x % 2 == 0) {
            ans |= x;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
