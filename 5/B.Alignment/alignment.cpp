#include<cstdio>
#include<iostream>
#include<queue>

using namespace std;

int main(){
#ifndef ONLINE_JUDGE
  freopen("data","r",stdin);
#endif

  queue<string> text;
  string s;
  int maxl = 0 ,i;

  while(getline(cin,s)){
    if( maxl < s.length() )
      maxl = s.length();
    text.push(s);
  }

  for(i=0; i<maxl+2; i++){
    cout<<"*";
  }
  cout<<"\n";
  while(!text.empty()){
    s = text.front();
    cout<<"*";
    for( i=0 ; i < ( maxl - s.length() )/2 ; i++ ){
      cout<<" ";
    }
    cout<<s;
    for( i=0 ; i < ( maxl - s.length() + 1 )/2 ; i++ ){
      cout<<" ";
    }
    cout<<"*\n";
    text.pop();
  }
  for(i=0; i<maxl+2; i++){
    cout<<"*";
  }
  cout<<endl;
#ifndef ONLINE_JUDGE
  fclose(stdin);
#endif
  return 0;
}
