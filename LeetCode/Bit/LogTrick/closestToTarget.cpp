#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int closestToTarget(vector<int>& arr, int target) {
    int n = arr.size(), ans = INT32_MAX;
    
    for (int i = 0; i < n; i++) {
        ans = min(ans, abs(target - arr[i]));

        for (int j = i - 1; j >= 0 && (arr[j] & arr[i]) != arr[j]; j--) {
            arr[j] &= arr[i];
            ans = min(ans, abs(target - arr[j]));
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
