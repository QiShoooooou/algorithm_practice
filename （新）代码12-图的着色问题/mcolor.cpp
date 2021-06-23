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
//    顶点的个数n（2≤n≤10），颜色数m（1≤m≤n)
	cin>>n>>m;
    while (1){
    	cin>>a>>b;
    	if(a*b==0) break;
        graph[a][b] = graph[b][a] = 1;
    }
    cout<<"各方案如下："<<endl;
    backtrack(1);
    if (cnt) cout<<"Total="<<cnt<<"种"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
