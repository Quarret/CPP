#include<bits/stdc++.h>
 
using namespace std;
typedef long long ll;
ll head, endd, t, n, a[2005], b[2005];
 
void solve1() {
    cout << 1;
    head = (head + 1) % n;
    endd = (endd + 1) % n;
}
 
void solve2() {
    cout << 2;
    swap(a[head], a[(head + 1) % n]);
    head = (head + 1) % n;
    endd = (endd + 1) % n;
}
 
void solve() {
    cin>>n;
    for (int i = 0; i < n; i++) cin>>a[i];
    for (int i = 0; i < n; i++) cin>>b[i];
    head = 0, endd = n - 1;
    for (int i = 1; i < n; i++) {
        while (b[i] != a[head]) solve1();
        while (b[i - 1] != a[endd]) solve2();
        solve1();
    }
}
 
int main() {
    cin>>t;
    while (t--) {
        solve();
        cout << endl;
    }
    return 0;
}