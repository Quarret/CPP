#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
    int n = order.size();
    vector<int> idx(n);
    
    for (int i = 0; i < n; i++) {
        idx[order[i]] = i;
    }

    sort(friends.begin(), friends.end(), [&](int a, int b) {
        return idx[a] < idx[b];
    });

    return friends;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
