#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>

using namespace std;

#define MAXS 100 
char s[MAXS];

int checkchar(char c){
  if(c>='0'&&c<='9'){
    return c-'0';
  }else if(c=='R'){
    return 10;
  }else if(c=='C'){
    return 11;
  }else if(c!='\0'){
    return 12;
  }else{
    return 13;
  }
}

string absMode(int x){
  string s = "";
  char temp;
  bool goon = true;
  while(goon){
    if(x<26)
      goon = false;
    temp = x%26+'A';
    s.insert(0,1,temp);
    x = x/26-1;
  }
  return s;
}

string convert(char s[]){
  int res,i;
  int c,r;
  string rs="";
  char cs[100];

  if(s[0]=='R'){
    i=1;
    c=r=0;
    rs="";
    while(checkchar(s[i])<10){
      r = checkchar(s[i])+r*10;
      rs += s[i];
      i++;
    }
    if(checkchar(s[i])==11 && i!=1){
      i++;
      while(checkchar(s[i])<10){
        c = checkchar(s[i])+c*10;
        i++;
      }
      if(checkchar(s[i])==13){
#ifdef DEBUG
        cout<<r<<"\t"<<c<<endl;
        cout<<absMode(c)<<"\t"<<rs<<endl;
#endif
        return absMode(c-1) + rs;
      }
    }
  }

  i=0;
  c=r=0;
  rs = "";
  while(checkchar(s[i])>9){
    c = s[i]-'A' + 1 + c*26;
    i++;
  }
  while(checkchar(s[i])<10){
    r = r*10 + checkchar(s[i]);
    rs += s[i];
    i++;
  }
  sprintf(cs,"%d",c);
#ifdef DEBUG
  cout<<c<<endl;
#endif
  return "R"+rs+"C"+cs; 
}

int main(){
  int n,i;

#if defined(DEBUG) || defined(TEST)
  freopen("data","r",stdin);
#endif

  cin>>n;
  while(n--){
    cin>>s;
    cout<<convert(s)<<endl;
  }

#if defined(TEST) || defined(DEBUG)
  fclose(stdin);
#endif

  return 0;
}
