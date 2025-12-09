#include <bits/stdc++.h>
using ll = long long;
using namespace std;

bool makeStringsEqual(string s, string target) {
    int cnt0 = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0;

    if (s == target) return true;
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] & 1) cnt1++;
        else cnt0++;

        if (target[i] & 1) cnt2++;
        else cnt3++;
    }

    return (!cnt1 | !cnt2 ? false : true);
}

//换句话说, s 与 target 不能都只是0组成的
bool makeStringsEqual(string s, string target) {
    return s.contains('1') == target.contains('1');
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
