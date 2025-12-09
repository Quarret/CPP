#include <bits/stdc++.h>
using ll = long long;
using namespace std;

bool canPartition(vector<int>& nums) {
    int s = reduce(nums.begin(), nums.end()), n = nums.size();
    if (s % 2) return false;
    s /= 2;
    
    vector<int> f(s + 1);
    f[0] = 1;
    for (int x : nums) {
        for (int j = s; j >= x; j--) {
            f[j] |= f[j - x];
        }
    }

    return f[s];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
