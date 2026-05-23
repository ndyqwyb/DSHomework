// 任务描述
// 二叉树按照二叉链表方式存储，编写程序，计算二叉树中叶子结点的数目。

// 编程要求
// 根据提示，在右侧编辑器补充代码，完成计算二叉树叶子结点数目。

// 测试说明
// 输入说明：
// 按先序输入二叉树各结点，其中#表示取消建立子树结点。
// 输出说明：
// 输出二叉树中叶子节点的数目。

// 平台会对你编写的代码进行测试：

// 测试输入：ABD##EH###CF#I##G##
// 预期输出：4

#include<stdio.h>

int Cal(char** str) {
    int ans = 0;
    int count = -1;
    while(**str != '\0') {
        if(**str != '#') {
            count = 0;
        }
        else {
            count++;
        }
        (*str)++;
        if(count == 2) ans++;
    }
    return ans;
}

int main() {
    char str[100];
    scanf("%s", str);
    char* p = str;
    int ans = Cal(&p);
    printf("%d", ans);
}