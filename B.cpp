#include<bits/stdc++.h>
using namespace std; 


int root=0,nodes=0;

// This is used to create new node in trie data structure
int new_node()
{
    nodes++;
    return nodes;
}

// This functions add strings to trie data structue
void add_string(string s,vector<vector<int>>&t,vector<int>&string_ends_on_me)
{
    int cur=root;
    for(char ch:s)
    {
        if(t[cur][ch-'a'])
        {
            cur=t[cur][ch-'a'];
        }
        else
        {
            t[cur][ch-'a']=new_node();
            cur=t[cur][ch-'a'];
        }
    }
    string_ends_on_me[cur]++;
}

// This function is used for searching purpose
bool search_string(string s,vector<vector<int>>&t,vector<int>&string_ends_on_me)
{
    int cur=root;
    for(auto ch:s)
    {
        if(t[cur][ch-'a'])
        {
            cur=t[cur][ch-'a'];
        }
        else
        {
            return false;
        }
    }
    if(string_ends_on_me[cur])return true;
    else return false;
}

// This function is used to count duplicate strings present in input
int count_duplicate(string s,vector<int>&string_ends_on_me)
{
    int ans=0;
    for(int i=1;i<=nodes;i++)
    {
        if(string_ends_on_me[i]>1)ans++;
    }
    return ans;
}

// This function is used to count distinct strings present in input
int count_distinct(string s,vector<int>&string_ends_on_me)
{
    int ans=0;
    for(int i=1;i<=nodes;i++)
    {
        if(string_ends_on_me[i]>0)ans++;
    }
    return ans;
}



int main()
{
ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif 

   
   
   int n;
   cout<<"Enter number of strings in database\n";
   cin>>n;
   cout<<"Enter string\n";
   vector<string>v(n);
   for(int i=0;i<n;i++)cin>>v[i];
   vector<vector<int>>t(1000001,vector<int>(26,0));
   vector<int>string_ends_on_me(1000001,0);
   for(int i=0;i<n;i++)
   {
       add_string(v[i],t,string_ends_on_me);
   }
   cout<<"Enter strings to be searched in database\n";
   string s;
   cin>>s;
   if(search_string(s,t,string_ends_on_me))cout<<"YES IT EXIST\n";
   else cout<<"NOT FOUND";


   return 0;
}
   




// 2^64-1 use Unsigned long long 