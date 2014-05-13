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
  int alt[2] = {0,1};

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
    for( i=0 ; i < ( maxl - s.length() + alt[0] )/2 ; i++ ){
      cout<<" ";
    }
    cout<<s;
    for( i=0 ; i < ( maxl - s.length() + alt[1] )/2 ; i++ ){
      cout<<" ";
    }
    cout<<"*\n";
    text.pop();
    if( 0 != (maxl-s.length())%2 ){
      alt[0] = !alt[0];
      alt[1] = !alt[1];
    }
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
