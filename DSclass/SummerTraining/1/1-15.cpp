#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct node {
    int first;
    int second;
};
typedef pair<string, node> Pair;
bool cmp(Pair const &x, Pair const &y) {
        if (x.second.first > y.second.first) return 1;
        else if (x.second.first == y.second.first) {
            return x.second.second > y.second.second;
        } else return 0;
}
map<string, node> mp;
void solve() {
    int num = 12;
    string s1, s2, s3;
    int num1, num2; 
    
    while(num--) {
        cin >> s1 >> num1 >> s2 >> num2 >> s3;
        if (num1 > num2) {
            mp[s1].first += 3;
            mp[s1].second += num1 - num2;
            mp[s3].second += num2 - num1;
        } else if (num1 == num2) {
            mp[s1].first += 1;
            mp[s3].first += 1;
        } else if (num1 < num2) {
            mp[s3].first += 3;
            mp[s3].second += num2 - num1;
            mp[s1].second += num1 - num2;
        }
    }
    
    vector<Pair> a(mp.begin(), mp.end());
    sort(a.begin(), a.end(), cmp);
    for (int i = 0; i < 2; i++) {
        cout << a[i].first << ' ';
    }
    cout << '\n';
    mp.clear();
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
