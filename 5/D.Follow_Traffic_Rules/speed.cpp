#include<cstdio>
#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main(){
#ifndef ONLINE_JUDGE
  freopen("data","r",stdin);
#endif

  double a,v,d,l,w;
  double t[3],tw[2],tv,s[2];

  cout<<setprecision(5)<<std::fixed;

  cin>>a>>v>>l>>d>>w;
  w = w > v ? v : w;

  tw[0] = w/a;
  s[0] = a*tw[0]*tw[0]/2;
  if(s[0]>d){
    t[0] = sqrt(d*2/a);
  }else{
    tw[1] = ( sqrt((d-s[0])*a+w*w)-w )/a *2;
    t[0] = tw[0] + tw[1];
  }

  tv = (v-w)/a;
  s[1] = a*tv*tv/2+w*tv;
  if( s[1] > l-d ){
    t[1] = ( sqrt( w*w + 2*a*(l-d) ) - w )/a;
  }else{
    t[1] = tv + (l-d-s[1])/v;
  }

  t[2] = t[0] + t[1];

  cout<<t[2]<<endl;;

#ifndef ONLINE_JUDGE
  fclose(stdin);
#endif
  return 0;
}
