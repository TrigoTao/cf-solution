#include<cstdio>
#include<iostream>

using namespace std;

#define MAXN 1000000


class HillCircle{
  private:
    int n;
    int hills[MAXN];
    int pn;

    int _searchOneSide(int begin, int (HillCircle::*move)(int) ){
      int iter = (this->*move)(begin);
      int maxh = hills[iter];
      int res = 0;
      
      //cout << "begin: " << begin << "\tnext:" << iter<<endl;
      
      if(n <= 2 || maxh > hills[begin])
        return 0;
    
      for(iter = (this->*move)(iter); hills[iter] <= hills[begin] && (this->*move)(iter) != begin; iter = (this->*move)(iter)){
        if(hills[iter]>=maxh){
          maxh = hills[iter];
          res++;
        }
      }
      if( (this->*move)(iter) != begin ){
        res++;
      }

      //cout << "res: " << res<<endl;
      return res;
    }

  public:
    void getInput(){
      cin >> n;
      for(int i=0; i<n; i++){
        cin>> hills[i];
      }
      pn = 0;
    }

    int nextHillP(int now){
      return now+1 == n ? 0 : now+1;
    }

    int preHillP(int now){
      return now-1 == -1 ? n-1 : now-1;
    }

    void run(){
      for(int i=0; i<n; i++){
        pn += _searchOneSide(i,&HillCircle::preHillP);
        pn += _searchOneSide(i,&HillCircle::nextHillP);
      }
      pn = pn/2 + n;
    }

    int output(){
      cout << pn <<endl;
    }

};


int main(){
#ifndef ONLINE_JUDGE
  freopen("data","r",stdin);
#endif

  HillCircle hc;

  hc.getInput();
  hc.run();
  hc.output();

#ifndef ONLINE_JUDGE
  fclose(stdin);
#endif

  return 0;
}
