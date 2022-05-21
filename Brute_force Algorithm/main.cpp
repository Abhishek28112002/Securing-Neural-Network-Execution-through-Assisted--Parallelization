#include<bits/stdc++.h>
using namespace std;
int main()
{
	//variables for our input 
 unordered_map<int,int>Layers;
 unordered_map<int,int>3pc_time;
 vector<int,int>Hgc_time;
 unordered_map<int,int>Comm_time;
 long long int No_hgc;
 
 //ready to take input from input's file
 unordered_map<string,string>Input;
 ifstream in;
 in.open("Input's/Input1.txt");
string name,array;
 while(in.eof()==0)
 {
 	getline(in,name);
 	getline(in,array);
 Input[name]=array;
 }
 
 //checking input captured is right or wrong.
// for(auto it:m)
// cout<<it.first<<" "<<it.second<<endl;

//inserting data...
 for(int i=0;i<Input["Layers"].length();i+=2)
    {
 	Layers[i/2]=(int)(Input["Layers"][i] -'0');
    }
 
 for(int i=0;i<Input["3pctime"].length();i+=2)
    {
 	3pc_time[i/2]=(int)(Input["3pctime"][i] -'0');
    }
 
for(int i=0;i<Input["comm.time"].length();i+=2)
    {
 	Comm_time[i/2]=(int)(Input["comm.time"][i] -'0');
    }
 
 for(int i;i<Input["hgctime"].length();i+=2)
    {
 	Hgc_time({(int)(Input["hgctime"][i] -'0'),i/2});
    }
    
 No_hgc=(int)(Input[noofhgc] -'0');
  
  
  //main algorithm start from here
  
  
}
