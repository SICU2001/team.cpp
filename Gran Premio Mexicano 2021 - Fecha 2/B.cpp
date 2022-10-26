#include <bits/stdc++.h>
using namespace std;
vector <int> pal;

int cr(int ac, int in, int si){
  if(in > (si-1)/2){
    pal.push_back(ac);
    return 1;
  }
  cr(ac, in+1, si);
  ac|=(1<<in);
  ac|= (1<<(si-1-in));
  cr(ac,in+1, si);
  return 1;
}

int main() {

  for(int i=1; i<=31; i++)cr(((1<<(i-1)) | 1), 1, i);
  sort(pal.begin(),pal.end());
  //for(int i = 0; i<10; i++)cout<<pal[i]<<endl;

  int q;
  cin>>q;
  while(q--){
    int a,b;
    cin>>a>>b;
    if(a>pal.back() || a>b || b< pal[0]){
      cout<<0<<endl;
    }
    else{
      int l1=0;
      int l2 = pal.size()-1;
      while(l1<l2){
        int m = (l1+l2)/2;
        if(pal[m]>=a)l2=m;
        else l1 = m+1;
      }
      int la = l1;
      //cout<<la<<endl;
      l1 = 0;
      l2 = pal.size()-1;
      while(l1<l2){
        int m = (l1+l2+1)/2;
        //cout<<pal[m]<<' '<<m<<' '<<b<<endl;
        if(pal[m]<=b)l1=m;
        else l2 = m-1;
      }
      int lb = l1;
      //cout<<lb<<endl;
      if(lb<la){
        cout<<0<<endl;
      }
      else cout<<lb-la+1<<endl;
    }
  }
  
  
  return 0;
}