#include <bits/stdc++.h>
using ll = long long;
using namespace std;

map<pair<int, int>, vector<string> > mp1;
typedef pair<pair<int, int>, vector<string> > Pair; 
void solve() {
    int n, pos, num1, num2;
    std::cin >> n;
    string s, s1, s2;
    
    std::getline(std::cin, s);
    while (n--) {
        cin >> s >> num1 >> num2;
        pos = s.find(' ');
        s1 = s.substr(0, pos);
        mp1[make_pair(num1, num2)].push_back(s1);
    }

    vector<Pair> a(mp1.begin(), mp1.end());
    sort(a.begin(), a.end(), [&](Pair x, Pair y) {
        if (x.first.first < y.first.first) return 1;
        else if (x.first.first == y.first.first) {
            if (x.first.first < y.first.first) return 1;
            else return 0;
        } else return 0;
    });
    
    for (auto &it : a) {
        cout << it.first.first << ' ' << it.first.second << ' ';
        for (auto &it1 : it.second) {
            cout << it1 << ' ';
        }
        cout << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    solve();
}
