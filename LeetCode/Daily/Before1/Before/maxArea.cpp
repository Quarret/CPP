#include <bits/stdc++.h>
using ll = long long;
using namespace std;

// O(n ^ 2)需要搜索的状态
// 比较两边大小排除掉N个状态
int maxArea(vector<int>& height) {
    int l = 0, r = height.size() - 1;
    
    int ans = 0;
    while (l < r) {
        ans = max(ans, (r - l) * min(height[l], height[r]));
        if (height[l] < height[r]) {
            l++;
        } else {
            r--;
        }
    }
    
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
