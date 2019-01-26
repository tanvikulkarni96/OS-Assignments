//Tanvi Kulkarni
//OS Memory Allocation Basic Algorithm

#include<iostream>
using namespace std;

int allocate_Process(int process,int i,int occupied[][2],int free[],int &occ)
{
	if(free[1]-free[0]>process) //check if memory is avaliable to fit entire process
	{
		if(i==0)
		{
			occupied[i][0]=0;
			occupied[i][1]=process-1;		
		}
		else
		{
			occupied[i][0]=occupied[i-1][1]+1;
			occupied[i][1]=occupied[i][0]+process;		//updating the occupied memory array
		}
		free[0]=occupied[i][1];	//updating free memory array
		occ++;
		return 1;
	}
	else
	{
		return 0;
	}
	
}

int main()
{
	int *process,occupied[10][2],free[2],na[10];
	int pnum,occ=0,res,nac=0,mnum;
	
	cout<<"How many processes?";
	cin>>pnum;
	process=new int[pnum];
	
	cout<<"\nHow much memory is available?";
	cin>>mnum;
	
	free[1]=mnum;
	cout<<"\nEnter process memory requirements"<<endl;
	for(int i=0;i<pnum;i++)
	{
		cout<<"\nEnter requirement for process "<<i+1;
		cin>>process[i];
		
		res=allocate_Process(process[i],i,occupied,free,occ);	//allocating memory for each accepted process
		if(res==0)
		{
			na[nac++]=i;	//updating the array with the process that could not be allocated memory.
		}
	}
	
	//Displaying the final memory status after allocation of processes.
	
	cout<<"Memory status :"<<endl;
	cout<<"\n\n\n\n";
	
	cout<<"Occupied memory slots :"<<endl;
	for(int i=0;i<occ;i++)
	{
		cout<<"Start: "<<occupied[i][0]<<" End: "<<occupied[i][1]<<endl;
	}
	cout<<"Free memory: "<<endl;
	cout<<"Start: "<<free[0]<<" End: "<<free[1];
	
	cout<<"\nProcesses not allocated memory : "<<endl;
	for(int i=0;i<nac;i++)
	{
		cout<<"Process "<<na[i]+1;	
	}	
	delete []process;
	return 0;
	
}
