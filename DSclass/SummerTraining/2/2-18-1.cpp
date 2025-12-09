#include <bits/stdc++.h>
using namespace std;
char a[2005][2005];
int mark[2005];
int max_size = 1;
int N;
void expand(int row, int col, int size)
{
    if (a[row][col] != '1')
        return;
    int flag = 0;
    for (int i = row; i < row + size; i++)
    {
        for (int j = col; j < col + size; j++)
        {
            if ((i - row + j - col) % 2 == 0 && a[i][j] == '0')
            {
                flag = 1;
                break;
            }
            else if ((i - row + j - col) % 2 == 1 && a[i][j] == '1')
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
            break;
    }
    if (!flag)
    {
        if (size >= max_size)
        {
            max_size = size;
            mark[max_size]++;
        }
        if (row + size <= N && col + size <= N)
            expand(row, col, size + 1);
    }
}
int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            expand(i, j, 1);
        }
    }
    cout << max_size << ' ' << mark[max_size] << endl;
    return 0;
}