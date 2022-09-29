#include <iostream>
#include <stdio.h>
#define N 999

using namespace std;

int t(int p[N],int n)
{	
	int c=0;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(p[i]>p[j])
			c++;
			else if(p[i]==p[j])
			return 0;
		}
	}
	
	if(c%2==0)
	return 1;
	else
	return -1;
}

double product(double x[30][30],int p[N],int n)
{
	double pdt=1;
	for(int i=1;i<=n;i++)
	{
		pdt*=x[i][p[i]];
	}
	return pdt;
}


double sum(double x[30][30],int n)
{
	double sum1=0;
	int p[N];
	for(int i=1;i<=N;i++)
	{
		p[i]=1;
	}
	
	for(int i=1;i<=n^n;i++)
	{
		p[1]++;
		for(int j=1;j<=n^n;j++)
		{
			if(p[j]==n+1)
			{
				p[j]=1;
				p[j+1]++;
			}
		}
		
		sum1+=t(p,n)*product(x,p,n);
	}
	
	
	return sum1;
}

int main()
{
	int n;
	double x[30][30];
	cout<<"input n=";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<"input x["<<i<<"]["<<j<<"]=";
			cin>>x[i][j];
		}
	}
	
	
	cout<<"D="<<sum(x,n);
	
	return 0;
}

