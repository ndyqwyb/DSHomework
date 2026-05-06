// 任务描述
// 已知 A , B 和 C 为三个非递减有序的线性表，均以单链表作为存储结构。现要求对 A 表作如下操作：删去那些既在 B 表中出现又在 C 表中出现的元素。试对单链表编写实现上述操作的算法，并释放 A 表中的无用结点空间。

// 编程要求
// 根据提示，在右侧编辑器补充代码，完成单链表的删除操作。

// 测试说明
// 输入说明：
// 第一行输入 3 个正整数m, n, p (m,n,p<=100)，用空格分开，表示三个线性表中的元素个数，其后 3 行依次输入A,B,C表中的元素。

// 输出说明：
// 输出实现上述操作后的 A 表。

// 平台会对你编写的代码进行测试：

// 测试输入：
// 8 5 6
// 1 2 3 4 5 6 6 7
// 2 3 5 9 12
// 2 4 5 6 12 13
// 预期输出：
// 1 3 4 6 6 7

#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int num;
    struct Node* next;
}Node, *PNode;

void InputLinklist(int size, PNode linklist) {
    PNode tail = linklist;
    for(int i = 0; i < size; i++) {
        PNode newnode = (PNode)malloc(sizeof(Node));
        newnode->next = NULL;
        scanf("%d", &newnode->num);
        tail->next = newnode;
        tail = tail->next;
    }
}

int Merge(PNode linklistA, PNode linklistB, int sizeA, int sizeB) {
    int newsize = 0;
    PNode pointerA = linklistA;
    PNode pointerB = linklistB;
    while(pointerA->next != NULL && pointerB->next != NULL) {
        if(pointerA->next->num == pointerB->next->num) {
            pointerA = pointerA->next;
            pointerB = pointerB->next;
            newsize++;
        }
        else if(pointerA->next->num > pointerB->next->num) {
            pointerB = pointerB->next;
        }
        else {
            pointerA->next = pointerA->next->next;
        }
    }
    if(pointerA->next != NULL) pointerA->next = NULL;
    return newsize;
}

int Delete(PNode linklistA, PNode linklistB, int sizeA, int sizeB) {
    int newsize = sizeA;
    PNode pointerA = linklistA;
    PNode pointerB = linklistB;
    while(pointerA->next != NULL && pointerB->next != NULL) {
        if(pointerA->next->num == pointerB->next->num) {
            pointerA->next = pointerA->next->next;
            newsize--;
        }
        else if(pointerA->next->num > pointerB->next->num) {
            pointerB = pointerB->next;
        }
        else {
            pointerA = pointerA->next;
        }
    }
    return newsize;
}

int main() {
    int sizeA, sizeB, sizeC;
    scanf("%d %d %d", &sizeA, &sizeB, &sizeC);
    PNode PA = (PNode)malloc(sizeof(Node));
    PNode PB = (PNode)malloc(sizeof(Node));
    PNode PC = (PNode)malloc(sizeof(Node));
    InputLinklist(sizeA, PA);
    InputLinklist(sizeB, PB);
    InputLinklist(sizeC, PC);
    sizeB = Merge(PB, PC, sizeB, sizeC);
    sizeA = Delete(PA, PB, sizeA, sizeB);
    PNode out = PA->next;
    for(int i = 0; i < sizeA - 1; i++) {
        printf("%d ", out->num);
        out = out->next;
    }
    printf("%d", out->num);
}