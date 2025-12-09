#include <bits/stdc++.h>
using i64 = long long;
using namespace std;


const int MX = 1000001;
unordered_map<int, unordered_set<int>> d;
int init = [] {
    d[1].insert(1);
    for (int i = 2; i < MX; i++) {
        if (d[i].size()) continue; 
        for (int j = i; j < MX; j += i) {
            d[j].insert(i);
        }
    }

    return 0;
}();

class Solution {
public:
    int findValidSplit(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> last;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                last[1] = min(last[1], i);
                continue;
            }

            for (int x : d[nums[i]]) {
                last[x] = i;
            }
        }
        
        int end = -1;
        for (int i = 0; i < n - 1; i++) {
            for (int x : d[nums[i]]) {
                end = max(end, last[x]);
            }

            if (i == end) {
                return i;
            }
        }

        return -1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
