#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct node {
    int score;
    int rank[101];
};
typedef pair<string, node> Pair;
map<string, node> mp;
bool cmp1(Pair const &x, Pair const &y) {
    if (x.second.score > y.second.score) return 1;
    else if (x.second.score == y.second.score) {
        if (x.second.rank[1] > y.second.rank[1]) return 1;
        else if (x.second.rank[1] == y.second.rank[1]) {
            for (int i = 2; i <= 100; i++) {
                if (x.second.rank[i] > y.second.rank[i]) return 1;
                else if (x.second.rank[i] < y.second.rank[i]) return 0;
            }
        } else return 0;
    } else return 0;
}

bool cmp2(Pair const &x, Pair const &y) {
    if (x.second.rank[1] > y.second.rank[1]) return 1;
    else if (x.second.rank[1] == y.second.rank[1]) {
        if (x.second.score > y.second.score) return 1;
        else if (x.second.score == y.second.score) {
            for (int i = 2; i <= 100; i++) {
                if (x.second.rank[i] > y.second.rank[i]) return 1;
                else if (x.second.rank[i] < y.second.rank[i]) return 0;
            }
        } else return 0;
    } else return 0;
}
void solve() {
    int t;
    cin >> t;

    int score[11] = {0, 25, 18, 15, 12, 10, 8, 6, 4, 2, 1};

    while (t--) {
        int n;
        cin >> n;
        string s;
        for (int i = 1; i <=n; i++) {
            cin >> s;
            mp[s].rank[i]++;
            if (i >= 1 && i <= 10) {
                mp[s].score += score[i];
            }
        }
    }

    vector<Pair> a1(mp.begin(), mp.end()), a2(mp.begin(), mp.end());
    sort(a1.begin(), a1.end(), cmp1);
    sort(a2.begin(), a2.end(), cmp2);
    cout << a1[0].first << '\n';
    cout << a2[0].first << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    
    solve();
}
