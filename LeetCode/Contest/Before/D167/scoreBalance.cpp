#include <bits/stdc++.h>
using ll = long long;
using namespace std;

bool scoreBalance(string s) {
    int sum = 0;
    for (char c : s) {
        sum += c - 'a' + 1;
    }
    
    int pre = 0;
    for (char c : s) {
        pre += c - 'a' + 1;
        if (sum - pre == pre) return true;
    }

    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
