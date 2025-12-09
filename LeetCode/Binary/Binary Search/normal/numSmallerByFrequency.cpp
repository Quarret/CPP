#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int f(string s) {
    char minn = 'z';
    int n = s.size(), ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] < minn) {
            minn = s[i];
            ans = 1;
        } else if (s[i] == minn) {
            ans++;
        }
    }

    return ans;
}
int check(vector<int>& nums, int k) {
    int l = 0, r = nums.size() - 1, mid = 0;

    while (l <= r) {
        mid = l + (r - l) / 2;
        if (nums[mid] < k) l = mid + 1;
        else r = mid - 1;
    }

    return l;
}
vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
    int n = queries.size(), m = words.size();
    vector<int> num1(n, 0), num2(m, 0), ans(n, 0);
    
    for (int i = 0; i < n; i++) num1[i] = f(queries[i]);
    for (int i = 0; i < m; i++) num2[i] = f(words[i]);

    sort(num2.begin(), num2.end());

    for (int i = 0; i < n; i++) {
        ans[i] = m - check(num2, num1[i] + 1);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
