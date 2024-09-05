#include <iostream>
#include <stdint.h>
#include <cstring>

#define MAX_ELEMENT 100

uint32_t returnFactorial(int K){
    int value = 1;

    for(int i=2; i<=K; i++){
        value = value*i;
    }

    return value;
}

void setElement(int a[], int N, int M, int i, int j, int value)
{
    if (i >= 0 && i < N && j >= 0 && j < M) {
        a[i*M+j] = value;
    }
}

void crossShell(int a[], int N, int M, int i, int j)
{
    setElement(a, N, M, i-1, j, 1);
    setElement(a, N, M, i-1, j+1, 1);
    setElement(a, N, M, i-1, j-1, 1);
    setElement(a, N, M, i, j, 1);
    setElement(a, N, M, i, j-1, 1);
    setElement(a, N, M, i, j+1, 1);
    setElement(a, N, M, i+1, j, 1);
    setElement(a, N, M, i+1, j+1, 1);
    setElement(a, N, M, i+1, j-1, 1);
}

void getBlack(int a[], int N, int M, int K, int &count){
    int preArray[MAX_ELEMENT];

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) 
        {
            if (a[i*M+j] != 1) 
            {
                if (K > 1) 
                {
                    memcpy(preArray, a, sizeof(int)*N*M);

                    crossShell(a,N,M,i,j);
                    
                    getBlack(a, N, M, K-1, count);

                    memcpy(a, preArray, sizeof(int)*N*M);
                } 
                else 
                {
                    count++;
                }
            }
        }
    }
}

int main() {
    int row = 0, column = 0, K = 0, count = 0, giai_thua = 1;
    int a[MAX_ELEMENT] = {0};

    std::cout << "Nhap K= ";
    std::cin >> K;

    std::cout << "Nhap row= ";
    std::cin >> row;

    std::cout << "Nhap column= ";
    std::cin >> column;

    getBlack(a, row, column, K, count);

    std::cout << "Count of satisfied cases: " << count/returnFactorial(K) << std::endl;

    return 0;
}
