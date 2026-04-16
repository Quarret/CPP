#include <bits/stdc++.h>
using ll = long long;
using namespace std;


vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
    int i = x, j = x + k - 1;
    while (i < j) {
        for (int t = y; t < y + k; t++) {
            swap(grid[i][t], grid[j][t]);
        }
        i++;
        j--;
    }
    
    return grid;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}