#include <bits/stdc++.h>
using namespace std;
// it's for minimum
class SGtree{
    vector<int> seg;
    public:
        SGtree(int n)
        {
            seg.resize(4*n);
        }

        void build(int idx,int low,int high,vector<int> &arr)
        {
            if(high==low)
            {
                seg[idx]=arr[low];
                return;
            }

            int mid= (low+high)>>1;
            build(2*idx+1,low,mid,arr);
            build(2*idx+2,mid+1,high,arr);
            seg[idx]=min(seg[2*idx+1],seg[2*idx+2]);
        }

        int find(int idx,int low,int high,int l,int r)
        {
            if(r<low || high<l)return INT_MAX;

            if(low>=l and high<=r)return seg[idx];
            
            int mid= (low+high)>>1;
            int left=find(2*idx+1,low,mid,l,r);
            int right=find(2*idx+2,mid+1,high,l,r);
            return min(left,right);
        }

        void update(int idx,int low,int high,int i,int val)
        {
            if(high==low)
            {
                seg[idx]=val;
                return;
            }
            int mid=(high+low)>>1;
            if(i<=mid)update(2*idx+1,low,mid,i,val);
            else update(2*idx+2,mid+1,high,i,val);
            seg[idx]=min(seg[2*idx+1],seg[2*idx+2]);
        }

};

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    SGtree sg1(n);
    sg1.build(0,0,n-1,arr);

    // int n2;
    // cin>>n2;
    // vector<int> arr2;
    // for(int i=0;i<n2;i++)
    // {
    //     cin>>arr2[i];
    // }

    int q;
    cin>>q;
    while(q--)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            //find min
            int l,r;
            cin>>l>>r;
            cout<<sg1.find(0,0,n-1,l,r);
        }
        else
        {
            // update
            int ii,val;
            cin>>ii>>val;
            sg1.update(0,0,n-1,ii,val);
            arr[ii]=val;
        }
    }
}