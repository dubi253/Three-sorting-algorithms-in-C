/*�������һ��3λ������
���������򷽷�����
��ȷ������������Ƿ��ڸ������У�
�ڡ���ɾ�������ݣ�
���ڡ����򽫸����ݲ�������ȷ��λ����*/
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
    printf("����ð�������������ǣ�\n");
    for (j = 0; j <= n - 1; j++)
        printf("%4d", aa[j]);
    printf("\n\n");
}

void swap(int *a, int *b) //���Q�ɂ�׃��
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
    printf("����ѡ�������������ǣ�\n");
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
//    printf("����ѡ�������������ǣ�\n");
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
    printf("���в��������������ǣ�\n");
    for (k = 0; k <= n - 1; k++)
        printf("%4d", aa[k]);
    printf("\n\n");
}

int main() {
    int a[100], i, j, x, n, flag = 1;
    srand(time(NULL));
    printf("������ԭ���г��ȣ�");
    scanf("%d", &n);
    printf("ԭʼ�����ǣ�\n");
    for (i = 0; i <= n - 1; i++) {
        a[i] = rand() % 900 + 100;
        printf("%4d", a[i]);
    }
    printf("\n\n");
    bubble(a, n);
    selection(a, n);
    insertion(a, n);
    printf("������һ����λ������");
    scanf("%d", &x);
    for (i = 0; i <= n - 1; i++) {
        if (a[i] == x) {
            printf("�ڸ������У�ɾ����\n\n");
            for (j = i; j <= n - 1; j++)
                a[j] = a[j + 1];
            flag = 0;
            break;
        } else if (a[i] < x)
            continue;
        else {
            printf("���ڸ������У����롣\n");
            for (j = n - 1; j >= i; j--)
                a[j + 1] = a[j];
            a[i] = x;
            break;
        }
    }
    printf("�����У�\n");
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