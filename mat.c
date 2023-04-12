#include <stdio.h>
#include <stdlib.h>                 
#include<time.h>        
void print_matrix(int** mat, int n);                //������
void add_matrix(int** A, int** B, int n);           //A+B
void subtraction_matrix(int** A, int** B, int n);   //A-B 
void transpose_matrix(int** A, int n);              //��ġ���T
void multiply_matrix(int** A, int** B, int n);      //AxB
void free_matrix(int** mat, int n);                 //�����޸� ����

int main() {
    
    int n=0;                                        
    int** A = NULL;                                 
    int** B = NULL;

    printf("[-----[������][2020041047]-----]\n");

    //���ũ�� �ޱ�
    printf("���簢����� ũ�� n (nXn) :");
    scanf("%d", &n);                             
  
    //��� A,B 1���� �迭 �Ҵ�
    A = (int**)malloc(n*sizeof(int*));
    B = (int**)malloc(n*sizeof(int*));


    //��� A,B 2���� �迭 �Ҵ�
    for (int i = 0; i < n; i++) 
    {
        A[i] = (int*)malloc(sizeof(int) * n);
        B[i] = (int*)malloc(sizeof(int) * n);

    }
    

    //��� ���� �ʱ�ȭ
    srand((unsigned int)time(NULL));
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n; k++)
        {
            A[i][k] = (rand() % 10);
            B[i][k] = (rand() % 10);

        }
    }
   
    //A�� B����� ����Ѵ�.
    printf("-��� A���\n");
    print_matrix(A,n);
    printf("-��� B���\n");
    print_matrix(B, n);

    //A+B
    printf("-A+B ��� ���\n");
    add_matrix(A, B, n);

    //A-B
    printf("-A-B ��� ���\n");
    subtraction_matrix(A, B, n);

    //A�� ��ġ��� T
    printf("-A�� ��ġ��� T���\n");
    transpose_matrix(A,n);

    //AxB
    printf("-AxB ��� ���\n");
    multiply_matrix(A,B,n);

    free_matrix(A,n);   //A��� �����Ҵ� ����          
    free_matrix(B,n);   //B��� �����Ҵ� ����
    
    return 0;

}

void print_matrix(int** mat, int n)                 //��� ��� �Լ�
{
    //��� ���
    for (int i = 0; i < n; i++) {           
        for (int k = 0; k < n; k++) {
            printf("%3d ", mat[i][k]);
        }
        printf("\n");
    }
    printf("\n");
}

void free_matrix(int** mat, int n)                  //�����޸� ���� �Լ�
{
    for (int i = 0; i < n; i++) {
        free(mat[i]);
    }
    free(mat);
}

void add_matrix(int** A, int** B, int n)            //A+B �����Լ�
{
    int** add=NULL;

    //add��� �޸��Ҵ�
    add = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
    {
        add[i] = (int*)malloc(sizeof(int) * n);
    }

    //����� ���� 
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n; k++)
        {
            add[i][k] = A[i][k] + B[i][k];
        }
    }
    //��� ���
    print_matrix(add, n);
    //add �����޸� ����
    free_matrix(add, n);
}

void subtraction_matrix(int** A, int** B, int n)    //A-B �����Լ�
{
    int** sub = NULL;

    //sub��� �޸��Ҵ�
    sub = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
    {
        sub[i] = (int*)malloc(sizeof(int) * n);
    }

    //����� ����
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n; k++)
        {
            sub[i][k] = A[i][k] - B[i][k];
        }
    }

    //��� ���
    print_matrix(sub, n);
    //sub �����޸� ����
    free_matrix(sub, n);
}

void transpose_matrix(int** A, int n)               //��ġ���T ���� �Լ�
{
    int** tra = NULL;

    //tra��� �޸��Ҵ�
    tra = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
    {
        tra[i] = (int*)malloc(sizeof(int) * n);
    }

    //��ġ ��� ���� 
    for (int i = 0; i < n; i++)
        for (int k = 0; k < n; k++) {
            {
                tra[k][i] = A[i][k];
            }
        }

    //��� ���
    print_matrix(tra, n);
    //tra �����޸� ����
    free_matrix(tra, n);
}

void multiply_matrix(int** A, int** B, int n)   //AxB ���� �Լ�
{

    int** mul = NULL;

    //mul��� �޸��Ҵ�
    mul = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
    {
        mul[i] = (int*)calloc(n,sizeof(int));
    }

    //��İ� ����
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            for (int r = 0; r < n; r++) {
                mul[i][j] += A[i][r] * B[r][j];
            }
        }
    }
    
    //��� ���
    print_matrix(mul, n);
    //mul �����޸� ����
    free_matrix(mul, n);

}