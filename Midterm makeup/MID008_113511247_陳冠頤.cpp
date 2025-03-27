//考試時因為在009b花太多時間而沒來的及想出來
#include <iostream>
using namespace std;
int main() 
{
  int h;
  cin>>h;
  if(h<=2||h%2==0)
  {
    cout<<"Incorrect Input(s)!"<<endl;
  }
  else
  {
    int m=(h+1)/2;
    int n_blank=m-1;
    for(int i=0;i<h;++i) 
    {
      if(i<m) //判斷是否為上半部
      {
        for(int i=0;i<n_blank;++i) cout<<" "; //印左邊的空格
        cout<<"*"; //第一排左邊

        if(i>0) //印第一排之後的左邊的菱形
        {
          for(int i=n_blank+1+1;i<=h-n_blank-1;++i) cout<<" ";
          cout<<"*";
        }

        for(int i=0;i<2*n_blank;++i) cout<<" "; //兩個菱形間的空格
        cout<<"*"; //第一排右邊

        if(i>0) //印第一排之後的右邊的菱形
        {
          for(int i=n_blank+1+1;i<=h-n_blank-1;++i) cout<<" ";
          cout<<"*";
        }

        for(int i=0;i<n_blank;++i) cout<<" "; //注意右邊的菱形有空格要印
        cout<<endl;
        if(i<m-1) n_blank--; //更新n_blank值
      }
      else
      {
        n_blank++; //避免變成負數出事

        for(int i=0;i<n_blank;++i) cout<<" ";
        cout<<"*";

        if(i<h-1)
        {
          for(int i=n_blank+1+1;i<=h-n_blank-1;++i) cout<<" ";
          cout<<"*";
        }

        for(int i=0;i<2*n_blank;++i) cout<<" ";
        cout<<"*";

        if(i<h-1)
        {
          for(int i=n_blank+1+1;i<=h-n_blank-1;++i) cout<<" ";
          cout<<"*";
        }
        
        for(int i=0;i<n_blank;++i) cout<<" ";
        cout<<endl;
      }
    }
  }        
}