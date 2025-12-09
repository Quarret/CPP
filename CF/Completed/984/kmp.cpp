#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 构建部分匹配表（next 数组）
vector<int> computeNext(const string &pattern)
{
    int m = pattern.size();
    vector<int> next(m, 0);
    int j = 0; // 记录前缀末尾的长度

    for (int i = 1; i < m; ++i)
    {
        // 回溯：当当前字符不匹配时，利用 next[j-1] 找到新的前缀长度
        while (j > 0 && pattern[i] != pattern[j])
        {
            j = next[j - 1];
        }
        // 如果字符匹配，前缀长度加 1
        if (pattern[i] == pattern[j])
        {
            ++j;
        }
        next[i] = j;
    }

    return next;
}

// KMP 主算法
vector<int> kmpSearch(const string &text, const string &pattern)
{
    vector<int> result;                      // 存储匹配成功的位置
    vector<int> next = computeNext(pattern); // 生成 next 数组

    int n = text.size();
    int m = pattern.size();
    int j = 0; // 模式串当前匹配到的位置

    for (int i = 0; i < n; ++i)
    {
        // 回溯：当字符不匹配时，调整模式串位置
        while (j > 0 && text[i] != pattern[j])
        {
            j = next[j - 1];
        }
        // 如果字符匹配
        if (text[i] == pattern[j])
        {
            ++j;
        }
        // 如果完全匹配
        if (j == m)
        {
            result.push_back(i - m + 1); // 匹配的起始位置
            j = next[j - 1];             // 继续寻找下一个匹配
        }
    }

    return result;
}

// 主函数测试
int main()
{
    string text = "ababcabcabababd";
    string pattern = "ababd";

    vector<int> result = kmpSearch(text, pattern);

    cout << "Pattern found at indices: ";
    for (int index : result)
    {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}
