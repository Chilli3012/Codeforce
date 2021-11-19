#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int a[100005];
int sum=0;
int n;
bool Checker(int x)
{
	x=n-x;
	if(sum%x!=0)
  {
    return false;
  }
	const int val=sum/x;
	int res=0;
	for(int i=0;i<n;++i)
  {
		res+=a[i];
		if(res==val)
    {
			res=0;
		}
    else if(res>val)
      return false;
	}
	return res==0;
}
void solver()
{
	sum=0;
	for(int i=0;i<n;++i)
  {
		cin>>a[i];
		sum += a[i];
	}
	for(int i=0;i<n;++i)
  {
		if(Checker(i)){
			printf("%d\n",i);
			return;
		}
	}
	puts("-1");
}
int main()
{
	int tc;
  cin>>tc;
  while(tc--)
  {
    cin>>n;
		solver();
	}
	return 0;
}
