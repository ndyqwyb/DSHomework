// 任务描述
// 假设一个算术表达式中可以包含三种括号：圆括号“（ ”和“ ）”、方括号“ [ ”和“ ] ”和花括号“{”和“}”，且这三种括号可按任意的次序嵌套使用（如：…[…{…}…[…]…]…[…]…(…)…）。编写判别给定表达式中所含括号是否正确配对出现的程序（已知表达式已存入数据元素为字符的顺序表中）。

// 编程要求
// 根据提示，在右侧编辑器补充代码，完成表达式括号匹配。

// 测试说明
// 输入说明：输入算术表达式，换行结束。

// 输出说明：若给定表达式中所含括号正确配对，则输出 yes，否则输出 no。

// 平台会对你编写的代码进行测试：

// 测试输入：[5+(6-3)]-(2+3)]
// 预期输出：no

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Stack {
    char s[100];
    int top;
}Stack, *PStack;

void push(PStack stk, char c) {
    stk->top = stk->top + 1;
    stk->s[stk->top] = c;
}

int IsEmpty(PStack stk) {
    if(stk->top == -1) return 1;
    else return 0;
}

char top(PStack stk) {
    return stk->s[stk->top];
}

void pop(PStack stk) {
    stk->top = stk->top - 1;
}

int IsMatch(char a, char b) {
    return ( (a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}') );
}

int main() {
    int ch;
    //初始化栈
    PStack stk = (PStack)malloc(sizeof(Stack));
    stk->top = -1;
    //开始getchar
    while((ch = getchar()) != '\n' && ch != EOF) {
        //左括号入栈
        if(ch == '(' || ch == '[' || ch == '{') {
            push(stk, (char)ch);
        }
        //右括号查找是否空栈以及是否匹配
        else if(ch == ')' || ch == ']' || ch == '}') {
            if(IsEmpty(stk) || !IsMatch(top(stk), (char)ch)) {
                printf("no");
                return 0;
            }
            else {
                pop(stk);
            }
        }
    }
    //检测是否空栈
    if(IsEmpty(stk)) {
        printf("yes");
        return 0;
    }
    else {
        printf("no");
        return 0;
    }
}