/*随机生成一组3位整数，
用三种排序方法排序，
并确认输入的数据是否在该数组中，
在——删除改数据，
不在——则将该数据插入在正确的位置上*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble(int aa[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (aa[j] > aa[j + 1]) {
                temp = aa[j];
                aa[j] = aa[j + 1];
                aa[j + 1] = temp;
            }
        }
    }
    printf("进行冒泡排序后的数据是：\n");
    for (j = 0; j <= n - 1; j++)
        printf("%4d", aa[j]);
    printf("\n\n");
}

void swap(int *a, int *b) //交換兩個變數
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection(int aa[], int length) {
    int i, j, temp;
    for (i = 0; i < length - 1; i++) {
        int min = i;
        for (j = i + 1; j < length; j++)
            if (aa[j] < aa[min])
                min = j;
        temp = aa[min];
        aa[min] = aa[i];
        aa[i] = temp;
    }
    printf("进行选择排序后的数据是：\n");
    for (int k = 0; k <= length - 1; k++)
        printf("%4d", aa[k]);
    printf("\n\n");
}

//void selection(int aa[], int n) {
//    int i, j, k, imax, temp;
//    for (i = 0; i < n - 1; i++) {
//        imax = i;
//        for (j = i + 1; j < n; j++) {
//            if (aa[j] > aa[j + 1])
//                imax = j;
//        }
//        if (imax != i) {
//            temp = aa[imax];
//            aa[imax] = aa[i];
//            aa[i] = temp;
//        }
//    }
//    printf("进行选择排序后的数据是：\n");
//    for (k = 0; k <= n - 1; k++)
//        printf("%4d", aa[k]);
//    printf("\n\n");
//}

void insertion(int aa[], int n) {
    int i, j, k, temp;
    for (i = 1; i < n; i++) {
        for (j = i; j >= 0 && aa[j] < aa[j - 1]; j--) {
            temp = aa[j];
            aa[j] = aa[j - 1];
            aa[j - 1] = temp;
        }
    }
    printf("进行插入排序后的数据是：\n");
    for (k = 0; k <= n - 1; k++)
        printf("%4d", aa[k]);
    printf("\n\n");
}

int main() {
    int a[100], i, j, x, n, flag = 1;
    srand(time(NULL));
    printf("请输入原数列长度：");
    scanf("%d", &n);
    printf("原始数列是：\n");
    for (i = 0; i <= n - 1; i++) {
        a[i] = rand() % 900 + 100;
        printf("%4d", a[i]);
    }
    printf("\n\n");
    bubble(a, n);
    selection(a, n);
    insertion(a, n);
    printf("请输入一个三位整数：");
    scanf("%d", &x);
    for (i = 0; i <= n - 1; i++) {
        if (a[i] == x) {
            printf("在该数组中，删除。\n\n");
            for (j = i; j <= n - 1; j++)
                a[j] = a[j + 1];
            flag = 0;
            break;
        } else if (a[i] < x)
            continue;
        else {
            printf("不在该数组中，插入。\n");
            for (j = n - 1; j >= i; j--)
                a[j + 1] = a[j];
            a[i] = x;
            break;
        }
    }
    printf("新数列：\n");
    if (flag == 0) {
        for (i = 0; i <= n - 2; i++)
            printf("%4d", a[i]);
        printf("\n\n");
    } else {
        for (i = 0; i <= n; i++)
            printf("%4d", a[i]);
        printf("\n\n");
    }
    return 0;
}