#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct node{
    int score;
    int tball;
    int ball;
};
typedef pair<string, node> Pair;

map<string, node> mp;

bool cmp(Pair const &x, Pair const & y) {
    if (x.second.score > y.second.score) return 1;
    else if (x.second.score == y.second.score) {
        if (x.second.tball > y.second.tball) return 1;
        else if (x.second.tball == y.second.tball) {
            return x.second.ball > y.second.ball;
        } else return 0;
    } else return 0;
}
void solve() {
    int n;
    cin >> n;
    string tmp;

    for (int i = 0; i < n; i++) {
        cin >> tmp; 
    }
    
    int N = n * (n - 1) / 2;
    getline(cin, tmp);
    for (int i = 0; i < N; i++) {
        getline(cin, tmp);
        //cout << tmp << '\n';
        int pos1 = tmp.find('-');
        int pos2 = tmp.find(' ');
        int pos3 = tmp.find(':');
        
        string n1, n2;
        int num1, num2;
        n1 = tmp.substr(0, pos1);
        n2 = tmp.substr(pos1 + 1, pos2 - pos1 - 1);
        num1 = stoi(tmp.substr(pos2 + 1, pos3 - pos2));
        num2 = stoi(tmp.substr(pos3 + 1, tmp.size() - 1 - pos3));
        //cout << n1 << ' ' << n2 << ' ' << num1 << ' ' << num2 << '\n';

        if (num1 > num2) {
            mp[n1].score += 3;
            mp[n1].tball += num1 - num2;
            mp[n2].tball += num2 - num1;
            mp[n1].ball += num1;
            mp[n2].ball += num2;
        } else if (num1 == num2) {
            mp[n1].score += 1;
            mp[n2].score += 1;
            mp[n1].ball += num1;
            mp[n2].ball += num2;
        } else {
            mp[n2].score += 3;
            mp[n2].tball += num2 - num1;
            mp[n1].tball += num1 - num2;
            mp[n1].ball += num1;
            mp[n2].ball += num2;
        }
    }
    
    vector<Pair> a(mp.begin(), mp.end());
    // for (auto &it : mp) {
    //     cout << it.first << ' ' << it.second.score << ' ' << it.second.tball << ' ' << it.second.ball << '\n';
    // }
    sort(a.begin(), a.end(), cmp);
    vector<string> b;
    for (int i = 0; i < n / 2; i++) {
        b.push_back(a[i].first);
    }
    sort(b.begin(),b.end());

    for (int i = 0; i < n / 2; i++) {
        cout << b[i] << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    solve();
}
