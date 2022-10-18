#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct typeArr
{
    int *arr;
    int size;
} tyAr;

void tang(tyAr *value){
    int temp = 0;
    for (int i = 0; i < value->size; i++)
    {
        for (int j = i + 1; j < value->size; j++)
        {
            if (value->arr[i] > value->arr[j])
            {       
                temp = value->arr[i];
                value->arr[i] = value->arr[j];
                value->arr[j] = temp;
            }
        }
    }
}

void giam(tyAr *value){
    int temp = 0;
    for (int i = 0; i < value->size; i++)
    {
        for (int j = i + 1; j < value->size; j++)
        {
            if (value->arr[i] < value->arr[j])
            {       
                temp = value->arr[i];
                value->arr[i] = value->arr[j];
                value->arr[j] = temp;
            }
        }
    }
}

int max(tyAr *value){
    int max = value->arr[0];
    for (int i = 1; i < value->size; i++)
    {
        if (max < value->arr[i])
        {
            max = value->arr[i];
        }
    }
    printf("MAX = %d\n", max);
    //return max;
}

struct typeArr *nhap(){
    static tyAr a; 
    printf("Nhap so phan tu trong mang: ");
    scanf("%d", &a.size);
    
    a.arr = (int*)malloc(a.size*sizeof(int));
    for (int i = 0; i < a.size; i++)
    {
        printf("Nhap phan tu arr[%d]: ",i);
        scanf("%d",(a.arr+i));
    }    
    return &a;
}

void thong_tin()
{
    printf("\n");
    printf("****************************\n");
    printf("* 1. Sap xep mang tang     *\n");
    printf("* 2. Sap xep mang giam     *\n");
    printf("* 3. Tim gia tri lon nhat  *\n");
    printf("* 4. Thoat                 *\n");
    printf("****************************\n");
}

int main()
{
    tyAr *test;
    test = nhap();
    printf("Tong so phan tu: %d\n",test->size);
    printf("Mang da nhap la: ");
    for (int i = 0; i < test->size; i++)
    {
        printf("%d  ",*(test->arr + i));
    }

    thong_tin();
    int option;
    printf("\nNhap che do: ");
    scanf("%d",&option);
    
    switch (option)
    {
        case 1:
            tang(test);
            break;
        case 2:
            giam(test);
            break;
        case 3:
            max(test);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("khong hop le!\n");
            break;
    }
    
    printf("Mang da xu ly: ");
    for (int i = 0; i < test->size; i++)
    {
            printf("%d  ",*(test->arr + i));
    }
    
    return 0;
}
