#include <iostream>
#include <chrono>  // for time measurement

#define N_MAX 300
#define M_MAX 5000

int main()
{
    int graph[N_MAX][N_MAX] = {};
    int n, m, k;
    std::cin >> n >> m >> k;

    for(int count = 0; count < m; count++){
        int i, j, w;
        std::cin >> i >> j >> w;
        
        if(i < N_MAX && j < N_MAX){
            graph[i-1][j-1] = w;
            graph[j-1][i-1] = w;
        }
    }

    int idx_vip[N_MAX] = {};

    for(int count = 0; count < k; count++){
        std::cin >> idx_vip[count];
    }

    int idx_nv[N_MAX] = {};

    for(int count = 0; count < k; count++){
        std::cin >> idx_nv[count];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            std::cout << graph[i][j] << " ";
        }
        std::cout << "\n";
    }

    for(int count = 0; count < k; count++){
        std::cout << vip_idx[count] << " ";
    }

    return 0;
}
