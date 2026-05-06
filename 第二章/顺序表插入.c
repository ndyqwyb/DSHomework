// 任务描述
// 已知顺序表 L 递增有序，编写程序，将 X 插入到线性表的适当位置上，以保持线性表的有序性。

// 编程要求
// 根据提示，在右侧编辑器补充代码，完成顺序表的插入操作。

// 测试说明
// 输入说明：
// 第一行输入顺序表元素个数elenum；(0)
// 第二行输入顺序表 L ；
// 第三行输入插入值 X 。

// 输出说明：
// 输出插入 X 后的有序顺序表。

// 平台会对你编写的代码进行测试：

// 测试输入：
// 7
// 2 3 4 5 6 7 8
// 1
// 预期输出：
// 1 2 3 4 5 6 7 8

#include<stdio.h>
void insertelement() {
    //输入
    int elenum;
    scanf("%d", &elenum);
    int array[elenum + 1];
    for(int i = 0; i < elenum; i++) {
        scanf("%d", &array[i]);
    }
    int insertnum;
    scanf("%d", &insertnum);
    //定位
    int pos;
    for(int i = 0; i < elenum; i++) {
        if(array[i] > insertnum) {
            pos = i;
            break;
        }
    }
    //后移
    for(int i = elenum; i >= pos; i--) {
        array[i + 1] = array[i];
    }
    array[pos] = insertnum;
    //输出
    for(int i = 0; i < elenum + 1; i++) {
        printf("%d ", array[i]);
    }
}
int main() {
    insertelement();
    return 0;
}