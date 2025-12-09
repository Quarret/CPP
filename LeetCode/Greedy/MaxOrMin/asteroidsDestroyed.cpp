#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
    sort(asteroids.begin(), asteroids.end());
    
    long long sum = mass;
    for (int x : asteroids) {
        if (sum < x) return false;
        sum += 1LL * x;
    }

    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
