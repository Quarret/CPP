#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

// 正难则反
int countCollisions(string directions) {
    int n = directions.size();
    int i = 0, j = n - 1;
    while (i <= j && directions[i] == 'L') i++;
    while (i <= j && directions[j] == 'R') j--;
    
    int ans = 0;
    for (int k = i; k <= j; k++) {
        if (directions[k] != 'S') {
            ans++;
        }
    }
    
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
