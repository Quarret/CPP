#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int subarrayBitwiseORs(vector<int>& arr) {
    int n = arr.size(), ans = 0;
    unordered_map<int, int> mp;
    
    for (int i = 0; i < n; i++) {
        if (mp.find(arr[i]) != mp.end()) ans++;
        mp[arr[i]] = 1;

        for (int j = i - 1; j >= 0 && (arr[j] | arr[i]) != arr[j]; j--) {
            arr[j] |= arr[i];
            if (mp.find(arr[j]) != mp.end()) ans++;
            mp[arr[j]] = 1;
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
