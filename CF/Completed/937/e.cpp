#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool cmp(pair<int, int> x, pair<int, int> y) {
    return x.first < y.first;
}
void solve() {
    int n;
    string s;

    cin >> n;
    cin >> s;

    vector<int> a;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            a.push_back(i);
        }
    }

    vector< pair<int, int> > pa;
    for (int i : a) {
        int cnt1 = 0, cnt2 = 0;
        string tmp = s.substr(0, i), s1, s2;
        for (int j = 1; j <= n / i; j++) {
            s1 += tmp; 
        }

        for (int j = 0; j < n; j++) {
            if (s1[j] != s[j]) {
                cnt1++;
            }
        }

        tmp = s.substr(n - i, i);
        for (int j = 1; j <= n / i; j++) {
            s2 += tmp; 
        }

        for (int j = 0; j < n; j++) {
            if (s2[j] != s[j]) {
                cnt2++;
            }
        }
        
        if (cnt1 <= 1 || cnt2 <= 1) {
        pa.push_back(make_pair(i , min(cnt1, cnt2)));
        }
    }

    sort(pa.begin(), pa.end(), cmp);

    cout << pa[0].first << '\n';

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
