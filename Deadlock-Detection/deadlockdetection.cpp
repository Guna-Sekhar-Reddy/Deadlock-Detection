//dead lock detection algorithm

#include<iostream>

using namespace std;

int main()
{
	int m,n;
	cout<<"Enter number of processes"<<endl;
	cin>>n;
	cout<<"Enter number of resources"<<endl;
	cin>>m;
	
	int request[n][m],allocate[n][m],available[m],p,req[m],sum=0,total[m];
	int flag[n]={0};		//flag 1-> that process can execute ;  flag 0-> that process not execcute
	
	cout<<"enter total instances of resources"<<endl;
	for(int i=0;i<m;i++)
	{
		cin>>total[i];
	}
	cout<<"Enter the request resources"<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>request[i][j];
		}
	}
	
	
	cout<<"Enter the allocation of resources"<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>allocate[i][j];
		}
	}
	
	cout<<"Enter the process need of additional request"<<endl;
	cin>>p;
	
	cout<<"Enter the requested resources"<<endl;
	for(int i=0;i<m;i++)
	{
		cin>>req[i];
		request[p][i]=request[p][i]+req[i];
	}
	

	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			sum=sum+allocate[j][i];
		}
	//	cout<<"sum is "<<sum<<endl;
		available[i]=total[i]-sum;
		sum=0;
	//	cout<<"available is "<<available[i]<<endl;
	}
	
	cout<<"program should run in the sequence of "<<endl;
	int index=0,index1=1;
	while(index1)
	{
		index1=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(request[i][j]<=available[j] && flag[i]==0)
				{
					index++;
				}
			}
			if(index==m)							//all resources are more than or equal needed
			{
				cout<<"process "<<i<<endl;
				flag[i]=1;
				for(int j=0;j<m;j++)
				{
					available[j]=available[j]+allocate[i][j];
				}
				index1=1;
			}
			index=0;
		}
	}
	
	for(int i=0;i<n;i++)
	{
		if(flag[i]==0)
		{
			cout<<"process "<<i<<" is in deadlock"<<endl;
		}
	}
	
}
