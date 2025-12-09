# bit函数
**1. 统计数位上1的个数**(这个函数是硬件实现的,O(1)时间复杂度)
__builtin_popcount(ll) 
ll 计算long long数据

# bit计算技巧
**1. 计算lowbit**
\[
    num1 \& -num1 = lowbit(第一个1)
\]

**2. 计算第一个0**
\[
    num1 \| -num2 = low0bit
\]


# 恒等式
(a & b) ^ (a & c) = a & (b ^ c)
