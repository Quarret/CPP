/*
Problem: 2230		User: lantianheyeqi
Memory: 3776K		Time: 860MS
Language: C++		Result: Accepted
*/
#include"iostream"
#include"cstdio"
#include"cstring"
#include"cstdlib"
#define N 100005
 
using namespace std;
//实现的数据结构是用链式前向星模拟邻接表
int u[N];
int v[N];
int next1[N];
int first[N];
int n,m;
bool book[N];
 
void dfs(int root)
{
	int k=first[root];
	while(k!=-1)
	{
		if(book[k]!=1)
		{
			book[k]=1;
			dfs(v[k]);
		}
		k=next1[k];
	}
	printf("%d\n",root);
}
 
int main()
{
	memset(book,0,sizeof(book));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) scanf("%d%d",&u[i],&v[i]);
	memset(first,-1,sizeof(first));
	for(int i=1;i<=2*m;i++)
	{
		next1[i]=first[u[i]];
		first[u[i]]=i;
	}
	dfs(1);
	return 0;
}