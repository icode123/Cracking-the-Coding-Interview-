#include <iostream>
#include <map>
using namespace std;

struct point 
{
  int x;
	int y;
};

class line
{
public:
	double epsilon,slope,intercept;
	bool bslope;
	line() { }
	line(const point &a,const point &b)
	{
		epsilon = 0.0001;
		if (abs(a.x-b.x)>epsilon)
		{
			slope=(a.y-b.y)/(a.x-b.x);
			intercept=a.y-slope*a.x;
			bslope=true;
		}
		else
		{
			bslope=false;
			intercept=a.x;
		}
	}
	int hashcode()
	{
		int sl=(int)(slope*1000);
		int inter=(int)(intercept*1000);
		return sl*1000+inter;
	}
};

line find_best_line(point *p, int point_num)
{
	line bestline;
	bool first = true;
	map<int,int> hash;
	for(int i=0;i<point_num;i++)
		for(int j=i+1;j<point_num;j++)
		{
			line l(p[i],p[j]);
			if (hash.find(l.hashcode())==hash.end())
			{
				hash[l.hashcode()]=0;
			}
			hash[l.hashcode()]+=1;
			if(first)
			{
				bestline=l;
				first=false;
			}
			else
			{
				if(hash[l.hashcode()]>hash[bestline.hashcode()])
				{
					bestline=l;
				}
			}
		}
	return bestline;
}
