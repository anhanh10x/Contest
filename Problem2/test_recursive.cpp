#include <iostream>

#define MAX_ELEMENT 50

void findFibArray(int a[], int value, int &arrayLength) {
    int preFib = 1;
    int currentFib = 2;
    int i = 0;
    while (currentFib <= value && i < MAX_ELEMENT) {
        a[i] = currentFib;
        currentFib = currentFib + preFib;
        preFib = a[i];
        i++;
    }
    arrayLength = i;
}

void process(int a[], int value, int index, int &count)
{
    int fib = a[index];
    
    if (value == 1) {
        count++;
        return;
    }
    
    if (index < 0) return;

    if (value % fib == 0) {
        process(a, value / fib, index, count);
    }
    process(a, value, index - 1, count);
}

int main() {
    int fibArray[MAX_ELEMENT] = {0};

    int value, arrayLength = 0, count = 0;
    std::cin >> value;

    findFibArray(fibArray, value, arrayLength);

    process(fibArray, value, arrayLength - 1, count);

    std::cout << "count= " << count << std::endl;
}
