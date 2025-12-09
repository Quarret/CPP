#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn=10000+5,maxm=50000+5;
int n,m;
int hd[maxn*2];//记录
int to[maxm*2];//记录每条边的终点
int nxt[maxm*2];//
int vis[maxm*2];//记录第cnt条边的情况
int cnt = 0;//边的个数
void add(int x,int y){
    to[cnt]=y;//第cnt条边，x->y
    vis[cnt]=0;//记录第cnt条边的情况
    nxt[cnt]=hd[x];//第x个点的第cnt条出边
    hd[x]=cnt++;//第x的点，第cnt条边
}
void dfs(int root){
    for(int i=hd[root];i!=-1;i=nxt[i]){//遍历root点的出边
        if(!vis[i])
            vis[i]=1,dfs(to[i]);
    }
    printf("%d\n",root);
}
int main(){
    while(scanf("%d%d",&n,&m)!=EOF){//n个点，m对xy关系
    cnt=0,memset(hd,-1,sizeof(hd));
    for(int i=1,x,y;i<=m;i++)
        scanf("%d%d",&x,&y),add(x,y),add(y,x);//记录2*m条边的情况
    dfs(1);
    }
    return 0;
} 




/*
DFS_Graph(root)://从root点搜起
    for (root,j) in Graph://遍历root的每个j方向的边
        if visit[(root,j)]==0://如果这条边没有走过
            visit[(root,j)]=1//标记为走过
            DFS_Graph(j)//从root出发沿j这条边往下搜
    add root in answer//回溯的时候点的所有边都走过，存入ans中
*/