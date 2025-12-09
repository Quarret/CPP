#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <cmath>
#include <algorithm>
#include <set>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <map>
using namespace std;

// 前缀和！  v[i]表示 前i个数字的和；方程：  v[i]= v[i-1] + a[i]

int main()
{
    string s;
    cin >> s;

    vector<int> a, b;

    // 由于前缀和是个递推的过程  因此需要确定初值
    if (s[0] == 'a')
    {
        a.push_back(1);
        b.push_back(0);
    }
    else
    {
        a.push_back(0);
        b.push_back(1);
    }

    // 递推得到前i个位置中a的数量和b的数量 ,而且某个区间的数量可以相减得到
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == 'a')
        {
            a.push_back(1 + a[i - 1]);
            b.push_back(0 + b[i - 1]);
        }
        else
        {
            a.push_back(0 + a[i - 1]);
            b.push_back(1 + b[i - 1]);
        }
    } // 复杂度O(n)

    int maxi = -1;
    // 任意两个结点i和j可以分出 【a】【b】【a】三个区间
    // 只要二重循环一次，可以得到所有情况，此时读取各个区间数目复杂度O（1）
    int a1, bm, a2;
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i; j < s.size(); j++)
        {

            a1 = a[i];
            bm = b[j] - b[i - 1]; // b[i-1]却不会越界  不懂呢~
            a2 = a[s.size() - 1] - a[j];

            if (a1 + bm + a2 > maxi)
                maxi = a1 + bm + a2;
        }
    }
    cout << maxi;
}