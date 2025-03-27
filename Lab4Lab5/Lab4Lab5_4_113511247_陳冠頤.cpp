#include <iostream>
#include <cmath>
using namespace std;
bool insideII(int,int,int,int);
bool insideI(int,int,int,int);
int main() {
    int r,a,x,y,county=0,bound;
    bool in;
    cin>>r>>a;
    if (r < 0 || r > 100 || a < 0 || a > 100)  
        return 0;
    if((double)a>sqrt(2)*r){
        cout<<"No square can fit!!"<<endl;
    }else{
    x=-(r/a)*a;
    y=0;
    in=insideII(x,y,r,a);
    while (in==false){
        x+=a;
        in=insideII(x,y,r,a);
    }
    bound=-x;
    while(x<=0){
        in=insideII(x,y,r,a);
        while(in){
            y+=a;
            ++county;
            in=insideII(x,y,r,a);
        }
        y-=a;
        --county;
        for(int i=0;i<county*2+1;++i){
            cout<<x<<", "<<y-i*a<<endl;
        }
    x+=a;
    }
    while(x>0&&x<=bound){
        in=insideI(x,y,r,a);
        while(in){
            y+=a;
            ++county;
            in=insideI(x,y,r,a);
        }
        y-=a;
        --county;
        for(int i=0;i<county*2+1;++i){
            cout<<x<<", "<<y-i*a<<endl;
        }
    x+=a;
    }
    }
}
bool insideII(int x,int y,int r,int a) {
    bool in;
    in=pow((x-(double)a/2),2)+pow((y+(double)a/2),2)<=pow(r,2);
    return in;
}
bool insideI(int x,int y,int r,int a) {
    bool in;
    in=pow((x+(double)a/2),2)+pow((y+(double)a/2),2)<=pow(r,2);
    return in;
}