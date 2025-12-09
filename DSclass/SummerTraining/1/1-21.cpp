#include <bits/stdc++.h>
#define ll long long
using namespace std;

map<char, int> mp;
char num[16] {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

void solve() {
    int B;
    string N;
    cin >> B >> N;

    int mod = B - 1;
    for (int i = 0; i < B; i++) {
        ll num1 = 0, base = B;
        string tmp = N;
        num1 += mp[num[i]] % mod;

        while(tmp.size()) {
            char x = tmp.back();
            num1 += ((mp[x] % mod) * (base % mod)) % mod;
            tmp.pop_back();
            base = (base * B) % mod;
        }

        if (num1 % (B - 1) == 0) {
            cout << num[i] << '\n';
            return;
        }
    }

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    
    mp['0'] = 0;
    mp['1'] = 1;
    mp['2'] = 2;
    mp['3'] = 3;
    mp['4'] = 4;
    mp['5'] = 5;
    mp['6'] = 6;
    mp['7'] = 7;
    mp['8'] = 8;
    mp['9'] = 9;
    mp['a'] = 10;
    mp['b'] = 11;
    mp['c'] = 12;
    mp['d'] = 13;
    mp['e'] = 14;
    mp['f'] = 15;


    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
