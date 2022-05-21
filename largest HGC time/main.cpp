# include <bits/stdc++.h>
using namespace std;
int main()
{
	//variables for our input 
 unordered_map<int,int>Layers;
 unordered_map<int,int>threepc_time;
 vector<pair<int,int>>Hgc_time;
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
 	   Layers[i/2]=(int)Input["Layers"][i] -48;
    }
 
 for(int i=0;i<Input["threepctime"].length();i+=2)
    {
 	   threepc_time[i/2]=(int)(Input["threepctime"][i] -'0');
    }
 
for(int i=0;i<Input["comm.time"].length();i+=2)
    {
 	   Comm_time[i/2]=(int)(Input["comm.time"][i] -'0');
    }
 
 for(int i=0;i<Input["hgctime"].length();i+=2)
    {
 	   Hgc_time.push_back({((int)Input["hgctime"][i]) -48,i/2});
    }
    
  No_hgc=(int)(Input["noofhgc"][0] -'0');
  
  
//main algorithm start from here
  
//sorted the runtime of hgc in descending order
  sort(Hgc_time.begin(),Hgc_time.end(),greater<int>());
  
//time is like how much time it will take in that step
  long long int Max_time=0,Time=0; 
  
//i have made this to take care of no of hgc's after uses we will increase no of hgc's
  vector<long long int >Totaltime;
  
//threepctime take care of threepctime of pervious running layers till that step 
  long long int threepctime=0; 
  
// we also need to track of free hgc, so these two wil track of time that hgc will take to free
  long long timerem_tofree=INT_MAX,freetime=0;
  for(auto it:Hgc_time)
    {
	
    	// adding the threepc time till now
  	    Time=threepctime ;
  	    if(it.second!=0)
  	    {
  	    // add the tiem of just previous layer and comm. time	
  		Time+=threepc_time[it.second-1]+Comm_time[it.second-1];
  		
  		//updating the threepc time 
  		threepctime+=threepc_time[it.second-1];
	    }
	    
	    // consdering there is no hgc's left(because if at last totaltime of hgc will less comapre to this then, the persent one can use the free hgc now and save for that one
	    for(auto it:Totaltime)
	    {
	    	// if time is greater then there total time then this will free
	    	if(it>=Time)
	    	{
	    		No_hgc++;
	    		
	    		// break here we need only 1 hgc at this point of time and we dont know about others time ,will more or less
	    		break;
	    		
	    		// updating its totalrun time because this already free and used for this step so we won't count this 
	    		it=-1;
			}
			// if no hgc will free then tha min time we have to wait
			freetime=Time-it;
			timerem_tofree=min(timerem_tofree,freetime);
		}
		if(No_hgc==0)
		{
			//if hgc's are 0 then till how much time this have to wait 
			Time+=timerem_tofree;
			
			//updating to its true value
			timerem_tofree=INT_MAX,freetime=0;
			
			//updating no f hgc
			No_hgc++;
		}
	    Time+=it.first;
	    Totaltime.push_back(Time);
	    
	    //updating no of hgc
	    No_hgc-=1;
	    
	    //updating  time 
	    Max_time=max(Max_time,Time);
	    
    }
    
    cout<<Max_time<<endl;
  
}
