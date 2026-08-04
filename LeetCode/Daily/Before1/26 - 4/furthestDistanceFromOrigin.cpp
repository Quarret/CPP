#include <bits/stdc++.h>
using ll = long long;
using namespace std;


int furthestDistanceFromOrigin(string moves) {
    int n = moves.size();
    int cur = 0, cnt = 0;
    
    for (int i = 0; i < n; i++) {
        if (moves[i] == '_') cnt++;
        else cur += moves[i] == 'L' ? 1 : -1;
    }

    return abs(cur) + cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}