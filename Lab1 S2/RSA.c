#include<stdio.h>
#include<stdlib.h>

long int fast_expo(long int a,long int x,long int n)
{
	if(x==0)
	{
		
	}
	if(x==1)
	{
		return a%n;		
	}	
	long int t = fast_expo(a,x/2,n);
	t = (t * t) % n;
	
	if (x % 2 == 0)
		return t; 
	else
		return ((a % n) * t) % n; 
}
int findm(int n)
{
	int i,temp,k;
	temp=n-1;
	k=0;
	while(1)
	{
		if(temp%2 == 0)
		{
			k++;
			temp=temp/2;
		}
		else
		{
			break;
		}
	}
	return temp;
}
int findk(int n)
{
	int i,temp,k;
	temp=n-1;
	k=0;
	while(1)
	{
		if(temp%2 == 0)
		{
			k++;
			temp=temp/2;
		}
		else
		{
			break;
		}
	}
	return k;
}
long int miler(long int a, long int n)
{

	int m,k,t,i;
	m=findm(n);
	k=findm(n);
	t=fast_expo(a,m,n);
	if(t== 1 || t == -1)
	{
		printf("Prime");
		return 1;
	}
	for(i=0;i<k;i++)
	{
		t=fast_expo(t,2,n);
		if(t==1)
		{
			printf("Composit");
			return 0;
		}
		if(t==-1)
		{
			printf("Prime");
			return 1;
		}		
		printf("Composit");
		return 0;
	}
}

int main()
{
	int a,x,n;
	a=17;
	x=22;
	n=21;
	long int ans = miler(2,7);
	printf("Answer:%d",ans);
	return 0;
}
