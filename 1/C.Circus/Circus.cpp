#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>

using namespace std;

double p[3][2];
double l[3];
double angle[3];

double cosC(double a, double b, double c){
  return (a*a + b*b - c*c)/(2*a*b);
}

double getR(){
  double cosc,sinc;
  cosc = cosC(l[0],l[1],l[2]);
  sinc = sqrt(1-cosc*cosc);
#ifdef DEBUG
  cout<<"------getR:"<<endl;
  cout<<cosc<<"\t"<<sinc<<endl;
#endif
  return l[2]/sinc/2;
}

double gcdD(double x, double y){
  double small=y,large=x,temp;
  if(x<y){
    small = x;
    large = y;
  }
#ifdef DEBUG
  cout<<"----------gcdD:"<<endl;
  cout<<small<<"\t"<<large<<endl;
#endif
  while(small>0.01){
    temp = fmod(large,small);
    large = small;
    small = temp;
#ifdef DEBUG
  cout<<small<<"\t"<<large<<endl;
#endif
  }
  return large;
}

void p2l(){
  l[0] = ( p[0][0]-p[1][0] ) * ( p[0][0]-p[1][0] ) + ( p[0][1] - p[1][1] )*( p[0][1]-p[1][1] );
  l[1] = ( p[1][0]-p[2][0] ) * ( p[1][0]-p[2][0] ) + ( p[1][1] - p[2][1] )*( p[1][1]-p[2][1] );
  l[2] = ( p[0][0]-p[2][0] ) * ( p[0][0]-p[2][0] ) + ( p[0][1] - p[2][1] )*( p[0][1]-p[2][1] );

  for(int i=0;i<3;i++){
    l[i] = sqrt(l[i]);
  }
#ifdef DEBUG
  cout<<"l[0]: "<<l[0]<<endl<<"l[1]: "<<l[1]<<endl<<"l[2]: "<<l[2]<<endl;
#endif
}

double cal(){
  double a,b,r,n;

  r = getR();
#ifdef DEBUG
  cout<<"------------cal:"<<"r: "<<r<<endl;
#endif
  angle[0] = acos(cosC(r,r,l[0]));
  angle[1] = acos(cosC(r,r,l[1]));
  angle[2] = acos(cosC(r,r,l[2]));
#ifdef DEBUG
  cout<<"angle:"<<endl;
  cout<<angle[0]<<"\t"<<angle[1]<<"\t"<<angle[2]<<endl;
#endif
  a = gcdD(angle[0],angle[1]);
  a = gcdD(angle[2],a);
  a = gcdD(M_PI*2,a);
  n = 2*M_PI/a;
  b = (M_PI-a)/2;

#ifdef DEBUG
  cout<<"--------------"<<endl;
  cout<<"a: "<<a<<endl;
  cout<<n<<endl;
#endif

  return r*sin(b)*r*cos(b)*n;
}

int main(){

#if defined(TEST)|| defined(DEBUG)
  freopen("data","r",stdin);
#endif

  for(int i=0; i<3; i++){
    for(int j=0; j<2; j++){
      cin >> p[i][j];
    }
  }
  p2l();
  cout.setf(ios::fixed);
  cout<< setprecision(6) <<cal()<<endl;

#if defined(TEST) || defined(DEBUG)
  fclose(stdin);
#endif

  return 0;
}
