#include <bits/stdc++.h>
using ll = long long;
using namespace std;

struct node {
    string name;
    string s;
    int id;
    int num;
};
map<string, node> mp;
bool cmp(node x, node y) {
    if (x.num > y.num) return 1;
    else if (x.num == y.num) {
        return x.id < y.id;
    } else return 0;
}
int n;
void solve() {
    int num1, m;
    //cout << n << '\n';
    string tmp, mod, tmp1;
    getline(cin, tmp);
    for (int i = 0; i < n; i++) {
        getline(cin, tmp);
        mp[tmp].name = tmp;
        //cout << tmp << '\n';
        mp[tmp].s.push_back(' ');
        for (int i = 0; i < tmp.size(); i++) {
            if (tmp[i] >= 'A' && tmp[i] <= 'Z') {
                mp[tmp].s.push_back(tolower(tmp[i]));
            } else {
                mp[tmp].s.push_back(tmp[i]);
            }
        }
        mp[tmp].s.push_back(' ');
        mp[tmp].id = i;
        cin >> num1;
        //cout << num1 << '\n';
        mp[tmp].num = num1;
        getline(cin, tmp);
    }

    cin >> m;
    //cout << m << '\n';
    getline(cin, mod);
    for (int i = 0; i < m; i++) {
        getline(cin, mod);
        tmp1.clear();
        mod.push_back(' ');
        vector<string> moda;
        for (int j = 0; j < mod.size(); j++) {
            if (mod[j] == ' ') {
                moda.push_back(' ' + tmp1 + ' ');
                tmp1.clear();
            } else {
                tmp1 += tolower(mod[j]);
            }
        }

        //cout << mod << '\n';    
        vector<node> a;

        for (auto &it : mp) {
            for (int j = 0; j < moda.size(); j++)
            {
                if (it.second.s.find(moda[j]) == -1)
                {
                    break;
                }

                if (j == moda.size() - 1)
                {
                    a.push_back(it.second);
                }
            }
        }

        sort(a.begin(), a.end(), cmp);
        for (int j = 0; j < a.size(); j++) {
            cout << a[j].name << '\n';
        }
        
        cout << "***\n";
    }

    cout << "---" << '\n';
    mp.clear();
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie();
    
    while (1) {
        cin >> n;
        if (!n) {   
            return 0;
        }
        solve();
    }
}
