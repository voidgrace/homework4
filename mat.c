#include <stdio.h>
#include <stdlib.h>                 
#include<time.h>        
void print_matrix(int** mat, int n);                //행렬출력
void add_matrix(int** A, int** B, int n);           //A+B
void subtraction_matrix(int** A, int** B, int n);   //A-B 
void transpose_matrix(int** A, int n);              //전치행렬T
void multiply_matrix(int** A, int** B, int n);      //AxB
void free_matrix(int** mat, int n);                 //동적메모리 해제

int main() {
    
    int n=0;                                        
    int** A = NULL;                                 
    int** B = NULL;

    printf("[-----[강은혜][2020041047]-----]\n");

    //행렬크기 받기
    printf("정사각행렬의 크기 n (nXn) :");
    scanf("%d", &n);                             
  
    //행렬 A,B 1차원 배열 할당
    A = (int**)malloc(n*sizeof(int*));
    B = (int**)malloc(n*sizeof(int*));


    //행렬 A,B 2차원 배열 할당
    for (int i = 0; i < n; i++) 
    {
        A[i] = (int*)malloc(sizeof(int) * n);
        B[i] = (int*)malloc(sizeof(int) * n);

    }
    

    //행렬 난수 초기화
    srand((unsigned int)time(NULL));
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n; k++)
        {
            A[i][k] = (rand() % 10);
            B[i][k] = (rand() % 10);

        }
    }
   
    //A와 B행렬을 출력한다.
    printf("-행렬 A출력\n");
    print_matrix(A,n);
    printf("-행렬 B출력\n");
    print_matrix(B, n);

    //A+B
    printf("-A+B 결과 출력\n");
    add_matrix(A, B, n);

    //A-B
    printf("-A-B 결과 출력\n");
    subtraction_matrix(A, B, n);

    //A의 전치행렬 T
    printf("-A의 전치행렬 T출력\n");
    transpose_matrix(A,n);

    //AxB
    printf("-AxB 결과 출력\n");
    multiply_matrix(A,B,n);

    free_matrix(A,n);   //A행렬 동적할당 해제          
    free_matrix(B,n);   //B행렬 동적할당 해제
    
    return 0;

}

void print_matrix(int** mat, int n)                 //행렬 출력 함수
{
    //행렬 출력
    for (int i = 0; i < n; i++) {           
        for (int k = 0; k < n; k++) {
            printf("%3d ", mat[i][k]);
        }
        printf("\n");
    }
    printf("\n");
}

void free_matrix(int** mat, int n)                  //동적메모리 해제 함수
{
    for (int i = 0; i < n; i++) {
        free(mat[i]);
    }
    free(mat);
}

void add_matrix(int** A, int** B, int n)            //A+B 연산함수
{
    int** add=NULL;

    //add행렬 메모리할당
    add = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
    {
        add[i] = (int*)malloc(sizeof(int) * n);
    }

    //행렬합 연산 
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n; k++)
        {
            add[i][k] = A[i][k] + B[i][k];
        }
    }
    //행렬 출력
    print_matrix(add, n);
    //add 동적메모리 해제
    free_matrix(add, n);
}

void subtraction_matrix(int** A, int** B, int n)    //A-B 연산함수
{
    int** sub = NULL;

    //sub행렬 메모리할당
    sub = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
    {
        sub[i] = (int*)malloc(sizeof(int) * n);
    }

    //행렬차 연산
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n; k++)
        {
            sub[i][k] = A[i][k] - B[i][k];
        }
    }

    //행렬 출력
    print_matrix(sub, n);
    //sub 동적메모리 해제
    free_matrix(sub, n);
}

void transpose_matrix(int** A, int n)               //전치행렬T 연산 함수
{
    int** tra = NULL;

    //tra행렬 메모리할당
    tra = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
    {
        tra[i] = (int*)malloc(sizeof(int) * n);
    }

    //전치 행렬 연산 
    for (int i = 0; i < n; i++)
        for (int k = 0; k < n; k++) {
            {
                tra[k][i] = A[i][k];
            }
        }

    //행렬 출력
    print_matrix(tra, n);
    //tra 동적메모리 해제
    free_matrix(tra, n);
}

void multiply_matrix(int** A, int** B, int n)   //AxB 연산 함수
{

    int** mul = NULL;

    //mul행렬 메모리할당
    mul = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
    {
        mul[i] = (int*)calloc(n,sizeof(int));
    }

    //행렬곱 연산
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            for (int r = 0; r < n; r++) {
                mul[i][j] += A[i][r] * B[r][j];
            }
        }
    }
    
    //행렬 출력
    print_matrix(mul, n);
    //mul 동적메모리 해제
    free_matrix(mul, n);

}