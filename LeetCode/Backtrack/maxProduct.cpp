#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int maxProduct(string s) {
    int n = s.size();
    string s1, s2;
    
    int ans = 0;
    auto dfs = [&](this auto&& dfs, int i) -> void {
        if (i == n) {
            string s3 = s1, s4 = s2;
            reverse(s3.begin(), s3.end());
            reverse(s4.begin(), s4.end());

            if (s1 == s3 && s2 == s4) {
                ans = max(ans, (int)(s1.size() * s2.size()));
            }
            return;
        }

        dfs(i + 1);

        s1.push_back(s[i]);
        dfs(i + 1);
        s1.pop_back();

        s2.push_back(s[i]);
        dfs(i + 1);
        s2.pop_back();
    };

    dfs(0);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
