#include <iostream>
#include <cmath>
#define N 900//比n^n大即可
#define max_n 30//最高可算多少阶行列式

using namespace std;

//计算每项前系数
int t(int p[N],int n)
{	
	int c=0;//定义逆序数计数器
	
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(p[i]>p[j])  
			c++;//出现逆序则自增1
			else if(p[i]==p[j])
			return 0;//出现同列情况将系数变为0
		}
	}
	
	if(c%2==0)
	return 1;//偶逆序数返回1
	else
	return -1;//奇逆序数返回-1
}

//计算系数外每项的乘积
double product(double x[max_n][max_n],int p[N],int n)
{
	double pdt=1;//乘积初始化为1
	for(int i=0;i<n;i++)
	{
		pdt*=x[i][p[i]];
	}
	return pdt;//返回本次序列数所对应的乘积
}


double sum(double x[max_n][max_n],int n)
{
	double sum1=0;//初始化结果为0
	int p[N];//定义序列数，从p[1]开始每一位的值对应取x[][]中每行的第几列
	for(int i=0;i<N;i++)
	{
		p[i]=0;//初始化
	}
	
	
	for(int i=0;i<pow(n,n);i++)
	{
		sum1+=t(p,n)*product(x,p,n);
		
		//开始生成序列数
		p[0]++;
		for(int j=0;j<n;j++)
		{
			if(p[j]==n)
			{
				p[j]=0;
				p[j+1]++;
			}
		}
		
		
	}
	
	
	return sum1;
}

int main()
{
	int n;//阶数
	double x[max_n][max_n];
	cout<<"input n=";
	cin>>n;//定义行列式阶数

	//输入行列式的每一项的值
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<"input x["<<i<<"]["<<j<<"]=";
			cin>>x[i][j];
		}
	}
	
	
	cout<<"D="<<sum(x,n);
	
	return 0;
}
