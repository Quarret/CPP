#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    if (n == 0) return true;
    
    int m = flowerbed.size();
    flowerbed.insert(flowerbed.begin(), 0);
    flowerbed.push_back(0);

    for (int j = 1; j <= m; j++) {
        
        if ((flowerbed[j - 1] | flowerbed[j] | flowerbed[j + 1]) == 0) {
            n--;
            flowerbed[j] = 1;
        }
        
        if (!n) return true;
    }

    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
