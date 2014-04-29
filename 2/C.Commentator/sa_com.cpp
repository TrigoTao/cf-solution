#include<cstdio>
#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstdlib>
#include<ctime>

using namespace std;

struct Point{
  double a;
  double b;
  int r;
};

Point pt[3];
const int xdir[4] = {0,1,-1,0};
const int ydir[4] = {1,0,0,-1};
bool ability = false;
int base = 10000;

double calE(Point p){
  double l[3];
  double minl;
  double e = 0.0;
  int i;
  const int co = 1;

  for(i=0;i<3;i++){
    l[i] = pow(p.a - pt[i].a, 2) + pow(p.b - pt[i].b, 2);
    l[i] = l[i]/pow(pt[i].r, 2);
  }
  minl = fmin(l[0],l[1]);
  minl = fmin(minl,l[2]);

  for(i=0;i<3;i++){
    e += (l[i]-minl)*co;
  }
  if(e<0.001){
    e += minl;
    base = minl;
    ability = true;
  }else{
    e += base;
  }

  return e;
}

double move(Point *nextP, const Point p, double step){
  int j,dir;
  double e,nextE;
  Point stepP;

  dir  = rand()%4;
  step *= ((float) rand()) / (float) RAND_MAX;
  stepP.a = p.a + xdir[dir]*step;
  stepP.b = p.b + ydir[dir]*step;

  e = calE(stepP);
  *nextP = stepP;
  nextE = e;

  return nextE;
}

int main(){
  int i,j,k;
  double t=100,alpha=0.998,step;
  Point p,stepP;
  Point bestp;
  double bestE,e,oe;
  bool saFlag;
  int heatTime = 20;

#if defined(DEBUG)||defined(TEST)
  freopen("data","r",stdin);
  freopen("result","w",stdout);
#endif

  cout.setf(ios::fixed);
  srand(time(NULL));

  for(i=0;i<3;i++){
    cin>>pt[i].a>>pt[i].b>>pt[i].r;
  }
  bestp.a = p.a = ( pt[0].a + pt[1].a + pt[2].a )/3;
  bestp.b = p.b = ( pt[0].b + pt[1].b + pt[2].b )/3;
  bestE = calE(p);

#ifdef DEBUG
  cout<<"after initial"<<endl;
#endif

  while(heatTime>0){
    t = 100;
    while(t>0.000001){
      step = t*50;
      saFlag = true;
      oe = calE(p);
  
      e = move(&stepP, p, step);
#ifdef DEBUG
      cout<<"-------------------------"<<endl;
      cout<<e<<"\t"<<oe<<"\t"<<bestE<<endl;
      cout<< setprecision(5)<<stepP.a<<"\t"<<stepP.b<<"\t"<<p.a<<"\t"<<p.b<<endl;
      cout<< setprecision(6)<<"t:\t"<<t<<endl;
#endif
      if(e<bestE){
        bestp = p  = stepP;
        bestE = e;
        saFlag = false;
      }else{
        if(e<oe){
          p  = stepP;
          saFlag = false;
        }else{
          if( exp((oe-e)/t) > ((float) rand()) / (float) RAND_MAX ){//oe<=e
            oe = e;
            p = stepP;
          }
        }
      }
  
      if(saFlag){
        t *= alpha;
      }
    }
    heatTime --;
  }

  if(ability){
    cout<< setprecision(5) <<bestp.a<<" "<<bestp.b<<endl;
  }

  return 0;
}
