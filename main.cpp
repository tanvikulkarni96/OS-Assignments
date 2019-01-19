//Tanvi Kulkarni-
//Best Fit Algorithm for allocation partitioned memory blocks

#include <iostream>
#include<stdlib.h>
using namespace std;

int *blocks,*process,*alloc;

int find_minimum(int msize,int process)   // Finding the min block for a process size
{
	int min=-1;
	int i;
	
	for(i=0;i<msize;i++)
	{
		if(blocks[i]>=process)
		{
			if(min==-1 || blocks[i]<blocks[min])
			{
				min=i;
			}
		}
	}
	return min;
}

int main() 
{
	int msize,psize;
	int i,min;
	
	cout<<"Enter the no. of memory blocks available for allocation :"<<endl;
	cin>>msize;
	blocks = new int[msize];
	
	cout<<"Enter the no.of process to be allocated memory :"<<endl;
	cin>>psize;
	process = new int[psize];
	alloc = new int[psize];
	
	for(i=0;i<psize;i++)
	{
		alloc[i]=-1; //Initializing allocation array to -1;
	}
	
	cout<<"Enter the block sizes :"<<endl;
	for(i=0;i<msize;i++)
	{
		cout<<"Enter the size of block"<<i+1<<" :"<<endl;
		cin>>blocks[i];		//Accepting memory block sizes
	}
	
	cout<<"Enter the process sizes :"<<endl;
	for(i=0;i<psize;i++)
	{
		cout<<"Enter the size of process"<<i+1<<" :"<<endl;
		cin>>process[i];		//Accepting process sizes to be allocated
	}
		
	for(i=0;i<psize;i++)
	{
		min=find_minimum(msize,process[i]);	//Finding min memory block
		if(min>=0)
		{
			alloc[i]=min;
			blocks[min]=blocks[min]-process[i];	//Updating memory blocks after allocating process
		}		
	}
	
	cout<<"Allocation array is :"<<endl;
	for(i=0;i<psize;i++)
	{
		cout<<alloc[i]<<" ";	//Displaying final allocation array
	}
	
	delete []alloc;
	delete []blocks;
	delete []process;
	
	
	return 0;
	
}
