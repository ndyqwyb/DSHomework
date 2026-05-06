// 任务描述
// 设有一个双向循环链表，每个结点中除有 pre，data 和 next 三个域外，还增设了一个访问频度域 freq 。在链表被起用之前，频度域 freq 的值均初始化为零，而每当对链表进行一次 LOCATE（L,x）的操作后，被访问的结点（即元素值等于 x 的结点）中的频度域 freq 的值便增 1，同时调整链表中结点之间的次序，使其按访问频度非递增的次序排列，以便始终保持被频繁访问的结点总是靠近表头结点。试编写符合上述要求的 LOCATE 操作的程序。

// 编程要求
// 根据提示，在右侧编辑器补充代码，完成 LOCATE 操作。

// 测试说明
// 输入说明：
// 第一行输入双向循环链表的节点数 m 和被访问的节点数 n，
// 第二行输入双向循环链表各节点的值，
// 第三行依次输入被访问的节点。

// 输出说明：
// 输出符合上述要求的双向循环链表。
// 输出经过n次LOCATE后的链表。

// 平台会对你编写的代码进行测试：

// 测试输入：
// 7 1
// a b c d e f g
// d
// 预期输出：
// d a b c e f g

#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    struct Node *pre;
    char data;
    int freq;
    struct Node *next;
}Node, *PNode;

void InitDBList(PNode DBList, int size) {
    PNode tail = DBList;
    for(int i = 0; i < size; i++) {
        PNode newnode = (PNode)malloc(sizeof(Node));
        scanf(" %c", &newnode->data);
        newnode->freq = 0;
        newnode->pre = tail;
        newnode->next = NULL;
        tail->next = newnode;
        tail = tail->next;
    }
}

PNode Locate(PNode pointer, char value) {
    while(pointer->data != value) {
        pointer = pointer->next;
    }
    pointer->freq++;
    return pointer;
}

void Resort(PNode pointer, PNode DBList) {
    while(pointer->pre->data != '#' && pointer->freq > pointer->pre->freq) {
        //存前驱节点
        PNode temp = pointer->pre;
        //将当前节点的前后节点进行连接
        temp->next = pointer->next;
        if(pointer->next != NULL) {
            pointer->next->pre = pointer->pre;
        }
        //修改当前节点的前后指针
        pointer->pre = temp->pre;
        pointer->next = temp;
        //修改最后两个应该指向当前节点的指针(最后修改temp的pre)
        temp->pre->next = pointer;
        temp->pre = pointer;
    }
}

void Access(PNode DBList, char value) {
    PNode pointer = DBList->next;
    pointer = Locate(pointer, value);
    Resort(pointer, DBList);
}

int main() {
    //input
    int size, accessnum;
    scanf("%d %d", &size, &accessnum);
    PNode DBList = (PNode)malloc(sizeof(Node));
    //初始化头结点
    DBList->pre = NULL;
    DBList->data = '#';
    DBList->next = NULL;
    //初始化链表
    InitDBList(DBList, size);
    //按循环次数访问
    for(int i = 0; i < accessnum; i++) {
        char temp;
        scanf(" %c", &temp);
        Access(DBList, temp);
    }
    //output
    PNode out = DBList->next;
    for(int i = 0; i < size - 1; i++) {
        printf("%c ", out->data);
        out = out->next;
    }
    printf("%c", out->data);
}