#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int minFlips(string target) {
    int ans = 0;
    for (char c : target) {
        if (((c - '0') ^ (ans % 2)) == 1) {
            ans++;
        }
    }
    
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
