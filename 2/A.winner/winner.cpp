#include<iostream>
#include<cstdio>
#include<map>
#include<list>
#include<algorithm>

using namespace std;

struct classcmp{
  bool operator() (int a,int b) const{
    return a>b;
  }
};

int main(){

#if defined(DEBUG)||defined(TEST)
  freopen("data","r",stdin);
#endif

  int n;
  map< string,int > scores;
  map< int,list<string>,classcmp > orderlist;
  list< pair<int,string> > record;
  string name;
  int score;

  cin >> n;

  while(n--){
    cin >> name >> score;
    
    if(scores.find(name) == scores.end()){
      scores[name] = score;
    }else{
      scores[name] += score;
    }

    orderlist[scores[name]].push_back(name);
    if(scores[name] != score){
      orderlist[scores[name]-score].remove(name);
    }

    record.push_back(make_pair(scores[name],name));
  }
#ifdef DEBUG
  for(map<string,int>::iterator it=scores.begin(); it!=scores.end();it++){
    cout << it->first << "->" << it->second<<endl;
  }
  cout<<"###"<<endl;
  for(map< int,list<string>,classcmp >::iterator i=orderlist.begin();i!=orderlist.end();i++){
    cout<<i->first<<"  "<<i->second.empty()<<endl;
  }
#endif
  map< int,list<string>,classcmp >::iterator it=orderlist.begin();
  while( it->second.empty() ){
    it++;
  }
#ifdef DEBUG
  cout<<"---------"<<endl;
  cout<<it->first<<endl;
#endif
  if(it->second.size()==1)
    cout<<it->second.front()<<endl;
  else{
    int target = it->first;
    list<string> cand = it->second;
    for(list< pair<int,string> >::iterator it=record.begin();it!=record.end();it++){
      if( it->first < target ){
        continue;
      }else{
        if(find(cand.begin(),cand.end(),it->second)==cand.end()){
          continue;
        }else{
          cout<<it->second<<endl;
          break;
        }
      }
    }
  }

  return 0;
}
