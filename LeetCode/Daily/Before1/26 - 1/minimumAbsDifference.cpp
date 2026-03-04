#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
    int n = arr.size();
    ranges::sort(arr);

    int mn = INT_MAX;
    for (int i = 0; i < n - 1; i++) {
        mn = min(mn, arr[i + 1] - arr[i]);
    }

    vector<vector<int>> ans;
    for (int i  = 0; i < n - 1; i++) {
        if (arr[i + 1] - arr[i] == mn) {
            ans.push_back({arr[i], arr[i + 1]});
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}