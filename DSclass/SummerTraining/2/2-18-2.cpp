#include <bits/stdc++.h>
using ll = long long;
using namespace std;
char a[2005][2005];
int maxx;
int mark[2005];
int n;

void dfs(int row, int col, int size) {
    if (a[row][col] == '0') 
        return;
    int flag = 0;
    for (int i = row; i < row + size; i++) {
        for (int j = col; j < col + size; j++) {
            if ((i - row + j - col) % 2 == 1 && a[i][j] == '1') {
                flag = 1;
                break;
            }
            if ((i - row + j - col) % 2 == 0 && a[i][j] == '0') {
                flag = 1;
                break;
            }
        }

        if (flag) {
            break;
        }
    }

    if (!flag) {
        if (size >= maxx) {
            maxx = size;
            mark[size]++;
        }

        if (col + size <= n && row + size <= n) {
            dfs(row, col, size + 1);
        }
    } 


}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1 ; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dfs(i, j, 1);
        }
    }

    cout << maxx << ' ' << mark[maxx] << '\n';
}
