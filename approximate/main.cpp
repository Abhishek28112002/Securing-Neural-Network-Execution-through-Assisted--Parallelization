#include <bits/stdc++.h>
using namespace std;
 
int shgc(int s_index,int e_index,int thgc[])
{
    int sum=0;
    for(int i=s_index;i<=e_index;i++)
            sum+=thgc[i];
    return sum;
}
int spc(int s_index,int e_index,int t3pc[])
{
    int sum=0;
    for(int i=s_index;i<=e_index;i++)
            sum+=t3pc[i];
    return sum;
}
 
int main() {
   
    //declaration
    int nlayers,s3pc,nhgc;
    int st3pc=0,sthgc=0;
    cin>>nlayers;
    int t3pc[nlayers];
    for(int i=0;i<nlayers;i++)
    {
        cin>>t3pc[i];
        st3pc+=t3pc[i];
    }
    int commtime[nlayers];
    for(int i=0;i<nlayers;i++)
        cin>>commtime[i];
    int thgc[nlayers];
    for(int i=0;i<nlayers;i++)
    {
        cin>>thgc[i];
        sthgc+=thgc[i];
    }
    cin>>nhgc;
 
    float T,x;
 
    x= s3pc/sthgc;
 
    T=st3pc/(1- pow((1-x),nhgc));
 
    int c=nhgc-1,tbatch_ideal;
    int sum=0,time_taken_by_hgc[nhgc];
    int array_storing_first_layer_index[nhgc];
    int tout;
 
    for(int i=nlayers-1;i>0;i--)    //i>0 because we wont cross first layer
    {
        tbatch_ideal=T*pow((1-x),c);
 
        if(sum+thgc[i]>tbatch_ideal)
        {
            array_storing_first_layer_index[c]=i;
            time_taken_by_hgc[c]=sum;
            c--;
            sum=0;
        }
        sum+=thgc[i];
    }
    for (int i = 1; i < nhgc-1; i++)
    {
        time_taken_by_hgc[i]= spc(0,array_storing_first_layer_index[i],t3pc);
        time_taken_by_hgc[i]+=commtime[i];
        time_taken_by_hgc[i]+=shgc(array_storing_first_layer_index[i-1],array_storing_first_layer_index[i],thgc);
    }
 
    sort(time_taken_by_hgc,time_taken_by_hgc+nhgc);
    tout=time_taken_by_hgc[nhgc-1];
    }
