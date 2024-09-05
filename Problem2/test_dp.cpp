#include <iostream>
#include <vector>

#define MAX_ELEMENT 50

void findFibArray(std::vector<int>& a, int value) {
    int preFib = 1;
    int currentFib = 2;
    while (currentFib <= value && a.size() < MAX_ELEMENT) {
        a.push_back(currentFib);
        currentFib = currentFib + preFib;
        preFib = a.back();
    }
}

int countWays(int value, const std::vector<int>& fibArray) {
    // Tạo mảng dp và khởi tạo dp[1] = 1
    std::vector<int> dp(value + 1, 0);
    dp[1] = 1;  // 1 có thể biểu diễn như chính nó

    for (int v = 2; v <= value; ++v) {
        for (int fib : fibArray) {
            if (v % fib == 0) {
                dp[v] += dp[v / fib];
            }
        }
    }

    return dp[value];
}

int main() {
    std::vector<int> fibArray;

    int value;
    std::cin >> value;

    findFibArray(fibArray, value);

    int count = countWays(value, fibArray);

    std::cout << "count= " << count << std::endl;

    return 0;
}
