#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s;
int accum(int x) {
    vector<int> v1;
    vector<char> v2;

    while(!s[x] == ')') {
        if (s[x] >= '0' && s[x] <= '9') {
        v1.push_back(s[x] - '0');
        } else if (s[x] == '+' || s[x] == '-' || s[x] == '*' || s[x] == '/') {
        v2.push_back(s[x]);
        } else {
            return -1e9;
        }
    }
    int ans = 0;
    while(v2.size()) {
        int num1 = v1[0];
        v1.erase(v1.begin());
        char c1 = v2[0];
        v2.erase(v2.begin());
        
        int ans2 = 0;
        if (v2[0] == '/' || v2[0] == '*') {
            int num2 = v1[0];
            v1.erase(v1.begin());
            int num3 = v1[0];
            v1.erase(v1.begin());
            char c2 = v2[0];

            if (c2 == '*') {
                ans2 = num2 * num3;
            } else {
                ans2 = num2 / num3;
            }
        }

        if (c1 == '+') {
            ans = num1 + ans2;
        } else if (c1 == '-') {
            ans = num1 - ans2;
        } else if (c1 == '*') {
            ans = num1 * ans2;
        } else if (c1 == '/') {
            ans = num1 / ans2;
        }

    }

    return ans;
}
void solve() {
   cin >> s;
   int n = s.size();

   vector<int> a1;
   vector<char> a2;

   for (int i = 0; i < n; i++) {
    if (s[i] >= '0' && s[i] <= '9') {
        a1.push_back(s[i] - '0');
    } else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
        a2.push_back(s[i]);
    } else if (s[i] == '(') {
      int num = accum(i + 1);
      if (num == -1e9) {
        //cout << "NO" << '\n';
        return;
      }
      a1.push_back(num);
      while (s[i] != ')') {
        i++;
      }
    }
   }

   int ans = 0;
    while(a2.size()) {
        int num1 = a1[0];
        //cout << num1 << '\n';
        a1.erase(a1.begin());
        char c1 = a2[0];
        //cout << c1 << '\n';
        a2.erase(a2.begin());
        
        int ans2 = 0;
        if (a2[0] == '/' || a2[0] == '*') {
            int num2 = a1[0];
            //cout << num2 <<'\n';
            a1.erase(a1.begin());
            int num3 = a1[0];
            //cout << num3 << '\n';
            a1.erase(a1.begin());
            char c2 = a2[0];
            //cout << c2 << '\n';

            if (c2 == '*') {
                ans2 = num2 * num3;
            } else {
                ans2 = num2 / num3;
            }
        }

        if (c1 == '+') {
            ans = num1 + ans2;
        } else if (c1 == '-') {
            ans = num1 - ans2;
        } else if (c1 == '*') {
            ans = num1 * ans2;
        } else if (c1 == '/') {
            ans = num1 / ans2;
        }

    }

    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie();

    solve();
}
