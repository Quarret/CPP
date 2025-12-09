#include <bits/stdc++.h>
#define int long long
#define DB double

using namespace std;

const int N = 1e6 + 10, MOD = 998244353;
int n, x, sum;

int kuaisu(int x, int y)
{
	// 快速幂求逆元
	int ret = 1;
	while(y)
	{
		if(y & 1)
			ret = ret * x % MOD;
		x = x * x % MOD;
		y >>= 1;
	}
	return ret;
}

signed main()
{
	scanf("%lld", &n);
	
	for(int i = 1; i <= n; i ++ )
	{
		scanf("%lld", &x);
		sum = (x + sum) % MOD;
		// 输入并求和
	}
	
	printf("%lld\n", sum * kuaisu(n, MOD - 2) % MOD);
	// n的p-2次方（p为质数）在模p的意义下等同于n的-1次方，也就是n的逆元
	
	return 0;
}