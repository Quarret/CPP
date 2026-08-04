#include <bits/stdc++.h>
using ll = long long;
using namespace std;


vector<int> separateDigits(vector<int>& nums) {
    int n = nums.size();
    
    vector<int> ans;
    for (int x : nums) {
        vector<int> tmp;
        while (x) {
            tmp.push_back(x % 10);
            x /= 10;
        }
        ranges::reverse(tmp);
        ans.insert(ans.end(), tmp.begin(), tmp.end());
    }
    
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}