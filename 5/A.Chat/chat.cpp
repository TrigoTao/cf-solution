#include<cstdio>
#include<iostream>

using namespace std;

int n=0;
int traffic = 0;

bool changen(const string &s){
  switch(s[0]){
    case '+':
      n++;
      return true;

    case '-':
      n--;
      return true;

    default:
      return false;
  }
}

void changeTra(string &s){
  int pos;

  pos = s.find(":");
  traffic += n * ( s.length() - pos -1 );
}

int main(){
#ifndef ONLINE_JUDGE
  freopen("data","r",stdin);
#endif

  string s;

  while( getline(cin, s) ){
    if( !changen(s) )
      changeTra(s);
  }
  cout<<traffic<<endl;

#ifndef ONLINE_JUDGE
  fclose(stdin);
#endif
}
