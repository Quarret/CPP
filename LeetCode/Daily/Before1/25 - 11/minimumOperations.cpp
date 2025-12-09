#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int minimumOperations(vector<int>& nums) {
    int ans = 0;
    for (int x : nums) {
        if (x % 3) {
            ans++;
        }
    }
    
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
