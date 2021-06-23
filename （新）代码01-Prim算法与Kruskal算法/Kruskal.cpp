#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using  namespace std;

const int Maxvertex = 10;// 最多顶点数
const int MaxEdge = 100;// 最多边数

struct EdgeType
{
    int from, to;// 边依附的两个顶点
    int weight;// 边的权值
};

template<class T>
struct EdgeGraph
{
    T vertex[Maxvertex];// 存放顶点信息
    vector<EdgeType> edge;// 存放边的数组(用vector便于排序)
    int vertexNum, edgeNum;//顶点数和边数
};
int FindRoot(int parent[], int v)// 求顶点的双亲结点
{
    int t = v;
    while(parent[t]> -1)
        t = parent[t];
    return t;
}
void Kruskal(EdgeGraph<int> G)
{
    int parent[Maxvertex];
    for (int i = 0; i < G.vertexNum; i++)
        parent[i] = -1;// 表示顶点i没有双亲结点
    for (int num = 0, i = 0; i < G.edgeNum; i++) {
        int vex1 = FindRoot(parent, G.edge[i].from);
        int vex2 = FindRoot(parent, G.edge[i].to);
        if (vex1 != vex2) {
            cout << G.edge[i].from << G.edge[i].to << endl;
            parent[vex2] = vex1;// 合并生成树
            num++;
            if (num == G.vertexNum - 1)
                return;
        }
    }
}
bool sort_by_weight(EdgeType&k1, EdgeType&k2)
{
    return k1.weight < k2.weight;
}
int main()
{
    EdgeGraph<int> Edgraph;// 存放图的信息
    //构建图G
    cin >> Edgraph.vertexNum >> Edgraph.edgeNum;
    for (int k = 0; k <Edgraph.edgeNum; k++)
    {
        EdgeType temp;
        cin >> temp.from >> temp.to >> temp.weight;
        Edgraph.edge.push_back(temp);
    }
    // 将边按照权值排序
    sort(Edgraph.edge.begin(), Edgraph.edge.end(), sort_by_weight);
    Kruskal(Edgraph);
    return 0;
}