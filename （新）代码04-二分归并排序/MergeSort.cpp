#include<iostream>
#define MAX 100
using namespace std;
int a[MAX];
int newA[MAX];
void Merge(int first,int middle,int last){
	int i=first;
	int j=middle+1;
	int p=first;
	while(i<=middle && j<=last){
		if(a[i]>a[j])
		  newA[p++]=a[j++];
		else
		  newA[p++]=a[i++];
	}
	while(i!=middle+1)
	  newA[p++]=a[i++];
	while(j!=last+1)
	   newA[p++]=a[j++];
	for(int b=first;b<=last;b++)
	   a[b]=newA[b];
} 
void MergeSort(int first,int last){//»®·Ö
	int middle;
	if(first<last){
	  middle=(first+last)/2;
	  MergeSort(first,middle);
	  MergeSort(middle+1,last);
	  Merge(first,middle,last);
    }
	
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	MergeSort(0,n-1);
	for(int i=0;i<=n-1;i++){
	   cout<<a[i]<<' ';
	}
	return 0;
}

