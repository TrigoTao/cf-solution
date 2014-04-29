#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

class DayTime{
  public:
    int minT,maxT;

    DayTime(int mi, int ma){
      this->minT = mi;  this->maxT = ma;
    }
};

vector<DayTime> days;
vector<int> schedule;
int minsum=0, maxsum=0;

int main(){
  int d, sumTime;
  int i;
  int mi,ma;

#ifdef DEBUG
  freopen("data","r",stdin);
#endif

  cin>>d>>sumTime;
  for(i=0;i<d;i++){
    cin>>mi>>ma;
    days.push_back(DayTime(mi,ma));
    schedule.push_back(mi);
    minsum += mi;
    maxsum += ma;
  }

  if(minsum>sumTime || maxsum<sumTime)
    cout<<"NO"<<endl;
  else{
    cout<<"YES"<<endl;
    for(i=0;i<days.size();i++){
      if(sumTime-minsum > days[i].maxT - days[i].minT){
        minsum += days[i].maxT - days[i].minT;
        schedule[i] = days[i].maxT;
      }else{
        schedule[i] += sumTime - minsum;
        minsum = sumTime;
      }
      cout<<schedule[i]<<" ";
    }
    cout<<endl;
  }
}
