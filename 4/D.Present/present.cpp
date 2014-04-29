#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Point{
  public:
    int id,w,h;

    Point(int id, int w, int h){ this->id=id; this->w = w; this->h = h; }
    Point(){}
    bool operator <(const Point p) const{ return w == p.w ? h < p.h : w<p.w; }
    bool totalLess(const Point p) const{ return w<p.w && h<p.h; }
};

vector<Point> envelops;

int main(){
  int n,w,h;
  int endi;
  Point card;
  vector<int> costv,hisv;
  int cost,his;
  int left;

#ifndef ONLINE_JUDGE
  freopen("data","r",stdin);
#endif

  cin>>n>>card.w>>card.h;
  for(int i=1; i<=n; i++){
    cin>>w>>h;
    envelops.push_back(Point(i,w,h));
  }
  sort(envelops.begin(),envelops.end());

  for(int i=0;i<envelops.size();i++){
    card.totalLess(envelops[i]) ? cost = 1 : cost = 0;
    his = -1;
    if(cost>0)
      for(int j=0; j<i; j++){
        if( envelops[j].totalLess(envelops[i]) && costv[j]+1>cost ){
          cost = costv[j]+1;
          his = j;
        }
      }
    costv.push_back(cost);
    hisv.push_back(his);
  }

  endi = max_element(costv.begin(),costv.end())-costv.begin();
  cout<< costv[endi] << endl;

#ifndef ONLINE_JUDGE
  cout<<"costv: "<<endl;
  for(int i=0; i<costv.size(); i++){
    cout<<costv[i];
  }
  cout<<endl;

  cout<<"hisv: "<<endl;
  for(int i=0; i<hisv.size(); i++){
    cout<<hisv[i];
  }
  cout<<endl;

  cout<< "\tendi: " << endi <<endl;
#endif

  if( 0 != costv[endi] ){
    vector<int> answerv;
    answerv.push_back(envelops[endi].id);
    int pre = hisv[endi];
    while( -1 != pre ){
      answerv.push_back(envelops[pre].id);
      pre = hisv[pre];
    }
    for(int i=answerv.size()-1; i>=0; i--){
      cout<<answerv[i]<<" ";
    }
    cout<<endl;
  }

  return 0;
}
