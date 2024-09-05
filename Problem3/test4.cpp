#include <iostream>
#include <chrono>  // for time measurement

#define MAX_ELEMENT 100

int main()
{
    int a[MAX_ELEMENT] = {};
    int n, m;
    int single_point;
    std::cin >> n >> m;

    single_point = n;

    for(int i = 0; i < m; i++){
        int m, n;
        std::cin >> m >> n;

        a[m]++;
        a[n]++;
        if(a[m] == 2) single_point--;
        if(a[n] == 2) single_point--;
    }
    // Start measuring time
    auto start = std::chrono::high_resolution_clock::now();    
    if(single_point % 2 == 0)
        std::cout << (single_point) / 2 << std::endl;
    else{
        std::cout << (single_point + 1) / 2 << std::endl;
    }

    // End measuring time
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Execution time: " << elapsed.count() << " seconds" << std::endl;

    return 0;
}
