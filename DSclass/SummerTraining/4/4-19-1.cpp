#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    vector<int> a;
    map<int, int> b, expand; // map<次数，对应系数>
    int temp;
    while (cin >> n && n)
    {
        a.clear();
        b.clear();
        expand.clear();

        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            a.push_back(temp);
        }

        b[n] = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            cin >> temp;
            b[i] = temp; // 最后的对照结果
        }

        expand[0] = a[0];
        expand[1] = 1; // 这两步初始化第一个原始算式(x+key)

        // 接下来进行多项式的展开
        for (int i = 2; i <= n; i++)
        { // 控制当前最高次数

            for (int j = i; j >= 0; j--)
            { // 从最高次数慢慢向下计算

                if (j == i)
                { // 如果是最高次数项，则它的系数为n
                    expand[j] = 1;
                }
                else if (j == 0)
                { // 常数项
                    expand[j] *= a[i - 1]; // 当前常数项等于当前常数项*前一个式子的常数项
                }
                else
                {
                    //既不是最高项又不是0次项，这一步比较难
                    expand[j] = expand[j] * a[i - 1] + expand[j - 1];
                    // 解释：注意题目所给均为（x+key)的形式，所以j次项的系数只与当前项系数与前一个（x+key）式子中的key的乘积+（j-1）的系数有关
                }
            }
        }
        if (expand == b)
            cout << "Y" << endl;
        else
            cout << "N" << endl;
    }
    return 0;
}