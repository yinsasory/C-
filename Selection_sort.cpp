//Selection Sort
#include<bits/stdc++.h>
class selectionsort{
    private:
        int n;
        float array[1000000000];
        int temp,min;
    public:
        void input();
        void output();
        void algorithm();
};

void selectionsort::input(){
    std::cout<<"Mời bạn nhập số lượng phần tử: ";
    std::cin>>n;
    std::cout<<"Nhập các phần tử của mảng: \n";
    for(int i=0;i<n;++i){
        array[i]=rand();
    }
}
void selectionsort::algorithm(){
    for(int i=0;i<n-1;++i){
        min=i;
        for(int j=i+1;j<n;++j){
            if(array[min]>array[j]){
                min=j;
            }
        }
        if(min!=i){
            temp=array[i];
            array[i]=array[min];
            array[min]=temp;
        }
    }
}
void selectionsort::output(){
    for(int i=0;i<n;++i){
        std::cout<<"a["<<i+1<<"]: "<<array[i]<<"\n";
    }
}
int main(){
    selectionsort  a;
    a.input();
    a.algorithm();
    a.output();
}
