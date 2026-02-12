#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int mirrorDistance(int n) {
    string s = to_string(n);
    ranges::reverse(s);
    return abs(n - stoi(s));        
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
