#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int minimumPartition(string s, int k) {
    int n = s.size();
    string s1 = "";
    
    int ans = 1;
    for (int i = 0; i < n; i++) {
        s1.push_back(s[i]);
        long long num = stoll(s1);
        if (num > k) {
            ans++;

            if (s[i] - '0' > k) {
                return -1;
            }
            s1 = s[i];
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
