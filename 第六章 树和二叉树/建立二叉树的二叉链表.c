// 任务描述
// 已知一棵二叉树的前序序列和中序序列分别存于两个一维数组中，试编写算法建立该二叉树的二叉链表。

// 编程要求
// 根据提示，在右侧编辑器补充代码，建立二叉树的二叉链表。

// 测试说明
// 输入说明：
// 分两行分别输入一棵二叉树的前序序列和中序序列。
// 输出说明：
// 输出该二叉树的后序序列。

// 平台会对你编写的代码进行测试：

// 测试输入：
// ABDFGCEH
// BFDGACEH
// 预期输出：
// FGDBHECA

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node {
    char c;
    struct Node *l, *r;
}Node;

int pos[256];

Node* BuildTree(char** pre, const char* in, int l, int r) {
    if(l > r) return NULL;

    char rootc = **pre;
    (*pre)++;
    int mid = pos[(unsigned char)rootc];
    
    Node* root = (Node*)malloc(sizeof(Node));
    root->c = rootc;
    root->l = BuildTree(pre, in, l, mid - 1);
    root->r = BuildTree(pre, in, mid + 1, r);

    return root;
}

void PostOut(Node* root) {
    if(!root) return;
    PostOut(root->l);
    PostOut(root->r);
    putchar(root->c);
}

int main() {
    //input
    char pre[100], in[100];
    scanf("%s%s", pre, in);

    //建立pos数组
    int n = strlen(pre);
    for(int i = 0; i < n; i++) {
        pos[(unsigned char)in[i]] = i;
    }

    //生成树并输出
    char* p = pre;
    Node* root = BuildTree(&p, in, 0, n - 1);
    PostOut(root);
}