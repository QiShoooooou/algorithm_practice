#include<iostream>
using namespace std;
const int n=20;
int T[n]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};

int selectSearch(int x){
	int i,flag=0;
	for(i=0;i<n;i++){
		if(T[i]==x){
			flag=1;
			break;
		}
	}
	if(flag==1)
	return i;
	else
	return -1;
	
}

int binarySearch(int x){
	int a,b,c,flag=0;
	a=0;
	c=n-1;
	while(a<=c){
		b=(a+c)/2;
		if(T[b]<x){
			a=b+1;
		}
		else if(T[b]>x){
			c=b-1;
		}
		else{
			flag=1;
			return b;
		}	
		}
	return -1;
}
int main(){
	int x,j;
	cin>>x;
	//j=selectSearch(x);
	j=binarySearch(x);
	if(j!=-1)
	cout<<x<<"在T的下标j="<<j;
	else
	cout<<"j=0";
}
