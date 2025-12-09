#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int fillCups(vector<int>& amount) {
    int n = 0, m = 0;
    for (int x : amount) {
        n += x;
        m = max(m, x);
    }
    
    return max((n + 1) / 2, m);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
