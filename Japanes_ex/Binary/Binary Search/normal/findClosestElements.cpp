#include <bits/stdc++.h>
using ll = long long;
using namespace std;
vector<int> arr = {1,2,3,4,5};
int check(vector<int>& arr, int x) {
    int l = 0, r = arr.size() - 1, mid = 0;

    while (l <= r) {
        mid = l + (r - l) / 2;
        if (arr[mid] < x) l = mid + 1;
        else r = mid - 1;
    }

    return l;
}
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int r = check(arr, x), n = arr.size();
    int l = r - 1;
    vector<int> ans;

    while (k--) {
        if (l < 0) {
            ans.push_back(arr[r]);
            r++;
        } else if (r == n) {
            ans.insert(arr.begin(), arr[l]);
            l--;
        } else {
            if (x - arr[l] == arr[r] - x) {
                ans.insert(ans.begin(), arr[l--]);
            }
            else if (x - arr[l] > arr[r] - x) ans.push_back(arr[r++]);
            else {
                ans.insert(ans.begin(), arr[l--]);
            }
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    findClosestElements(arr, 4, 3);

    return 0;
}
