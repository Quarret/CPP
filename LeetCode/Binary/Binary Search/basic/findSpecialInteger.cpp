#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int check(vector<int>& arr, int k) {
    int l = 0, r = arr.size() - 1, mid = 0;

    while (l <= r) {
        mid = l + (r - l) / 2;
        if (arr[mid] < k) l = mid + 1;
        else r = mid - 1;
    }

    return l;
}
int findSpecialInteger(vector<int>& arr) {
    int l = arr[0], r = arr.back(), mid = l + (r - l) / 2, n = arr.size();
    
    int num1 = check(arr, mid);
    int num2 = check(arr, mid + 1) - 1;

    while (num2 - num1 < n / 4) {
        
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
