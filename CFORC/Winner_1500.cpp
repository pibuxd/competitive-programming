// author: Piotr "pibuxd" Bublik (https://github.com/pibuxd)
#include <iostream>
#include <map>
using namespace std;

int main(){
	map<string, int> mp;
	map<string, int> mp1;
	map<string, int>::iterator it;
	string name,names[1005];
	int n, score, scores[1005], max=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>name>>score;
		names[i] = name;
		scores[i] = score;
		mp[name] += score;
	}
	for(it=mp.begin();it!=mp.end();it++)
	{
		if(it->second>max)
		{
			max = it->second;
		}
	}
	
	for(int i=0;i<n;i++)
	{
		name = names[i];
		mp1[name] += scores[i];
		if(mp1[name]>=max && mp[name]==max)
		{
			cout<<name<<endl;
			break;
		}
	}	
	
	return 0;
}