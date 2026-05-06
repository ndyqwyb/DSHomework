// 任务描述
// 试分别以不同的存储结构实现线性表的就地逆置算法

// (1)以一维数组作存储结构。
// (2)以单链表作存储结构。

// 编程要求
// 根据提示，在右侧编辑器补充代码，完成线性表的就地逆置。

// 测试说明
// 输入说明：
// 第一行输入线性表元素个数elenum；
// 第二行输入elenum个数，作为线性表中的元素

// 输出说明：
// 分两行分别输出要求（1）和要求（2）的线性表逆置结果

// 平台会对你编写的代码进行测试：

// 测试输入：
// 5
// 2 5 3 7 15
// 预期输出：
// 15 7 3 5 2
// 15 7 3 5 2

#include<stdio.h>
#include<stdlib.h>
void ReverseArray(int elenum, int array[]) {
    //reverse
    for(int i = 0; i < elenum / 2; i++) {
        int temp;
        temp = array[i];
        array[i] = array[elenum - i - 1];
        array[elenum - i - 1] = temp;
    }
    
}

typedef struct Node {
    int num;
    struct Node *next;
}Node, *PNode, *PLinklist;

void InsertNode(int element, PNode p) {
    PNode newNode = (PNode)malloc(sizeof(Node));
    newNode->num = element;
    newNode->next = p->next;
    p->next = newNode;
}

void ReverseAndPrintLinkList(int elenum, int array[]) {
    //创建链表以及尾插指针
    PLinklist linklist = (PLinklist)malloc(sizeof(Node));
    linklist->next = NULL;
    PNode tail = linklist;
    //输入
    for(int i = 0; i < elenum; i++) {
        int temp = array[i];
        InsertNode(temp, tail);
        tail = tail->next;
    }
    //reverse
    PNode head = linklist->next;
    while(head->next != NULL) {
        PNode temp = head->next;
        head->next = temp->next;
        temp->next = linklist->next;
        linklist->next = temp;
    }
    //print
    PNode pointer = linklist->next;
    while(pointer->next != NULL) {
        printf("%d ", pointer->num);
        pointer = pointer->next;
    }
    printf("%d", pointer->num);
}

int main() {
    //输入
    int elenum;
    scanf("%d", &elenum);
    int array[elenum];
    for(int i = 0; i < elenum; i++) {
        scanf("%d", &array[i]);
    }
    ReverseArray(elenum, array);
    //输出  服了 被翻转了传进linklist还得再翻一遍 能不能人性化一点 输入一遍的元素要输出两遍本来就不好存
    for(int i = 0; i < elenum - 1; i++) {
        printf("%d ", array[i]);
    }
    printf("%d\n", array[elenum-1]);
    ReverseArray(elenum, array);
    ReverseAndPrintLinkList(elenum, array);
}