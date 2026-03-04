#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int minPartitions(string n) {
    int ans = 0;
    for (char c : n) {
        ans = max(ans, c - '0');
    }
    
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}