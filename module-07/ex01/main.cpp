#include "iter.hpp"

int main()
{
    int arr[8] = {1,2,3,4,5,6,7,8};
    char space[2] = " ";
    char arr2[8] = "alberto";
    iter(arr, 8, print);
    iter(space, 1, print);
    iter(arr2, 7, print);
    return 0;
}

