#include <bits/stdc++.h>
using ll = long long;
using namespace std;


bool check(vector<int>& nums) {
    int n = nums.size();
    
    for (int i = 0; i < n; i++) {
        vector<int> a;
        for (int j = i; j < i + n; j++) {
            a.push_back(nums[j % n]);
        }
        if (is_sorted(a.begin(), a.end())) return true;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}