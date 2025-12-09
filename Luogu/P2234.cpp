#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, num;
ll ans;
int a[2000005] = {0};

void solve() {
    cin >> n;
    cin >> num;
    a[num + 1000000] = 1;
    ans += num;
    n--;

    while (n--) {
        cin >> num;
        int num1 = 0;
        while (1) {
            if (num + 1000000 - num1 < 0) {
               if (a[num + 1000000 + num1] == 1) {
                ans += num1;
                break;
               }
            } else if (num + 1000000 + num1 >2000000) {
               if (a[num + 1000000 - num1] == 1) {
                ans += num1;
                break;
               }
            } else {
                if(a[num + 1000000 + num1] == 1 || a[num + 1000000 - num1] == 1) {
                    ans += num1;
                    break;
                }
            }
            num1++;
        }
        a[num + 1000000] = 1;
        //cout << ans << '\n';
    }

    cout << ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    solve();
}
