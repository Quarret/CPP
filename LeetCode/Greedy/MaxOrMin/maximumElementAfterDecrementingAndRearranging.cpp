#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    arr[0] = 1;
    int ans = arr[0], n = arr.size();
    for (int i = 1; i < n; i++) {
        if (arr[i - 1] < arr[i]) {
            arr[i] = arr[i - 1] + 1;
        }
        ans = max(ans, arr[i]);
    }
    
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
