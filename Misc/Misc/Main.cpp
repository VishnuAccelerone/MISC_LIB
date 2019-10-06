#include"List.h"
#include"Vector.h"
#include<iostream>



int main()
{
    Vector<int> a;
    a.push_back(10);
    a.push_back(34);
    std::cout << a.size() << "\n";
    for (int i = 0; i < a.size(); i++)
    {
        std::cout << a[i]<<"\n";
    }
    return 1;
}
