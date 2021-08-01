/*
Approach:

>> make a struture with index[] and words[]
>> sort the individual words in words[]
sort the whole words[] A/C to 1st character of each word


*/

#include<bits/stdc++.h>
#include<cstring>
#include<algorithm>

using namespace std;

struct MyHash
{
	int index;
	string word;
};

//MODIFYING our sort() as per 2nd step
bool cmp(struct MyHash m1,struct MyHash m2)
{
	return (m1.word[0]>m2.word[0]);
}

void printAnagramsTogether(struct MyHash m[],int size,char *words[])
{
	//dummy variables
	string temp=" ";
	
	//sort individual words of words[]
	for(int i=0;i<size;i++)
	{
		temp=m[i].word;
		//l=temp.length();
		//string ki length se nhi kar sakte sort
		sort(temp.begin(),temp.end());
		
		//resetting
		temp=" ";
	}
	
	//sort the whole words[] A/C to 1st character of each word
	sort(m,m+size,cmp);
	
	//now the sequence of words must be changed, we need to take help from original array in input
	//traverse the sorted structure and us us index pe original array me jo word hai vo print karte jaao
	cout<<"\n\n{ ";
	int indx;
	for(int i=0;i<size;i++)
	{
		indx=m[i].index;
		cout<<words[indx]<<" ";
	}
	cout<<" } ";
	
}

int main()
{	
	//inputs
	int size=5;
	int index[size]={0,1,2,3,4};                          //corresponding indices
	char *words[size]={"cat","dog","tac","god","act"};    //origonal array
	
	
	//filling structure
	struct MyHash m[size] = 
	{
		{0,"cat"},
		{1,"dog"},
		{2,"tac"},
		{3,"god"},
		{4,"act"}
	};

    printAnagramsTogether(m,size,words);
	
return 0;
}
