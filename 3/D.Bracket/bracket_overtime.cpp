#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<algorithm>

using namespace std;

class Cost{
  public:
    int l;
    int r;
    int id;

    Cost(int id, int l, int r){ this->id = id; this->l=l; this->r=r; }
    Cost(){ l=-1000; r=-1000; };

    bool operator <(const Cost c) const{
      return abs(this->r - this->l) < abs(c.r-c.l);
    }
};

string s;
long long res_c=0;
vector<Cost> costs;
int fq,lq;


bool isAble(int pos, char ch){
  int t1,t2,i;
  int que=0,ln=0,rn=0;

  if('(' == ch){
    for(i=pos-1; i>=0; i--){
      if(s[i] == '(') {que>0 ? que-- : ln++;}
      else que++;
    }
    for(i=pos+1; i<s.size(); i++){
      if(s[i] == '(') {rn--;}
      else rn++;
    }
    if(rn>ln)
      return true;

  }else{
    for(i=0; i<pos; i++){
      if(s[i] == ')') {ln--;}
      else  {ln++;}
    }
    for(i=pos+1; i<s.size(); i++){
      if(s[i] == ')') {que>0 ? que-- : rn++;}
      else que++;
    }
    if(ln>rn)
      return true;
  }

  return false;
}

int choose(Cost c){
  if( c.l < c.r ){
    if( isAble(c.id,'(') )
      return -1;
    else
      return 1;
  }else{
    if( isAble(c.id,')') )
      return 1;
    else
      return -1;
  }

  return 0;
}

void insertNoChoice(){
  while('?' != s[fq] && fq<s.size()-1)
    fq ++;
  if('?' == s[fq] && false == isAble(fq,')')){
    s[fq] = '(';
    insertNoChoice();
  }
  while('?' != s[lq] && lq>0)
    lq --;
  if('?' == s[lq] && false == isAble(lq,'(')){
    s[lq] = ')';
    insertNoChoice();
  }
}

void deal(){
  Cost c;
  while(costs.size()>0){
    c = costs.back();
    if( -1 == choose(c) ){
      s[c.id] = '(';
      res_c += c.l;
    }else{
      s[c.id] = ')';
      res_c += c.r;
    }
    if(c.id == fq || c.id == lq)
      insertNoChoice();
    costs.pop_back();
  }
  return ;
}

int getInfo(){
  int l,r,i;

  for(i=0; i<s.size(); i++){
    if('?' == s[i]){
      cin>>l>>r;
      costs.push_back( Cost(i,l,r) );
    }
  }

  fq = costs.front().id;
  lq = costs.back().id;
  insertNoChoice();
#ifdef DEBUG
  cout<<s<<endl;
#endif
  sort(costs.begin(),costs.end());

  return 0;
}

bool judge(){
  int i,more=0;

  for(i=0;i<s.size();i++){
    if(s[i]=='(')
      more++;
    else
      more--;

    if(more<0)
      return false;
  }
  if(more == 0)
    return true;
  else
    return false;
}

int main(){
  int n;

#ifdef DEBUG
  freopen("data","r",stdin);
#endif

  cin>>s;

  getInfo();
  deal();

  if(judge()){
    cout<<res_c<<endl;
    cout<<s<<endl;
  }else{
    cout<<"-1"<<endl;
    cout<<s<<endl;
  }

  return 0;
}
