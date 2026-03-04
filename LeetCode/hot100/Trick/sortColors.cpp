#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void sortColors(vector<int>& nums) {
    int n = nums.size();
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] > nums[j]) {
                swap(nums[i], nums[j]);
            }
        }
    }
}


void sortColors(vector<int>& nums) {
    int p0 = 0, p1 = 0;
    for (int i = 0; i < nums.size(); i++) {
        int x = nums[i];
        nums[i] = 2;
        if (x <= 1) {
            nums[p1++] = 1;
        }
        if (x == 0) {
            nums[p0++] = 0;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}