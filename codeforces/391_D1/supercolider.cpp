//https://codeforces.com/problemset/problem/391/D1
#include<iostream>
#include<algorithm>
using namespace std;
class line
{
	public:
		int x1,y1,x2,y2;

};
int intersect(line hor,line ver)
{
	int length=0;
	if((hor.y1>=ver.y1)&&(hor.y1<=ver.y2)&&(ver.x1>=hor.x1)&&(ver.x1<hor.x2))
	{
		int l1,l2,l3,l4;
		l1=ver.y2-hor.y1;
		l2=hor.y1-ver.y1;
		l3=hor.x2-ver.x1;
		l4=ver.x1-hor.x1;
		length=min(min(l1,l2),min(l3,l4));
	
	}
	return length;

}

int main()
{
	int n,m;
	cin>>n;cin>>m;
	int x1,y1,x2,y2,l;
	line vertical[n],horizontal[m];
	for(int i=0;i<n;i++)
	{
		cin>>x1>>y1>>l;
		x2=x1;
		y2=y1+l;
		vertical[i].x1=x1;
		vertical[i].x2=x2;
		vertical[i].y1=y1;
		vertical[i].y2=y2;
	}
	for(int i=0;i<m;i++)
        {
                cin>>x1>>y1>>l;
                x2=x1+l;
                y2=y1;
               	horizontal[i].x1=x1;
                horizontal[i].x2=x2;
                horizontal[i].y1=y1;
                horizontal[i].y2=y2;
        }
	int max_length=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int length=intersect(horizontal[j],vertical[i]);
			max_length=max(max_length,length);
		}
	}
	cout<<max_length<<endl;

return 0;
}
