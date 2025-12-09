#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int first(int x) {
    while (x > 10) x /= 10;

    return x;
}

int countBeautifulPairs(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> mp;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int num = nums[i] % 10;

        if (num == 2 || num == 4 || num == 38) {
            ans += mp[1];
            ans += mp[3];
            ans += mp[5];
            ans += mp[7];
            ans += mp[9];
        } else if (num == 3 || num == 9) {
            ans += mp[1];
            ans += mp[2];
            ans += mp[4];
            ans += mp[5];
            ans += mp[7];
            ans += mp[8];
        } else if (num == 6) {
            ans += mp[1];
            ans += mp[5];
            ans += mp[7];
        } else if (num == 1) {
            ans += mp[2];
            ans += mp[3];
            ans += mp[4];
            ans += mp[5];
            ans += mp[6];
            ans += mp[7];
            ans += mp[8];
            ans += mp[9];
        } else if (num == 5) {
            ans += mp[1];
            ans += mp[2];
            ans += mp[3];
            ans += mp[4];
            ans += mp[6];
            ans += mp[7];
            ans += mp[8];
            ans += mp[9];
        } else if (num == 7) {
            ans += mp[1];
            ans += mp[2];
            ans += mp[3];
            ans += mp[4];
            ans += mp[5];
            ans += mp[6];
            ans += mp[8];
            ans += mp[9];
        }

        mp[first(nums[i])]++;
    }

    return ans;
}
/*
根号的判断质数写法
*/
int countBeautifulPairs(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> mp;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int num = nums[i] % 10;

        for (int j = 1; j <= 9; j++) {
            if (gcd(j, num) == 1) ans += mp[j];
        }

        mp[first(nums[i])]++;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
