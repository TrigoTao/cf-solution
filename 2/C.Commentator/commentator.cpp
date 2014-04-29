#include<cstdio>
#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int p[3][2];
int r[3];

int main(){
  int i,j;
  int a[2],b[2],k[2],c[2];
  double xr,yr,xc,yc;
  double af,bf,cf;
  double deta,maxd,mind;
  double rs,x,y;

#if defined(DEBUG)||defined(TEST)
  freopen("data","r",stdin);
#endif

  for(i=0;i<3;i++){
    cin>>p[i][0]>>p[i][1]>>r[i];
  }

#ifdef DEBUG
  for(i=0;i<3;i++){
    cout<<p[i][0]<<"\t"<<p[i][1]<<"\t"<<r[i]<<endl;
  }
#endif

  a[0] = 2*(p[0][0]-p[1][0]);
  a[1] = 2*(p[1][0]-p[2][0]);
  b[0] = 2*(p[0][1]-p[1][1]);
  b[1] = 2*(p[1][1]-p[2][1]);
  k[0] = r[1]*r[1] - r[0]*r[0];
  k[1] = r[2]*r[2] - r[1]*r[1];
  c[0] = p[1][0]*p[1][0] - p[0][0]*p[0][0] + p[1][1]*p[1][1] - p[0][1]*p[0][1];
  c[1] = p[2][0]*p[2][0] - p[1][0]*p[1][0] + p[2][1]*p[2][1] - p[1][1]*p[1][1];
  c[0] = -c[0];
  c[1] = -c[1];

#ifdef DEBUG
  cout<<"a\tb\tk\tc\t"<<endl;
  for(i=0;i<2;i++){
    cout<<a[i]<<"\t"<<b[i]<<"\t"<<k[i]<<"\t"<<c[i]<<endl;
  }
#endif

  if(a[1]*b[0]-a[0]*b[1] == 0){
#ifdef DEBUG
    cout<<"no xr.."<<endl;
#endif
    return 0;
  }

  xr = (double)(k[1]*b[0]-k[0]*b[1])/(a[1]*b[0]-a[0]*b[1]);
  xc = (double)(c[1]*b[0]-c[0]*b[1])/(a[1]*b[0]-a[0]*b[1]);
  yr = (double)(k[1]*a[0]-k[0]*a[1])/(a[0]*b[1]-a[1]*b[0]);
  yc = (double)(c[1]*a[0]-c[0]*a[1])/(a[0]*b[1]-a[1]*b[0]);

#ifdef DEBUG
  cout<<"xr:\t"<<xr<<"\txc:\t"<<xc<<"\tyr:\t"<<yr<<"\tyc:\t"<<yc<<endl;
#endif

  af = xr*xr+yr*yr;
  bf = 2*xc*xr-2*p[1][0]*xr+2*yc*yr-2*p[1][1]*yr-r[1]*r[1];
  cf = xc*xc-2*p[1][0]*xc+p[1][0]*p[1][0]+yc*yc-2*p[1][1]*yc+p[1][1]*p[1][1];
  deta = bf*bf-4*af*cf;

#ifdef DEBUG
  cout<<"af:\t"<<af;
  cout<<"\tbf:\t"<<bf;
  cout<<"\tcf:\t"<<cf;
  cout<<"\tdeta:\t"<<deta<<endl;
#endif

  if(af==0){
    if( 0==bf && 0!=cf ){
#ifdef DEBUG
      cout<<"af=0 , bf=0 , cf!=0"<<endl;
#endif
      return 0;
    }
    if( bf*cf>0 ){
#ifdef DEBUG
      cout<<"bf*cf>0"<<endl;
#endif
      return 0;
    }
    x = xc;
    y = yc;
  }else if(deta<0)
    return 0;
  else{
    deta = sqrt(deta);
    maxd = deta-bf;
    mind = -bf-deta;
#ifdef DEBUG
    cout<<"maxd:\t"<<maxd<<"\tmind:\t"<<mind<<endl;
#endif
    if(mind<0)
      mind = maxd;
    if(maxd<0)
      return 0;
    else{
      rs = mind/2/af;
#ifdef DEBUG
      cout<<rs<<endl;
#endif
      x = xr*rs+xc;
      y = yr*rs+yc;
    }
  }
  cout.setf(ios::fixed);
  cout<< setprecision(5) <<x<<" "<<y<<endl;

  return 0;
}
