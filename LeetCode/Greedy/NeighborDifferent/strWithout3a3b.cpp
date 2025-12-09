#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

string strWithout3a3b(int a, int b) {
    int minn = min(a, b);
    int empty = minn + 1;
    char ch1 = 'a', ch2 = 'b';
    if (a < b) {
        swap(a, b);
        swap(ch1, ch2);
    }
    
    string ans;
    while (empty) {
        int num = (a + empty - 1) / empty;
        ans += string(num, ch1);
        if (b) ans += ch2;
        a -= num;
        b--;
        empty--;
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
