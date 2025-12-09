#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    int n = asteroids.size();
    vector<int> ans;
    
    for (int i = 0; i < n; i++) {
        if (asteroids[i] < 0) {
            int flag = 1;
            while (!ans.empty() && ans.back() > 0) {
                if (ans.back() + asteroids[i] < 0) ans.pop_back();
                else if (ans.back() + asteroids[i] == 0) {
                    ans.pop_back();
                    flag = 0;
                    break;
                } else break;
            }

            if ((ans.empty() || ans.back() < 0) && flag) ans.push_back(asteroids[i]);
        } else ans.push_back(asteroids[i]);
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
