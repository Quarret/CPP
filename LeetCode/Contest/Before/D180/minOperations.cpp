#include <bits/stdc++.h>
using ll = long long;
using namespace std;


vector<int> prime;
const int N = 200001;
vector<int> vis(N, 0);
int init = [] {
    for (int i = 2; i <= 200000; i++) {
        if (!vis[i]) prime.push_back(i);
        for (int j = i; j <= 200000; j += i) {
            vis[j] = 1;
        }
    }
    return 0;
}();

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st(prime.begin(), prime.end());

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            if (i % 2 == 0) {
                int idx = ranges::lower_bound(prime, x) - prime.begin();
                ans += prime[idx] - x;
            } else if (i % 2) {
                while (st.contains(x)) {
                    ans++;
                    x++;
                }
            }
        }

        return ans;
    }
};

// 埃氏筛
const int MX = 100004;
int not_prime[MX];

auto init = [] {
    not_prime[1] = 1;
    for (int i = 1; i * i < MX; i++) {
        if (!not_prime[i]) {
            for (int j = i * i; j < MX; j += i) {
                not_prime[j] = 1;
            }
        }
    }

    return 0;
}();

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];

            while (not_prime[x] != i % 2) {
                ans++;
                x++;
            }
        }

        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}