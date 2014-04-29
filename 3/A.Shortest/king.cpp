#include<cstdio>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

char s[3],t[3];
vector<string> path;

void greedy(){
  string step="";

  while(t[0]!=s[0] || t[1]!=s[1]){
    if(t[0]<s[0]){
      step += "L";
      s[0]--;
    }
    if(t[0]>s[0]){
      step += "R";
      s[0]++;
    }
    if(t[1]<s[1]){
      step += "D";
      s[1]--;
    }
    if(t[1]>s[1]){
      step += "U";
      s[1]++;
    }
    path.push_back(step);
    step = "";
  }
}

int main(){
#if defined(TEST)||defined(DEBUG) 
  freopen("data","r",stdin);
#endif
  cin>>s>>t;

  greedy();
  cout<<path.size()<<endl;
  for(vector<string>::iterator it = path.begin(); it != path.end(); it++){
    cout<<*it<<endl;
  }

  return 0;
}
