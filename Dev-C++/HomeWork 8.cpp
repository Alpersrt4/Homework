#include <iostream>
const int SIZE=7;
int find_min_top_triangle(int arr[SIZE][SIZE]){
    int min_element=arr[0][0];
    for(int i=0;i<SIZE;++i){
        for(int j=0;j<=i;++j){
            if(arr[i][j]<min_element){
                min_element=arr[i][j];
            }
        }
    }
    return min_element;
}
int find_min_down_triangle(int arr[SIZE][SIZE]){
    int min_element=arr[SIZE-1][0];
    for(int i=SIZE-1;i>=0;--i){
        for(int j=0;j<SIZE-i;++j){
            if(arr[i][j]<min_element){
                min_element=arr[i][j];
            }
        }
    }
    return min_element;
}
int find_min_left_triangle(int arr[SIZE][SIZE]){
    int min_element=arr[0][0];
    for(int i=0;i<SIZE;++i){
        for(int j=0;j<SIZE-i;++j){
            if(arr[j][i]<min_element){
                min_element=arr[j][i];
            }
        }
    }
    return min_element;
}
int find_min_right_triangle(int arr[SIZE][SIZE]){
    int min_element=arr[0][SIZE-1];
    for(int i=0;i<SIZE;++i){
        for(int j=SIZE-i-1;j<SIZE;++j){
            if(arr[j][i]<min_element){
                min_element=arr[j][i];
            }
        }
    }
    return min_element;
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
    int min_top=find_min_top_triangle(array_7x7);
    int min_down=find_min_down_triangle(array_7x7);
    int min_left=find_min_left_triangle(array_7x7);
    int min_right=find_min_right_triangle(array_7x7);
    std::cout<< "Minimum element in upper triangle: "<< min_top << std::endl;
    std::cout<< "Minimum element in lower triangle: "<< min_down << std::endl;
    std::cout<< "Minimum element in left triangle: "<< min_left << std::endl;
    std::cout<< "Minimum element in right triangle: "<< min_right << std::endl;
    return 0;
}
