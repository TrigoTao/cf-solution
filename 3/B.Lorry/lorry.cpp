#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Waterborne{
  public:
    int id;
    int p;
    int type;
    Waterborne(int id ,int p, int type){this->id=id; this->p=p; this->type=type;}
    bool operator<(const Waterborne &w) const { return this->p<w.p; }
};

vector<Waterborne> ka,ca,res;

void opt(vector<Waterborne> &res, vector<Waterborne> &candi){
  int replacen = 0;
  while(candi.size()>=2){
    if( res[replacen].type == 2 && (candi.end()-2)->p + (candi.end()-1)->p > res[replacen].p ){
      res.push_back(candi.back());
      candi.pop_back();
      res.push_back(candi.back());
      candi.pop_back();
      replacen++;
    }else
      break;
  }
  res.erase(res.begin(),res.begin()+replacen);

  return ;
}

void answer(){
  int c=0;

  for(vector<Waterborne>::iterator it=res.begin(); it != res.end(); it++){
    c += it->p;
  }
  cout<<c<<endl;
  for(vector<Waterborne>::iterator it=res.begin(); it != res.end(); it++){
    cout<<it->id<<" ";
  }
  cout<<endl;

  return ;
}

int main(){
  int n,v;
  int t,p;
  int leftspace;
#ifdef DEBUG
  freopen("data","r",stdin);
  cout<<"---after freopen"<<endl;
#endif

  cin>>n>>v;
  for(int i=0; i<n; i++){
    cin>>t>>p;
    switch(t){
      case 1:
        ka.push_back(Waterborne(i+1,p,1));
        break;

      case 2:
        ca.push_back(Waterborne(i+1,p,2));
        break;
    }
  }

#ifdef DEBUG
  cout<<"-----after ini"<<endl;
#endif

  sort(ka.begin(),ka.end());
  sort(ca.begin(),ca.end());

#ifdef DEBUG
  cout<<"------after sort"<<endl;
#endif

  if(v>ca.size()*2){
    res.insert(res.begin(),ca.begin(),ca.end());

    leftspace = v - ca.size()*2;
    if(leftspace > ka.size()){
      res.insert(res.begin(),ka.begin(),ka.end());
    }else{
      res.insert(res.end(),ka.end()-leftspace,ka.end());
      ka.erase(ka.end()-leftspace,ka.end());
      opt(res,ka);
    }
  }else{
    res.insert(res.begin(),ca.end()-v/2,ca.end());
    if(ka.size()>0){
      res.insert(res.end(),ka.end()-v%2,ka.end());
      ka.erase(ka.end()-v%2,ka.end());
    }
    opt(res,ka);
  }

#ifdef DEBUG
  cout<<"------------after opt"<<endl;
#endif

  answer();

  return 0;
}
