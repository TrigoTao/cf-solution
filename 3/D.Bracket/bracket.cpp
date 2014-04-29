#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<algorithm>
#include<queue>

using namespace std;

class Cost{
  public:
    int l;
    int r;
    int id;

    Cost(int id, int l, int r){ this->id = id; this->l=l; this->r=r; }
    Cost(){ l=-1000; r=-1000; };

    bool operator <(const Cost c) const{
      return this->r - this->l < c.r-c.l;
    }
};

string s;
long long res_c=0;
priority_queue<Cost> costs;

int deal(){
  int l,r,i;
  int ln,rn;
  Cost tmp;

  res_c = 0;
  for(i=0; i<s.size(); i++){
    switch(s[i]){
      case '(':
        ln++;
        break;

      case ')':
        ln--;
        break;

      case '?':
        cin>>l>>r;
        costs.push( Cost(i,l,r) );
        s[i] = ')';
        res_c += r;
        ln--;
        break;
    }
    if(ln<0){
      if(costs.empty())
        break;
      else{
        tmp = costs.top();
        costs.pop();

        s[tmp.id] = '(';
        res_c = res_c + tmp.l - tmp.r;
        ln += 2;
      }
    }
  }
  if(ln == 0){
    cout<< res_c <<endl;
    cout<< s << endl;
  }else
    cout<<"-1";

  return 0;
}

int main(){
  int n;

#ifdef DEBUG
  freopen("data","r",stdin);
#endif

  cin>>s;
  deal();

  return 0;
}
