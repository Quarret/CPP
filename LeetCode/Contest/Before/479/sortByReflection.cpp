#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

vector<int> sortByReflection(vector<int>& nums) {
    sort(nums.begin(), nums.end(), [&](int x, int y) {
        int num1 = x, num2 = y;
        int x1 = 0, y1 = 0;
        while (num1) {
            x1 = (x1 << 1) + (num1 & 1);
            num1 >>= 1; 
        }
        while (num2) {
            y1 = (y1 << 1) + (num2 & 1);
            num2 >>= 1;
        }

        if (x1 < y1) return true;
        else if (x1 == y1) {
            return x < y;
        } else {
            return false;
        }
    });
    
    return nums;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
