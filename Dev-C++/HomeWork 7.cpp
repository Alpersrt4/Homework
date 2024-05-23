#include <iostream>
const int SIZE=7;
int sum_under_diagonal1(int arr[SIZE][SIZE]){
    int sum=0;
    for(int i=1;i<SIZE;++i){
        for(int j=0;j<i;++j){
            sum+=arr[i][j];
        }
    }
    return sum;
}
int sum_excluding_diagonal1(int arr[SIZE][SIZE]){
    int sum=0;
    for(int i=1;i<SIZE;++i){
        for(int j=0;j<i-1;++j){
            sum+=arr[i][j];
        }
    }
    return sum;
}
int main(){
    int array_7x7[SIZE][SIZE]={
        {1,2,3,4,5,6,7},
        {8,9,10,11,12,13,14},
        {15,16,17,18,19,20,21},
        {22,23,24,25,26,27,28},
        {29,30,31,32,33,34,35},
        {36,37,38,39,40,41,42},
        {43,44,45,46,47,48,49}
    };
    int sum_including=sum_under_diagonal1(array_7x7);
    int sum_excluding=sum_excluding_diagonal1(array_7x7);
    std::cout<< "Sum of items under Diagonal1 (including Diagonal1): "<< sum_including << std::endl;
    std::cout<< "Sum of items under Diagonal1 (excluding Diagonal1): "<< sum_excluding << std::endl;
    return 0;
}

