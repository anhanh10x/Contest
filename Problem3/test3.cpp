#include <iostream>

#define MAX_ELEMENT 1000

int findMax(int a[], int init, int des, int &index){
    int Max = a[init];
    index = init;
    for(int i=init; i<des-init; i++){
        if(a[i] > Max){
            index = i;
            Max = a[i];
        }
    }
    a[index] = 0;
    return Max;
}

void process(int del[], int kip[], int init, int des, int &count)
{
    if(des-init < 0) return;

    int index = 0;
    int Max = findMax(kip, init, des, index);
    bool Flag = false;

    for(int i=init; i<=des; i++)
    {
        if(Max == 0){
            if(del[i] >= 0){
                del[i] = -1;
                count++;
                return;
            }
        }
        else{
            if(del[i] > Max)
            {
                del[i] = -1;
                Flag = true;
            }
        }
    }

    if(Flag == true) count++;

    process(del, kip, init, index-1, count);
    process(del, kip, index+1, des, count);
}

int main()
{
    int del[MAX_ELEMENT] = {}, kip[MAX_ELEMENT] = {};
    int n, index = 0, count = 0;

    std::cin>>n;

    for(int i=0; i<n; i++)
    {
        char c;
        int data;
        std::cin>>c;
        std::cin>>data;
        
        if(c == 'y'){
            del[index] = data;
            index++;
        }
        else if(c == 'n'){
            kip[index] = data;
            index++;
        } else{}
    }

    process(del, kip, 0, index, count);

    std::cout<<count<<std::endl;
}