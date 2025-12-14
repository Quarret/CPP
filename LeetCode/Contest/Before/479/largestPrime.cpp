#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<int> nums;
const int MX = 500001;
bool check(int x) {
    if (x == 1) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
};

int init = [] {
    long long s = 0;
    unordered_map<int, int> mp = {{0, 1}};
    for (int m = 2; m < MX; m++) {
        if (!check(m)) continue;
        if (mp.contains(m)) {
            nums.push_back(m);
        }
        s += m;
        mp[s] = 1;        
    }
    return 0;
}();
class Solution {
public:
int largestPrime(int n) {
    if (n == 1) return 0;

    int idx = upper_bound(nums.begin(), nums.end(), n) - nums.begin();
    return idx == 0 ? 2 : nums[idx - 1];
}
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
