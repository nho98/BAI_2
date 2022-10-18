/*
    
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h> 

#define MAX 50

void nhap_mang(int mang[], int n)
{
    for (int i=0; i<n; i++)
    {
        printf("Nhap phan tu thu %d: ", i+1);
        scanf("%d", &mang[i]);
    }
}

void sx_tang(int mang[], int n)
{
    int tmp;
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(mang[i] > mang[j])
            {
                tmp = mang[i];
                mang[i] = mang[j];
                mang[j] = tmp;
            }
        }
    }
}

void sx_giam(int mang[], int n)
{
    int tmp;
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(mang[i] < mang[j])
            {
                tmp = mang[i];
                mang[i] = mang[j];
                mang[j] = tmp;
            }
        }
    }
}

void xuat_mang(int mang[], int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%4d", mang[i]);
    }
    printf("\n");
}

void tim_max(int mang[], int n)
{
    int max = mang[0];
    for(int i=1; i<n; i++)
    {
        if(mang[i]>max)
            max = mang[i];
    }
    printf("MAX = %d\n", max);
}

void thong_tin()
{
    printf("****************************\n");
    printf("* 1. Sap xep mang tang     *\n");
    printf("* 2. Sap xep mang giam     *\n");
    printf("* 3. Tim gia tri lon nhat  *\n");
    printf("* 4. Thoat                 *\n");
    printf("****************************\n");
}

int main()
{
    int mang[MAX];
    int n;
    int a;
    printf("Nhap n (1<n<%d): ", MAX);
    do
    {
        scanf("%d", &n);
        if((n<2)|(n>MAX))
        {
            printf("Nhap lai: ");
        }
    }
    while((n<2)|(n>MAX));

    nhap_mang(mang, n);
    thong_tin();

    printf("Lua chon: ");
    scanf("%d", &a);

    switch(a)
    {
        case 1:
            sx_tang(mang, n);
            break;
        case 2:
            sx_giam(mang, n);
            break;
        case 3:
            tim_max(mang, n);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("khong hop le!\n");
            break;
    }
    
    printf("Ket qua lua chon %d la:\n", a);
    xuat_mang(mang, n);
}