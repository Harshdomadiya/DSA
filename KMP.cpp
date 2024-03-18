// ----------------------------------knuth-Morris-pratt KMP string matching-----------------------------------------------------------------------------
// 1.first calculate lps :- longest common prefix and suffix
// 2.then use KMP
// let assume we have 2 string pattern and text which length M and N
// 1.LPS:-
#include <bits/stdc++.h>
using namespace std;
void LPS(string pat,vector<int> &Lp,int M)
{
    int len=0;
    Lp[0]=0;
    int i=1;
    while(i<M)
    {
        if(pat[i]==pat[len])
        {
            len++;
            Lp[i]=len;
            i++;
        }
        else
        {
            if(len!=0){
            len=Lp[len-1];
            }
            else
            {
                Lp[i]=0;
                i++;
            }
        }
    }
}
// 2.KMP
int main(){
    string text, pat;
    cin >> text >> pat;
    int N=text.size();
    int M=pat.size();
    int i = 0;
    int j = 0;
    vector<int> Lp;
    LPS(pat,Lp,M);
    vector<int> ans;
    while (i < N)
    {
        if (text[i] == pat[j])
        {
            i++;
            j++;
        }
        if (j == M)
        {
            ans.push_back(i - j);
            j = Lp[j - 1];
        }
        else if (text[i] != pat[j])
        {
            if (j != 0)
            {
                j = Lp[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
    return 0;
}
