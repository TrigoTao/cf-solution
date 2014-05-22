#include<cstdio>
#include<iostream>

using namespace std;

#define MAXN 1000000


class HillCircle{
  private:
    int n;
    int hills[MAXN];
    int pn;

    int _searchOneSide(int begin, int &end, int (HillCircle::*move)(int) ){
      int iter = (this->*move)(begin);
      int maxh = hills[iter], maxp = iter;
      int res = 0;
      
      //cout << "begin: " << begin << "\tnext:" << iter<<endl;
      
      if(iter == end || maxh > hills[begin]){
        end = maxp;
        return 0;
      }
    
      for(iter = (this->*move)(iter); hills[iter] <= hills[begin] && iter != end; iter = (this->*move)(iter)){
        if(hills[iter]>=maxh){
          maxh = hills[iter];
          maxp = iter;
          res++;
        }
      }
      if( iter != end ){
        res++;
        end = iter;
      }else{
        end = maxp;
      }

      //cout << "res: " << res << "\tnew end: " << end <<endl;
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
      int tmp;
      for(int i=0; i<n; i++){
        tmp = nextHillP(i);
        pn += _searchOneSide(i,tmp,&HillCircle::preHillP);
        pn += _searchOneSide(i,tmp,&HillCircle::nextHillP);
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
