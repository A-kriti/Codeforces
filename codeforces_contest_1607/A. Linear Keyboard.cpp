// ques - https://codeforces.com/contest/1607/problem/A

#include <bits/stdc++.h>

using namespace std;

int max_time(string &s1,string &s2){
    
    unordered_map<char,int>m;
    int n=s2.length();
    int y=s1.length();
    
    for(int i=0;i<n;i++){
        m[s2[i]]=0;
    }
    
    for(int i=0;i<y;i++){
        
        if(m.find(s1[i])!=m.end()){
            m[s1[i]]=i+1;
        }
    }
    
    int val1;
    for(auto x:m){
        if(x.first==s2[0]) val1=x.second;
    }
    int val2;
    int ans=0;
    for(int i=1;i<n;i++){
        for(auto x:m){
            if(s2[i]==x.first) {
                val2=x.second;
                ans+=abs(val1-val2);
                val1=val2;
                }
        }
    }
    
    return ans;
}

int main()
{
    int t;
    cin>>t;
    string s1;
    vector<string>v;
    
    for(int i=0;i<2*t;i++){
        cin>>s1;
        v.push_back(s1);
        
    }
    
    for(int i=0;i<v.size()-1;i+=2){
        cout<<max_time(v[i],v[i+1])<<endl;
    }
    // string s1="qwertyuiopasdfghjklzxcvbnm";
    // string s2="abacaba";
    // cout<<max_time(s1,s2);

    return 0;
}
