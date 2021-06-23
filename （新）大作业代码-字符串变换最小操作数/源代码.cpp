#include<iostream>
#include<string.h>
using namespace std;
const int Max =2000;

char s1[Max], s2[Max];
int t[Max][Max];

int mint() 
{
    int l1 = strlen(s1 + 1);
    int l2 = strlen(s2 + 1);
    for(int i = 0; i <= l1; i++)
		t[i][0] = i;
    for(int i = 0; i <= l2; i++)
        t[0][l2] = i;
    for(int i = 1; i <= l1; i++) 
	{
        for(int j = 1; j <= l2; j++) 
		{
            if(s1[i] == s2[j])
                t[i][j] = t[i - 1][j - 1]+1;
            else
            {
            	int tmp = min(t[i - 1][j]+1, t[i][j - 1]+1);
                t[i][j] = min(t[i - 1][j - 1]+1, tmp);
			}
        }
    }
    return t[l1][l2];
}

int main() {
    cout<<"请输入源串:";
    cin>>s1;
    cout<<"请输入目标串:";
    cin>>s2;
    cout<<"源串变成目标串的最小操作次数为:";
    cout<<mint()<<endl;
    system("pause");
}
