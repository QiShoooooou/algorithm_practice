#include<bits/stdc++.h> 
using namespace std;
int n, m,a = 1, b = 1,cnt;
int graph[20][20],color[20];

bool check(int x) {
    for (int i = 1; i <= n; i++)
        if (graph[x][i] && color[x] == color[i])
            return false;
    return true;
}

void backtrack(int cur) {
    if (cur > n) {
        for (int i = 1; i <= n; i++)
            cout<<color[i];
        cnt++;
        cout<<endl;
    }
    else {
        for (int i = 1; i <= m; i++) {
            color[cur] = i;
            if (check(cur))
                backtrack(cur + 1);
            color[cur] = 0;
        }
    }
}

int main()
{
    freopen("input.txt","r",stdin);
//    ����ĸ���n��2��n��10������ɫ��m��1��m��n)
	cin>>n>>m;
    while (1){
    	cin>>a>>b;
    	if(a*b==0) break;
        graph[a][b] = graph[b][a] = 1;
    }
    cout<<"���������£�"<<endl;
    backtrack(1);
    if (cnt) cout<<"Total="<<cnt<<"��"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
