#include<stdio.h>
using namespace std;
int main()
{
	int T;
	int  a,b,c;
	scanf("%d",&T);
	while(T--)
	{
		b=0;
		scanf("%d",&a);
		if(a>180)
		a=a-180;
		while(a>=5)
		{
			a-=10;
			b++;
		}
		if(b==0)
		printf("18\n");
		else
		printf("%02d\n",b);

	}
}
