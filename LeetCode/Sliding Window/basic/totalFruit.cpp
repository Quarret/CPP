#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> fruits = {1,0,1,4,1,4,1,2,3};
int totalFruit(vector<int>& fruits) {
        int n = fruits.size(), l = 0, ans = 0;
        int box1 = -1, box2 = fruits[0];

        if (n == 1) return 1;
        for (int r = 1; r < n; r++) {
            if (box1 == -1 && fruits[r] != box2) {
                box1 = box2;
                box2 = fruits[r];
            }

            if (fruits[r] != box1 && fruits[r] != box2) {
                box1 = fruits[r - 1];
                box2 = fruits[r];

                int r2 = r - 1;
                while (fruits[r2] == fruits[r - 1]) {
                    r2--;
                }
                l = r2 + 1;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    
    cout << totalFruit(fruits);
    return 0;
}
