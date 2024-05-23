#include <iostream>
const int SIZE=7;
int sum_of_odd_elements(int arr[SIZE][SIZE]){
    int sum=0;
    for(int i=0;i<SIZE;++i){
        for(int j=0;j<SIZE;++j){
            if(arr[i][j]%2!=0){
                sum+=arr[i][j];
            }
        }
    }
    return sum;
}
long long product_of_even_elements(int arr[SIZE][SIZE]){
    long long product=1;
    for(int i=0;i<SIZE;++i){
        for(int j=0;j<SIZE;++j){
            if(arr[i][j]%2==0){
                product*=arr[i][j];
            }
        }
    }
    return product;
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
    int sum_odd=sum_of_odd_elements(array_7x7);
    long long product_even=product_of_even_elements(array_7x7);
    std::cout<< "Sum of single elements in the matrix: "<< sum_odd << std::endl;
    std::cout<< "Multiplication of even elements in the matrix: "<< product_even << std::endl;
    return 0;
}
