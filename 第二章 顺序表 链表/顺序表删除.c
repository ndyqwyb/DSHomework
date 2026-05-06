// 任务描述
// 已知 A , B 和 C 为三个非递减有序的线性表，现要求对 A 表作如下操作：删去那些既在 B 表中出现又在 C 表中出现的元素。试对顺序表编写实现上述操作的算法。

// 编程要求
// 根据提示，在右侧编辑器补充代码，完成顺序表的删除操作。

// 测试说明
// 输入说明：第一行输入 3 个正整数 m,n,p (m,n,p<=100)，用空格分开，分别表示三个线性表中的元素个数，其后 3 行依次输入 A,B,C 表中的元素。

// 输出说明：输出实现上述操作后的A表。

// 平台会对你编写的代码进行测试：

// 测试输入：
// 8 5 6
// 1 2 3 4 5 6 6 7
// 2 3 5 9 12
// 2 4 5 6 12 13
// 预期输出：
// 1 3 4 6 6 7

#include<stdio.h>
void DeleteElement(int arr[], int pos, int size) {
    for(int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
}
int MergeArray(int arr1[], int arr2[], int size1, int size2) {
    int i = 0, j = 0;
    //查找删除
    while(i != size1 && j != size2) {
        if(arr1[i] > arr2[j]) {
            j++;
        }
        else if(arr1[i] < arr2[j]) {
            DeleteElement(arr1, i, size1);
            size1--;
        }
        else {
            i++;
            j++;
        }
    }
    //若arr1有剩余则全删掉
    if(i != size1) {
        size1 = i;
    }
    //返回size
    return size1;
}
int DeleteArray(int arr1[], int arr2[], int size1, int size2) {
    int i = 0, j = 0;
    //查找删除
    while(i != size1 && j != size2) {
        if(arr1[i] > arr2[j]) {
            j++;
        }
        else if(arr1[i] < arr2[j]) {
            i++;
        }
        else {
            DeleteElement(arr1, i, size1);
            size1--;
            j++;
        }
    }
    return size1;
}
int main() {
    //input
    int size1, size2, size3;
    scanf("%d %d %d", &size1, &size2, &size3);
    int arr1[size1], arr2[size2], arr3[size3];
    for(int i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }
    for(int i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }
    for(int i = 0; i < size3; i++) {
        scanf("%d", &arr3[i]);
    }
    //合并并删除
    size2 = MergeArray(arr2, arr3, size2, size3);
    size1 = DeleteArray(arr1, arr2, size1, size2);
    //输出
    for(int i = 0; i < size1 - 1; i++) {
        printf("%d ", arr1[i]);
    }
    printf("%d", arr1[size1 - 1]);
}