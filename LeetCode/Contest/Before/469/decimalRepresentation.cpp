#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> decimalRepresentation(int n) {
    int base = 1;
    vector<int> ans;
    while (n) {
        int val = (n % 10) * base;
        if (val) ans.push_back(val);
        base *= 10;
        n /= 10;
    }
    reverse(ans.begin(), ans.end());
    
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
