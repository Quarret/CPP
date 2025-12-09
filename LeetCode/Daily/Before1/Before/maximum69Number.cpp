#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int maximum69Number (int num) {
    string s = to_string(num);
    int pos = s.find('6');

    if (pos == -1) return num;
    s[pos] = '9';
    return stoi(s);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
