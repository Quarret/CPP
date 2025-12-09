#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

string maxValue(string n, int x) {
    int len = n.size();
    char c = x + '0';

    for (int i = n[0] == '-' ? 1 : 0; i < len; i++) {
        if (n[0] == '-') {
            if (n[i] > c) {
                n.insert(i, 1, c);
                return n;
            }
        } else if (n[i] < c) {
            n.insert(i, 1, c);
            return n;
        }  
    }
    
    return n + c;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
