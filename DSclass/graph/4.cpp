#include "bits/stdc++.h"
using namespace std;
const int maxn = 123456;
vector<int> s[maxn];
int c[maxn];
int cnt[maxn], sz[maxn];
set<int> ans;
void dfs(int r){
	sz[r] = 1;
	cnt[r] = c[r];
	bool bad = c[r];
	for(int v : s[r]){
		dfs(v);
		sz[r] += sz[v];
		cnt[r] += cnt[v];
		bad &= c[v];
	}
	if(bad) ans.insert(r);
}
int main(){
	int n;
	scanf("%d", &n);
	int root = -1;
	for(int i = 0; i < n; i++){
		int pi;
		scanf("%d %d", &pi, c + i + 1);
		if(pi != -1) s[pi].push_back(i + 1);
		else root = i + 1;
	}
	dfs(root);
	if(ans.empty()) printf("-1");
	for(int v : ans) printf("%d ", v);
	printf("\n");
	return 0;
}