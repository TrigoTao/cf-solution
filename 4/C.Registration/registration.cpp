#include<cstdio>
#include<iostream>
#include<map>
#include<string>
#include<set>
#include<cstdlib>
#include<ctime>

using namespace std;

int main(){
  map<string,int> users;
  int n;
  string name;
  int count;
  char randc;

#ifndef ONLINE_JUDGE
  freopen("data","r",stdin);
#endif

  cin>>n;
  while(n-->0){
    cin >> name;
    if( users.end() == users.find(name) ){
      users.insert(pair<string,int>(name,0));
      cout<<"OK"<<endl;
    }else{
      map<string,int>::iterator it = users.find(name);
      it->second ++;
      cout<<name<<it->second<<endl;
    }
  }

  return 0;
}
