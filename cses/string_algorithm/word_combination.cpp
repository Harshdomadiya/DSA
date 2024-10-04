#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long int
#define ll long long int
#define vll vector<ll>
#define vpll vector<pair<ll, ll>>
#define vvll vector<vector<ll>>
#define pll pair<ll, ll>
#define mpll map<ll, ll>
#define ld long double
#define fd double double
#define f(i, x, n) for (int i = x; i < n; i++)
#define rf(i, x, n) for (int i = x; i >= n; i--)
#define pb push_back
#define PI (3.141592653589)
#define sp(n) setprecision(n)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) (ll) a.size()
#define pi (3.141592653589)
#define min3(a, b, c) min(a, min(b, c))
#define min4(a, b, c, d) min(a, min(b, min(c, d)))
#define max3(a, b, c) max(a, max(b, c))
#define max4(a, b, c, d) max(a, max(b, max(c, d)))
#define max5(a, b, c, d, e) max(a, max(b, max(c, max(d, e))))
#define min5(a, b, c, d, e) min(a, min(b, min(c, min(d, e))))
const int mod=1e9+7;
#define dl endl

struct TrieNode{
    struct  TrieNode* child[26];
    bool isEnd;
    TrieNode(){
        isEnd=0;
        f(i,0,26)
        {
            child[i]=NULL;
        }
    }
} *root;
bool SearchString(string str)
{
    TrieNode *curr = root;
    ll n=str.length();
    f(i,0,n)
    {
        int idx=str[i]-'a';
        if(curr->child[idx]==NULL)return 0;
        curr = curr->child[idx];
    }
    return curr->isEnd;
}
void insertString(string str)
{
    TrieNode *curr = root;
    ll n=str.length();
    f(i,0,n)
    {
        int idx=str[i]-'a';
        if(curr->child[idx]==NULL)
        {
            curr->child[idx]=new TrieNode();
        }
        curr=curr->child[idx];
    }
    curr->isEnd=1;
}
 
 
void solve(){
    string s;
    cin>>s;
    ll n;
    cin>>n;
    root = new TrieNode();
    f(i,0,n)
    {
        string t;
        cin>>t;
        insertString(t);
    }
    ll len=s.length();
    vll dp(len+1);
    dp[len]=1;
    for(int i=len-1;i>=0;i--)
    {
        TrieNode *test = root;
        for(int j=i;j<len;j++)
        {
            ll idx = s[j]-'a';
            if(test->child[idx]==NULL)break;
            test=test->child[idx];
            if(test->isEnd)
            {
                dp[i]=(dp[i]%mod + dp[j+1]%mod)%mod;
            }
        }
    }
    cout<<dp[0]<<endl;
}
int main()
{
    // int t;
    // cin>>t;
    // while(t--)
    solve();
 
    return 0;
}
