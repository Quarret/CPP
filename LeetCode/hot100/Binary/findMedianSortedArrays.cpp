#include <bits/stdc++.h>
using ll = long long;
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<>> right;

    for (int x : nums1) {
        if (left.size() == right.size()) {
            right.push(x);
            left.push(right.top());
            right.pop();
        } else {
            left.push(x);
            right.push(left.top());
            left.pop();
        }
    }

    for (int x : nums2) {
        if (left.size() == right.size()) {
            right.push(x);
            left.push(right.top());
            right.pop();
        } else {
            left.push(x);
            right.push(left.top());
            left.pop();
        }
    }

    return left.size() == right.size() ? 0.5 * (left.top() + right.top()) : 1.0 * left.top();
}

// 双指针, 中位数是可以将数组分成两等分的数字
double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
    if (a.size() > b.size()) { // 保证第一组下标 i 可以从 0 开始
        swap(a, b);
    }

    int m = a.size(), n = b.size();
    a.insert(a.begin(), INT_MIN);
    b.insert(b.begin(), INT_MIN);
    a.push_back(INT_MAX / 2);
    b.push_back(INT_MAX / 2);

    // int i = 0, j = (m + n + 1) / 2;
    // while (1) {
    //     if (a[i] <= b[j + 1] && a[i + 1] >= b[j]) {
    //         int mx = max(a[i], b[j]);
    //         int mn = min(a[i + 1], b[j + 1]);
    //         return (m + n) % 2 ? mx : (mx + mn) / 2.0;
    //     }
    //     i++;
    //     j--;
    // }

    // 由于证明了唯一性, 如果 a[i + 1] <= b[j] 不满足则结束循环
    // while (a[i + 1] <= b[j]) {
    //     i++;
    //     j--;
    // }

    // 由于 i 越小 a[i] <= b[j + 1] 越满足, 具有单调性可以二分
    int l = 0, r = m + 1;
    while (l + 1 < r) {
        int i = l + (r - l) / 2;
        int j = (m + n + 1) / 2 - i;
        if (a[i] <= b[j + 1]) {
            l = i;
        } else {
            r = i;
        }
    }

    int i = l;
    int j = (m + n + 1) / 2 - i;
    int mx = max(a[i], b[j]);
    int mn = min(a[i + 1], b[j + 1]);
    return (m + n) % 2 ? mx : (mx + mn) / 2.0;    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}