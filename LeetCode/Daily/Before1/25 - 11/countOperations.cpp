#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int countOperations(int num1, int num2) {
    int ans = 0;
    while (num1 != 0 && num2 != 0) {
        int maxx = max(num1, num2);
        int minn = min(num1, num2);
        ans += maxx / minn;
        maxx %= minn;
        num1 = maxx;
        num2 = minn;
    }
    
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
