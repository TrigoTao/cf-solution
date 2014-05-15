#include<cstdio>
#include<iostream>

using namespace std;

int findLong(const string &s, int begin){
  int left=0;

  while(left>-1 && begin<s.size()){
    if('(' == s[begin])
      left++;
    else
      left--;

    begin++;
  }

  //return next begin
  if(begin == s.size())
    if(left == 0)
      return begin;
    else
      return begin+1;
  else //left == -1
    return begin-1;
}

int main(){
#ifndef ONLINE_JUDGE
  freopen("data","r",stdin);
#endif

  string s;
  int maxl,len;
  int begin=0,next=0;
  int n=0;

  cin>>s;

  while(begin<s.size()){
#ifndef ONLINE_JUDGE
    cout<<begin<<endl;
#endif
    next = findLong(s,begin);

    if( next == s.size()+1 )
      begin = next;
    else if(next == begin)
      begin++;
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
