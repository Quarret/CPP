#include <bits/stdc++.h>
using ll = long long;
using namespace std;

map<string, int> mp;
map<int, string> mp1;
void solve() {
    int n;
    string s;
    cin >> n;
    getline(cin, s);
    while (n--) {
        getline(cin, s);
        int pos1 = s.find('.'), pos2 = s.find(' ');
        string s1 = s.substr(0, pos1), 
        s2 = s.substr(pos1 + 1, pos2 - pos1 - 1), 
        s3 = s.substr(pos2 + 1, s.size() - pos2);

        int y = stoi(s3), m = mp[s2], d = stoi(s1);
        ll sum = 0;
        if (s2 != "uayet") {
            sum = y * 365 + (m - 1) * 20 + d + 1; 
        } else {
            sum = y * 365 + 360 + d + 1;
        }
        
        int y1 = sum / 260, num1 = sum % 260;
        int num2 = num1 % 20, num3 = num1 % 13;
        if (num3 == 0) num3 = 13;

        cout << num3 << ' ' << mp1[num2] << ' ' << y1 << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    mp["pop"] = 1;
    mp["no"] = 2;
    mp["zip"] = 3;
    mp["zotx"] = 4;
    mp["tzec"] = 5;
    mp["xul"] = 6;
    mp["yoxkin"] = 7;
    mp["mol"] = 8;
    mp["chen"] = 9;
    mp["yax"] = 10;
    mp["zac"] = 11;
    mp["ceh"] = 12;
    mp["mac"] = 13;
    mp["kankin"] = 14;
    mp["muan"] = 15;
    mp["pax "] = 16;
    mp["koyab"] = 17;
    mp["cumhu"] = 18;

    mp1[1] = "imix";
    mp1[2] = "ik";
    mp1[3] = "akbal";
    mp1[4] = "kan";
    mp1[5] = "chicchan";
    mp1[6] = "cimi";
    mp1[7] = "manik";
    mp1[8] = "lamat";
    mp1[9] = "muluk";
    mp1[10] = "ok";
    mp1[11] = "chuen";
    mp1[12] = "eb";
    mp1[13] = "ben";
    mp1[14] = "ix";
    mp1[15] = "mem";
    mp1[16] = "cib";
    mp1[17] = "caban";
    mp1[18] = "eznab";
    mp1[19] = "canac";
    mp1[0] = "ahau";

    solve();
}
