#include <iostream>

int main()
{
    int a, b;
    int n;
    
    std::cin>>n;
    
    for(int i=0; i<n; i++){
    
        std::cin>>a>>b;
    
        if((a+b)%2 == 0)
        {
            std::cout<<"Bob"<<std::endl;
        }
        else{
            std::cout<<"Alice"<<std::endl;
        }
    }
}