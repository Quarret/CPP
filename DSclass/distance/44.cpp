#include <iostream>
#include<algorithm>
#include<stack>
#include<math.h>
#include <vector>

using namespace std;

int n;
const double MAXNUM=1e10;


struct c_point {
    double x;
    double y;
};

c_point p0;//最低点
vector<c_point> points(n);//散点集
stack<c_point>convex_hull;//凸包

//显示栈
void check_stack(stack<c_point>points)
{
	//cout<<"==========="<<endl;
	while(!points.empty()){
		cout<<"  ["<<points.top().x<<","<<points.top().y<<"]"<<endl;
		points.pop();
	}
	//cout<<"==========="<<endl;
}

//寻找p0
void find_p0()
{
	p0=points[0];
	int ii=0;
	for(int i=1;i<n;i++){
		if(points[i].y<p0.y){
			p0=points[i];
			ii=i;
		}else if(points[i].y==p0.y){
			if(points[i].x<p0.x){
				p0=points[i];
				ii=i;
			}
		}
	}
}

//极角排序
bool cmp(c_point &p1,c_point &p2)
{
	//p0排首位
	if(p1.x==p0.x&&p1.y==p0.y)return true;
	if(p2.x==p0.x&&p2.y==p0.y)return false;

	//计算极角（等于0则赋予一个极大值）
	double angle1=p1.x==p0.x?MAXNUM:(p1.y-p0.y)/(p1.x-p0.x);
	double angle2=p2.x==p0.x?MAXNUM:(p2.y-p0.y)/(p2.x-p0.x);
	//小于0则赋予一个更大的值
	if(angle1<0)angle1+=2*MAXNUM;
	if(angle2<0)angle2+=2*MAXNUM;
	
	//极角排序
	if(angle1<angle2)return true;
	else if(angle1==angle2){
		if(p1.y>p2.y)return true;
		else return false;
	}
	else return false;
}

//叉积
double cross(c_point p1, c_point p2, c_point p3)
{
	return (p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y);
}

//搜索凸包
void find_convex_hull()
{
	//p0和p1是凸包中的点
	convex_hull.push(points[0]);
	convex_hull.push(points[1]);

	int i=2;
	//p1,p2为栈顶两个节点
	c_point p1=points[0];
	c_point p2=points[1];
	while(i<n){
		//如果points[i]和points[i-1]在同一个角度，则不再对points[i]进行计算
		if((points[i-1].y-p0.y)*(points[i].x-p0.x)==(points[i-1].x-p0.x)*(points[i].y-p0.y)){
			i++;
			continue;
		}

		//如果叉积大于0，将当前点压入栈
		if (cross(p1, p2, points[i])>=0){
			//假设现在栈中为a,b,c,d,cross(c,d,e)大于等于0
			convex_hull.push(points[i]);//a,b,c,d,e,p1=c,p2=d
			p1=p2;//p1=d
			p2=convex_hull.top();//p2=e
			i++;
		}

		//如果叉积小于0，对栈中节点进行处理
		else{
			while(1){
				//假设现在栈中为a,b,c,d,cross(c,d,e)小于0
				convex_hull.pop();//a,b,c
				convex_hull.pop();//a,b
				p2=p1;//p2=c;
				p1=convex_hull.top();//p1=b
				convex_hull.push(p2);//a,b,c
				//cross(b,c,e)
				if(cross(p1,p2,points[i])>=0){
					convex_hull.push(points[i]);//a,b,c,e
					p1=p2;//p1=c
					p2=convex_hull.top();//p2=e
					i++;
					break;
				}
			}
		}
	}
}

int main()
{   
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

	find_p0();//寻找p0
	sort(points.begin(),points.begin()+n,cmp);//按极角排序
	find_convex_hull();//搜索凸包
	check_stack(convex_hull);//显示结果

	system("pause");
}
