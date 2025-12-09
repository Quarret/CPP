#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {
    int n = arr.size();
    int l = -1, r = n - 1, mid = 0;

    while (l + 1 < r) {
        mid = l + (r - l) / 2;
        (arr[mid] > arr[mid + 1] ? r : l) = mid;
    }

    return r;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
