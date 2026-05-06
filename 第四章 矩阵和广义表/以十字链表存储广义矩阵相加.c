// 任务描述
// 以十字链表为存储结构，编写程序，将稀疏矩阵 B 加到稀疏矩阵 A 上。

// 编程要求
// 根据提示，在右侧编辑器补充代码，完成以十字链表为存储结构的矩阵相加。

// 测试说明
// 输入说明：
// 第一行输入四个正整数，分别为稀疏矩阵A和稀疏矩阵B的行数m、列数n、稀疏矩阵A的非零元素个数t1和稀疏矩阵B的非零元素个数t2。接下来的t1+t2行三元组表示，其中第一个元素表示非零元素所在的行值，第二个元素表示非零元素所在的列值，第三个元素表示非零元素的值。

// 输出说明：
// 输出相加后的矩阵三元组。

// 平台会对你编写的代码进行测试：

// 测试输入：

// 3 4 3 2
// 1 1 1
// 1 3 1
// 2 2 2
// 1 2 1
// 2 2 3
// 预期输出：

// 1 1 1
// 1 2 1
// 1 3 1
// 2 2 5

#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int row, col, val;
    struct Node *right, *down;
}Node, *PNode;

typedef struct {
    int row, col, num;
    PNode *rhead, *chead;
}crosslist;

crosslist initcrosslist(int r, int c) {
    crosslist m;
    m.row = r;
    m.col = c;
    m.num = 0;
    //calloc行列表头分别r和c个NULL存储位置
    m.rhead = (PNode*)calloc(r, sizeof(PNode));
    m.chead = (PNode*)calloc(c, sizeof(PNode));
    return m;
}

void insertnode(crosslist *m, PNode temp) {
    //插入行链
    PNode pre = NULL;
    PNode cur = m->rhead[temp->row];
    //遍历到当前要插入位置的前置指针pre和当前指针cur
    while(cur && cur->col < temp->col) {
        pre = cur;
        cur = cur->right;
    }
    //如果数据位置相同 便累加
    if(cur && cur->col == temp->col) {
        cur->val += temp->val;
        //若为0则删除行链列链连接处
        if(cur->val == 0) {
            //删除行链连接
            if(pre) pre->right = cur->right;
            else m->rhead[temp->row] = cur->right;
            //删除列链连接
            //重新定pre和cur
            pre = NULL;
            cur = m->chead[temp->col];
            //重新遍历到当前col
            while(cur && cur->row < temp->row) {
                pre = cur;
                cur = cur->down;
            }
            //删掉
            if(pre) pre->down = cur->down;
            else m->chead[temp->col] = cur->down;
            //个数建议
            m->num--;
        }
        return;
    }
    //插入node
    temp->right = cur;
    if(pre) pre->right = temp;
    else m->rhead[temp->row] = temp;

    //插入列链
    pre = NULL;
    cur = m->chead[temp->col];
    //遍历到当前
    while(cur && cur->row < temp->row) {
        pre = cur;
        cur = cur->down;
    }
    //插入node
    temp->down = cur;
    if(pre) pre->down = temp;
    else m->chead[temp->col] = temp;

    m->num++;
}

void outputmatrix(crosslist *m) {
    for(int i = 0; i < m->row; i++) {
        PNode cur = m->rhead[i];
        while(cur) {
            //记得把按0基存储的按1基输出
            printf("%d %d %d\n", cur->row + 1, cur->col + 1, cur->val);
            cur = cur->right;
        }
    }
}

int main() {
    //输入
    int r, c, sum1, sum2, sum;
    scanf("%d %d %d %d", &r, &c, &sum1, &sum2);
    sum = sum1 + sum2;
    //初始化链表
    crosslist m = initcrosslist(r, c);
    //a和b矩阵的元素都加进去
    for(int i = 0; i < sum; i++) {
        PNode temp = (PNode)malloc(sizeof(Node));
        scanf("%d %d %d", &temp->row, &temp->col, &temp->val);
        //1基的元素插进去先全都--，默认为0基
        temp->row--;
        temp->col--;
        temp->right = NULL;
        temp->down = NULL;
        insertnode(&m, temp);
    }
    outputmatrix(&m);
}