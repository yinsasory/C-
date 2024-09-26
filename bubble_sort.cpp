//bubble_sort
#include<iostream>

int main(){
    int n,array[50];
    std::cout<<"Moi ban nhap so phan tu cua mang: ";std::cin>>n;
    for(int i=0;i<n;++i){
        array[i]=rand();
    }
    //Bubblesort
    for(int i=0;i<n-1;++i){
        for(int j=n;j>0;--j){
            if(array[j]>array[j+1]){
                int swap=array[j];
                array[j]=array[j+1];
                array[j+1]=swap;
            }
        }
    }
    //In ra màn hình kết quả sắp xếp
    for(int i=0;i<n;++i){
        std::cout<<"a["<<i+1<<"]: "<<array[i]<<"\n";
    }
}