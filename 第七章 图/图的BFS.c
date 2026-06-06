// 任务描述
// 试基于图的广度优先搜索策略编写程序，判别以邻接表方式存储的有向图中，是否存在由顶点v 
// i
// ​
//  到顶点v 
// j
// ​
//  （i不等于j）。注意：程序中涉及的图的基本操作必须在此存储结构上实现。

// 编程要求
// 根据提示，在右侧编辑器补充代码，完成基于图的广度优先搜索策略。

// 测试说明
// 输入说明：
// 第一行输入有向图的顶点数 n 和边数 m ，用空格隔开；
// 第二行输入顶点信息；分m行输入有向图边的信息，例如顶点对1,2表示从顶点1到顶点2的一条弧。最后一行输入待判别的顶点对v 
// i
// ​
//  ,v 
// j
// ​
//  。(0)
// 输出说明：
// 若有向图中存在由顶点v 
// i
// ​
//  到顶点v 
// j
// ​
//  的路径（i不等于j），则输出yes；否则输出no。

// 平台会对你编写的代码进行测试：

// 测试输入：

// 4 4
// 1 2 3 4
// 1 2
// 1 3
// 1 4
// 2 3
// 2 3
// 预期输出：
// yes

#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int id;
    struct Node *next;
}Node;

typedef struct Graph {
    Node* head[100];
    int vexnum;
    int edgenum;
}Graph;


void BuildGraph(Graph* g, int vexnum, int edgenum) {
    g->vexnum = vexnum;
    g->edgenum = edgenum;
    //初始化空表位置
    for(int i = 0; i < 100; i++) {
        g->head[i] = NULL;
    }

    //初始化头结点
    for(int i = 0; i < vexnum; i++) {
        int tempid;
        scanf("%d", &tempid);

        Node* tempnode = (Node*)malloc(sizeof(Node));
        tempnode->id = tempid;
        tempnode->next = NULL;

        g->head[tempid] = tempnode;
    }

    //初始化边
    for(int i = 0; i < edgenum; i++) {
        int start, end;
        scanf("%d %d", &start, &end);

        Node* endnode = (Node*)malloc(sizeof(Node));
        endnode->id = end;
        
        endnode->next = g->head[start]->next;
        g->head[start]->next = endnode;
    }
}


int BFSSearch(Graph* g, int start, int end) {
    int visited[100] = {0};
    //建队列
    int queue[200];
    int front = 0, rear = 0;

    //start元素入队记录
    visited[start] = 1;
    queue[rear++] = start;
    //循环建立visited数组
    while(front != rear) {
        //出队
        int curnum = queue[front++];

        //循环入队
        Node* curnode = g->head[curnum]->next;
        while(curnode) {
            if(!visited[curnode->id]) {
                visited[curnode->id] = 1;
                queue[rear++] = curnode->id;
            }
            curnode = curnode->next;
        }
    }

    //判断
    return visited[end];
}

int main() {
    int vexnum, edgenum;
    scanf("%d %d", &vexnum, &edgenum);
    Graph g;
    BuildGraph(&g, vexnum, edgenum);
    
    int start, end;
    scanf("%d %d", &start, &end);
    int res = BFSSearch(&g, start, end);
    
    if(res == 1) printf("yes");
    else printf("no");
}