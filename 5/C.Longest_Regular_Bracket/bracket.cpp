#include<cstdio>
#include<iostream>

using namespace std;

int findLong(const string &s, int begin){
  int left=0;
  int next = begin+1;

  while(left>-1 && begin<s.size()){
    if('(' == s[begin])
      left++;
    else
      left--;

    if(left == 0)
      next = begin+1;

    begin++;
  }

  return next;
}

int main(){
#ifndef ONLINE_JUDGE
  freopen("data","r",stdin);
#endif

  string s;
  int maxl=0,len=0;
  int begin=0,next=0;
  int n=0;

  cin>>s;

  while(begin<s.size()){
    next = findLong(s,begin);

#ifndef ONLINE_JUDGE
    cout<<begin<<endl;
#endif

    if(next == begin+1)
      begin = next;
    else{
      len = next-begin;
      if(len>maxl){
        maxl = len;
        n=1;
      }else if(len==maxl)
        n++;

      begin = next;
    }
  }

  if(0==n)
    n=1;
  cout<<maxl<<" "<<n<<endl;
#ifndef ONLINE_JUDGE
  fclose(stdin);
#endif

  return 0;
}
