#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int sumOddLengthSubarrays(vector<int>& arr) {
    int n = arr.size();
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int l = i, r = n - i - 1;
        int l_odd = (l + 1) / 2, r_odd = (r + 1) / 2;
        int l_even = l / 2 + 1, r_even = r / 2 + 1;
        ans += arr[i] * l_odd * r_odd;
        ans += arr[i] * l_even * r_even;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}