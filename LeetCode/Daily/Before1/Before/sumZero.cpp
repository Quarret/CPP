#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> sumZero(int n) {
    int m = n / 2;
    vector<int> ans;
    
    for (int i = -m; i <= m; i++) {
        ans.push_back(i);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
