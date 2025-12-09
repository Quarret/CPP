#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int maxSumDivThree(vector<int>& nums) {
    int n = nums.size();
    int num1 = INT_MAX, num2 = INT_MAX;
    int s = reduce(nums.begin(), nums.end());

    if (s % 3 == 0) {
        return s;
    }

    vector<int> a, b;

    for (int x : nums) {
        if (x % 3 == 1) {
            num1 = min(num1, x);
            a.push_back(x);
        } else if (x % 3 == 2) {
            num2 = min(num2, x);
            b.push_back(x);
        }
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (s % 3 == 1) {
        return b.size() >= 2 ? max(s - num1, s - b[0] - b[1]) : s - num1;
    } else if (s % 3 == 2) {
        return a.size() >= 2 ? max(s - num2, s - a[0] - a[1]) : s - num2;
    }

    return s;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
