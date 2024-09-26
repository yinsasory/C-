#include<iostream>
#include<math.h>

class giaibai{
    private:
        int x,y,z;

    public:
        void input();
        void output();
        void loadingcation();
};


void giaibai::input(){
    std::cout<<"moi ban nhap so phong phu: ";
    std::cin>>x;
}
void giaibai::loadingcation(){
    for(int i=1;i<x;++i){
        if(x%i==0){
            y=y+i;
        }
    }
    if(y<x){
        z=z+1;
    }

}
void giaibai::output(){
    std::cout<<"so luong so phong phu la: "<<z;
}

int main(){
    giaibai q;
    q.input();
    q.loadingcation();
    q.output();
}