#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minImpossibleOR(vector<int>& nums) {
    int len = 0;
    sort(nums.begin(), nums.end());

    for (int x : nums) {
        if (x == (1 << len)) len++;
    }

    return (1 << len);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
