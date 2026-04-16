#include <bits/stdc++.h>
using ll = long long;
using namespace std;



bool uniformArray(vector<int>& nums1) {
    vector<int> odd, even;
    for (int x : nums1) {
        if (x % 2) odd.push_back(x);
        else even.push_back(x);
    }


    int n = nums1.size();
    int ok_odd = 1, ok_even = 1;
    for (int i = n - 1; i >= 0 ; i--) {
        int x = nums1[i];
        if (x % 2 && odd.size() == 1) ok_even = 0;
        if (x % 2 == 0 && odd.empty()) ok_odd = 0;
    }

    return ok_odd || ok_even;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}