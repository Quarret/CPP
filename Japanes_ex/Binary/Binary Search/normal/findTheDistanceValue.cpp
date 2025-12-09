#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int check(vector<int>& arr2, int k) {
    int l = 0, r = arr2.size() - 1, mid = 0;

    while (l <= r) {
        mid = l + (r - l) / 2;
        if (arr2[mid] < k) l = mid + 1;
        else r = mid - 1;
    }

    return l;
}

int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
    sort(arr2.begin(), arr2.end());
    int n = arr1.size(), num1 = 0, num2 = 0, ans = 0;
    
    for (int i = 0; i < n; i++) {
        num1 = check(arr2, arr1[i] - d);
        num2 = check(arr2, arr1[i] + d + 1) - 1;
        ans += (num2 - num1) < 0;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
