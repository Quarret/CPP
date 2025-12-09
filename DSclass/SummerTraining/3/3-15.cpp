#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {
    string s, tmp, tmp1, tmp2;
    cin >> s;
    //cout << s << '\n';
    
    set<string> s1, s2, s3, s4, s5;

    sort(s.begin(), s.end());
    
    int cnt = 1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] != s[i - 1]) {
            cnt = 1;
        } else cnt++;

        if (cnt == 1) {
                tmp.push_back(s[i - 1]);
                s1.insert(tmp);
                tmp.clear();
        }
        else if (cnt == 2)
        {
            tmp.push_back(s[i - 1]);
            tmp.push_back(s[i - 1]);
            s2.insert(tmp);
            tmp.clear();
        }
        else if (cnt == 3)
        {
            tmp.push_back(s[i - 1]);
            tmp.push_back(s[i - 1]);
            tmp.push_back(s[i - 1]);
            s3.insert(tmp);
            tmp.clear();
        }
        else if (cnt == 4)
        {
            tmp.push_back(s[i - 1]);
            tmp.push_back(s[i - 1]);
            tmp.push_back(s[i - 1]);
            tmp.push_back(s[i - 1]);
            s4.insert(tmp);
            tmp.clear();
        }
    }
    tmp.push_back(s.back());
    s1.insert(tmp);
    
    tmp1.push_back(s[0]);
    for (int i = 1; i < s.size(); i++) {
        if (s[i - 1] != s[i]) {
            tmp1.push_back(s[i]);
        }
    }
    //cout << tmp1 << '\n';

    if (tmp1.find("12345") != -1) {
        s5.insert("12345");
    } 
    if (tmp1.find("23456") != -1) {
        s5.insert("23456");
    } 
    if (tmp1.find("34567") != -1) {
        s5.insert("34567");
    } 
    if (tmp1.find("45678") != -1) {
        s5.insert("45678");
    } 
    if (tmp1.find("56789") != -1) {
        s5.insert("56789");
    }
    

    while (cin >> tmp2) {
        //cout << tmp2 << '\n';
        vector<string> ans;
        if (tmp2.size() == 1) {
            for (auto &it : s1) {
                //cout << it << '\n';
                if (it > tmp2) {
                    ans.push_back(it);
                }
            }
        } else if (tmp2.size() == 2) {
            for (auto &it : s2) {
                //cout << it << '\n';
                if (it > tmp2) {
                    ans.push_back(it);
                }
            }
        } else if (tmp2.size() == 3) {
            for (auto &it : s3) {
                if (it > tmp2) {
                    ans.push_back(it);
                }
            }
            
        } else if (tmp2.size() == 5) {
            for (auto &it : s5) {
                if (it > tmp2) {
                    ans.push_back(it);
                }
            }
        } else if (tmp2.size() == 4) {
            for (auto &it : s4) {
                if (it > tmp2) {
                    ans.push_back(it);
                }
            }
        }

        if (!ans.empty()) {
            cout << "YES ";
            for (int i = 0; i < ans.size(); i++)
            {
                cout << ans[i] << ' ';
            }
            cout << '\n';
        } else {
            cout << "NO\n";
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie();

    solve();
}
