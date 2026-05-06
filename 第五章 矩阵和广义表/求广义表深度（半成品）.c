// 任务描述
// 试按表头、表尾的分析方法编写求广义表的深度的递归程序。

// 编程要求
// 根据提示，在右侧编辑器补充代码，求广义表的深度。

// 测试说明
// 输入说明：
// 输入一串以‘(’开始，以‘(’结束的字符串，并且输入的左右括号必须匹配，如：(),(())……

// 输出说明：
// 分别输出按表头、表尾分析方法求广义表深度的结果，每个结果占一行。

// 平台会对你编写的代码进行测试：

// 测试输入：
// ((a,b,(c,(d,e),f)),g)
// 预期输出：
// 4
// 4

#include<stdio.h>
#include<stdlib.h>

typedef enum {atom, list} ElemTag;

typedef struct GLNode{
    ElemTag tag;
    union {
        char elem;
        struct {
            struct GLNode *head, *tail;
        }ptr;
    }p;
}GLNode, *GList;

void createElem(GList *list); 
void createList(GList *list); 

void createList(GList *list) {
    int ch;
    ch = getchar();
    while(ch == ',') ch = getchar();

    //空表
    if(ch == ')') {
        *list = NULL;
        return;
    }

    //如果不是空表 malloc内存并且吐回去getchar内容
    ungetc(ch, stdin);
    *list = (GList)malloc(sizeof(GLNode));
    (*list)->tag = 1;

    //读head
    createElem(&(*list)->p.ptr.head);

    //读后续的逗号或右括号
    ch = getchar();
    if(ch == ',') {
        //给tail创建新表
        createList(&(*list)->p.ptr.tail);
    }
    else if(ch == ')') {
        (*list)->p.ptr.tail = NULL;
    }
    else if(ch == EOF) {
        (*list)->p.ptr.tail = NULL;  //读到空表结尾
    }
}

void createElem(GList *list) {
    int ch;
    ch = getchar();
    while(ch == ',') ch = getchar();

    if (ch == EOF) {
        *list = NULL;
        return;
    }

    if (ch == '(') {
        createList(list);
    } else if (ch == ')') { //空表
        *list = NULL;
    } else {
        *list = (GList)malloc(sizeof(GLNode));
        (*list)->tag = 0;
        (*list)->p.elem = (char)ch;
    }
}

//测深度
int GListDepth(GList list) {
    //空集返回1
    if(!list) return 1;
    //原子节点返回0
    if(list->tag == 0) return 0;
    int max = 0;
    //创建一个遍历指针 在外层for遍历
    for(GList ptr = list; ptr; ptr = ptr->p.ptr.tail) {
        //在内层递归遍历
        int dep = GListDepth(ptr->p.ptr.head);
        if(dep > max) max = dep;
    }
    //统计完一整层的max 最终+1返回上层
    return max + 1;
}

int main() {
    GList list = NULL;
    int ch = getchar();
    if (ch == '(') {
        createList(&list);
    }
    int depth = GListDepth(list);
    printf("%d\n%d", depth, depth);
}