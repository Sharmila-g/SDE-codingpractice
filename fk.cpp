  
#include<bits/stdc++.h>
using namespace std;
struct Item
{
	int item;
	int value;
};
bool com(struct Item a,struct Item b)
{
	double r1=(double)a.item/a.value;
	double r2=(double)b.item/b.value;
	return r1>r2;
}
int knapsack(int weight,struct Item it[],int n)
{
	int i=0;
	sort(it,it+n,com);
	int current=0;
	double final;
	for(i=0;i<n;i++)	
	{
		if(current+it[i].value<=weight)
		{
			current+=it[i].value;
			final+=it[i].item;
		}
		else
		{
			int remain=weight-current;
			final+=it[i].item*((double)remain/it[i].value);
			break;
		}
		return final;
	}
}

int main()
{
	int n=0,i,weight;
	cin>>n;
	cin>>weight;
	Item it[n];
	for(i=0;i<n;i++)
	{
		cin>>it[i].item>>it[i].value;
	}
	cout<<knapsack( weight,it,n);
}