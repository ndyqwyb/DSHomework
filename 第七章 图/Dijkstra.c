// 任务描述
// 编写程序，实现以邻接表作存储结构，求从源点到其余各顶点的最短路径的 Dijkstra 算法。

// 编程要求
// 根据提示，在右侧编辑器补充代码，实现Dijkstra算法。

// 测试说明
// 输入说明：
// 第一行输入顶点数 n 和边数 m；
// 第二行输入顶点信息；分 m 行输入 m 对顶点v 
// i
// ​
//  ，v 
// j
// ​
//  （表示由顶点v 
// i
// ​
//  到顶点v 
// j
// ​
//  （i不等于j）的边）以及该弧的权值。(0)
// 输出说明：
// 输出从源点到其余各顶点的最短路径（不可达用-1表示）。

// 平台会对你编写的代码进行测试：

// 测试输入：

// 6 11
// 1 2 50
// 1 3 10
// 1 5 45
// 2 3 15
// 2 5 10
// 3 1 20
// 3 4 15
// 4 2 20
// 4 5 35
// 5 4 30
// 6 4 3 
// 预期输出：

// 1 3 10
// 1 4 25
// 1 2 45
// 1 5 45
// 1 6 -1

#include<stdio.h>
#include<stdlib.h>
#define INF 9999

typedef struct EdgeNode {
    int id;
    int weight;
    struct EdgeNode* next;
}EdgeNode;

typedef struct VexNode {
    int id;
    EdgeNode* next;
}VexNode;

typedef struct Graph {
    VexNode* head[100];
    int vexnum, edgenum;
}Graph;

void initgraph(Graph* g, int vexnum, int edgenum) {
    g->vexnum = vexnum;
    g->edgenum = edgenum;

    //初始化空节点
    for(int i = 0; i < 100; i++) {
        g->head[i] = NULL;
    }

    //初始化头结点
    for(int i = 1; i <= vexnum; i++) {
        VexNode* temp = (VexNode*)malloc(sizeof(VexNode));
        temp->id = i;
        temp->next = NULL;

        g->head[i] = temp;
    }

    //读取边节点
    for(int i = 0; i < edgenum; i++) {
        int start, end, weight;
        EdgeNode* temp = (EdgeNode*)malloc(sizeof(EdgeNode));

        //初始化新边节点
        scanf("%d %d %d", &start, &end, &weight);
        temp->id = end;
        temp->weight = weight;

        //头插
        temp->next = g->head[start]->next;
        g->head[start]->next = temp;
    }
}

void Dijkstra(Graph* g, int* dist, int* visited, int* prev) {
    int vexnum = g->vexnum;

    dist[1] = 0;
    while(1) {
        //找未访问的节点中dist最小的
        int distmin = -1;
        for(int i = 1; i <= vexnum; i++) {
            if(visited[i] == 0 && (distmin == -1 || dist[i] < dist[distmin])) {
                distmin = i;
            }
        }
        
        //若没找到（全部遍历/剩下节点不联通），break
        if(distmin == -1 || dist[distmin] == INF) break;

        //dist最小节点标记访问
        visited[distmin] = 1;

        //找dist最小节点的所有未访问的邻节点，做松弛
        EdgeNode* p = g->head[distmin]->next;
        while(p) {
            int newdist = dist[distmin] + p->weight;
            if(!visited[p->id] && newdist < dist[p->id]) {
                dist[p->id] = newdist;
                prev[p->id] = distmin;
            }
            p = p->next;
        }
    }
}

int main() {
    int vexnum, edgenum;
    scanf("%d %d", &vexnum, &edgenum);
    Graph g;
    initgraph(&g, vexnum, edgenum);

    int dist[vexnum + 1];
    int visited[vexnum + 1];
    int prev[vexnum + 1];

    for(int i = 0; i < vexnum + 1; i++) {
        dist[i] = INF;
        visited[i] = 0;
        prev[i] = 0;
    }

    Dijkstra(&g, dist, visited, prev);

    //按从小到大输出（？）
    int isprinted[vexnum + 1];
    for(int i = 0; i < vexnum + 1; i++) {
        isprinted[i] = 0;
    }
    for(int i = 0; i < vexnum - 1; i++) {
        int mindist = INF + 1;
        int minid = 0;
        for(int j = 2; j <= vexnum; j++) {
            if(!isprinted[j] && dist[j] < mindist) {
                mindist = dist[j];
                minid = j;
            }
        }
        isprinted[minid] = 1;
        if(mindist != INF) {
            printf("1 %d %d\n", minid, mindist);
        }
        else {
            printf("1 %d -1", minid);
        }
    }
}