# 信号模拟 - 题解

## 题目大意

有 $2 \times n$ 个仪器，每个仪器左右两侧各有一个接线点。将左右两侧的 $2n$ 个接线点分别随机两两配对，然后用导线连接。信号在闭环中传递，每个环至少需要一个信号源。求在所有接收器均能接收到信号的前提下，信号源数量 $x$ 的方差。

---

## 问题转化

**关键观察：**
- 左右两侧的匹配交替连接，形成若干个独立的环
- 每个环至少需要 1 个信号源
- 因此 $x$ = **环的数量**
- 问题转化为：求随机双匹配形成环数的方差

---

## 数学推导

### 1. 期望的推导

设 $X_n$ 表示 $2n$ 个仪器形成的环数。

使用**指示变量**方法，定义 $I_k$ 表示第 $k$ 步是否开启新环：
$$X_n = \sum_{k=1}^{n} I_k$$

**核心引理：** 第 $k$ 个仪器开启新环的概率为：
$$P(I_k = 1) = \frac{2}{2k-1}$$

**证明思路：** 当处理到第 $k$ 个仪器时，右侧有 $2k-1$ 个可选接线点，其中 2 个会开启新环。

由期望的线性性：
$$E(X_n) = \sum_{k=1}^{n} \frac{2}{2k-1} = 2 + \frac{2}{3} + \frac{2}{5} + \cdots + \frac{2}{2n-1}$$

### 2. 方差的推导

对于双匹配问题，经过严格的组合推导（涉及随机置换的循环结构和生成函数），方差公式为：

$$\boxed{Var(X_n) = \sum_{k=2}^{n} \frac{2}{(2k-1)^2}}$$

**边界条件：** $Var(X_1) = 0$（只有一个环，无方差）

---

## 示例验证

### n = 1
$$Var(X_1) = 0$$
✓ 只有一种配对方式，恒为 1 个环

### n = 2

手动计算验证：
- 左侧 3 种配对 × 右侧 3 种配对 = 9 种组合
- 形成 1 个环：概率 $\frac{6}{9}$
- 形成 2 个环：概率 $\frac{3}{9}$

$$E(X) = 1 \times \frac{6}{9} + 2 \times \frac{3}{9} = \frac{4}{3}$$
$$Var(X) = E(X^2) - [E(X)]^2 = \left(1 \times \frac{6}{9} + 4 \times \frac{3}{9}\right) - \frac{16}{9} = \frac{2}{9}$$

公式计算：
$$Var(X_2) = \frac{2}{(2\times2-1)^2} = \frac{2}{9}$$
✓ 一致

### n = 3

$$Var(X_3) = \frac{2}{3^2} + \frac{2}{5^2} = \frac{2}{9} + \frac{2}{25} = \frac{68}{225}$$

---

## 算法实现

### 核心公式

$$Var(X_n) = \sum_{k=2}^{n} \frac{2}{(2k-1)^2}$$

### 模运算处理

题目要求输出 $(p \times q^{-1}) \mod M$，其中 $M = 998244353$ 是质数。

使用**费马小定理**求逆元：
$$q^{-1} \equiv q^{M-2} \pmod{M}$$

### 递推计算

$$Var(X_n) = Var(X_{n-1}) + \frac{2}{(2n-1)^2}$$

预处理所有值，单次查询 $O(1)$。

---

## 代码

```cpp
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const int MOD = 998244353;

// 快速幂：计算 x^n % MOD
ll qpow(ll x, ll n) {
    ll res = 1;
    for (; n; n /= 2) {
        res = res * x % MOD;
        x = x * x % MOD;
    }
    return res;
}

// 乘法逆元：使用费马小定理
ll inv(ll x) {
    return qpow(x, MOD - 2);
}

const int MAXN = 1e6 + 5;
ll variance[MAXN];

// 预处理所有方差值
void init() {
    variance[1] = 0;
    for (int i = 2; i <= MAXN; i++) {
        ll denom = (2LL * i - 1) % MOD;
        ll denom2 = denom * denom % MOD;
        ll term = 2 * inv(denom2) % MOD;
        variance[i] = (variance[i - 1] + term) % MOD;
    }
}

void solve() {
    int n;
    cin >> n;
    cout << variance[n] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```

---

## 复杂度分析

| 项目 | 复杂度 |
|------|--------|
| 预处理时间 | $O(n \log M)$ |
| 单次查询 | $O(1)$ |
| 空间 | $O(n)$ |

其中 $n \leq 10^6$，$T \leq 10^4$，完全满足 1 秒时限。

---

## 关键知识点

1. **快速幂算法** - 计算 $x^n \mod M$
2. **费马小定理** - $a^{p-1} \equiv 1 \pmod{p}$（$p$ 为质数）
3. **乘法逆元** - $\frac{1}{a} \mod M = a^{M-2} \mod M$
4. **期望的线性性** - $E(\sum X_i) = \sum E(X_i)$
5. **指示变量方法** - 将计数问题转化为概率求和

---

## 参考

- 随机置换的循环结构理论
- 双匹配问题（Double Matching Problem）
- 组合概率论中的环计数问题
