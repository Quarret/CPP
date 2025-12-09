#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> binanum;
int maxn = 100007;

bool check(int x) {
    if (x == 1) return 1;
    bool ans = 0;
    for (int i : binanum) {
        if (x % i == 0) {
            ans |= check(x / i); 
        }
    }

    return ans;
}

void solve() {
    int n;
    cin >> n;
    cout << (check(n) ? "YES" : "NO") << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    for (int i = 2; i < maxn; i++) {
        int curr = i;
        bool flag = 0;
        while (curr) {
            if (curr % 10 > 1) {
               flag = 1;
               break;
            }
            curr /= 10;
        }

        if (!flag) {
            binanum.push_back(i);
        }
    }

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
