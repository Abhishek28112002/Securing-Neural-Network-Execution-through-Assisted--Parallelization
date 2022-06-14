#include <bits/stdc++.h>
using namespace std;

int main()
{
	// variables for our input
	unordered_map<int, int> Layers;
	unordered_map<int, int> threepc_time;
	vector<pair<int, int>> Hgc_time;
	unordered_map<int, int> Comm_time;
	long long int No_hgc;

	// //ready to take input from input's file
	unordered_map<string, string> Input;
	ifstream in;
	in.open("Input1.txt");
	string name, array;
	int num;
	in >> num;
	int n = num;
	int count_input = 1;
	int count1 = 0;

	// taking input
	// input file formate 
	// no of layers Three pc time
	// no of layers Hgc time
	// no of layers comm time
	// 1 no of hgc
	while (in.eof() == 0)
	{
		in >> num;
		if (n > 0)
		{
			n--;
			 if (count_input == 1)
			{
				threepc_time[count1] = num;
			}
			else if (count_input == 2)
			{
				Hgc_time.push_back({num, count1});
			}
			else if (count_input == 3)
			{
				Comm_time[count1] = num;
			}
			else
				No_hgc = num;
			count1++;
		} 
		else
			n = num, count1 = 0, count_input++;
	}

	// //checking input captured is right or wrong.
	// for(auto it:Layers)
	// cout<<it.first<<" "<<it.second<<endl;
	// cout<<endl;
	// for(auto it:threepc_time)
	// cout<<it.first<<" "<<it.second<<endl;
	// cout<<endl;
	// for(auto it:Hgc_time)
	// cout<<it.first<<" "<<it.second<<endl;
	// cout<<endl;
	// for(auto it:Comm_time)
	// cout<<it.first<<" "<<it.second<<endl;
	// cout<<endl;
	// cout<<No_hgc<<endl;

	// main algorithm start from here

	// time is like how much time it will take in that step
	long long int Max_time = 0, Time = 0;

	// i have made this to take care of no of hgc's after uses we will increase no of hgc's
	vector<pair<int, long long int>> Hgc_Totaltime;

	// threepctime take care of threepctime of pervious running layers till that step
	long long int threepctime = 0;

	// calculation of 3pc time till i th layer;
	unordered_map<long long int, long long int> Threepc_timei;
	for (int i=0;i<threepc_time.size();i++)
	{
		Threepc_timei[i] = threepctime;
		threepctime += threepc_time[i];
	}
	for (auto it : Hgc_time)
	{
		// adding the threepc time till now
		Time = 0;
		if (it.second != 0)
		{
			// add the tiem of just previous layer and comm. time
			Time += Threepc_timei[it.second] + Comm_time[it.second - 1];
		}
		Time += it.first;
		Hgc_Totaltime.push_back({Time, it.second});
	}

	long long timerem_tofree = INT_MAX, freetime = 0, updated_Totaltime = 0,index=-1;
	// no of hgc
	for (auto it : Hgc_Totaltime)
	{

		// adding the threepc time till now
		Time = 0;
		if (it.second != 0)
		{
			// add the tiem of just previous layer and comm. time
			Time += Threepc_timei[it.second - 1] + Comm_time[it.second - 1];
		}

		// consdering there is no hgc's left(because if at last totaltime of hgc will less comapre to this then, the persent one can use the free hgc now and save for that one
		for (auto ip : Hgc_Totaltime)
		{
			// if time is greater then there total time then this will free
			if (ip.first < it.first)
			{
				if (ip.first <= Time)
				{
					No_hgc++;

					

					// updating its totalrun time because this already free and used for this step so we won't count this
					ip.first = -1;

					// break here we need only 1 hgc at this point of time and we dont know about others time ,will more or less
					break;
				}
				// if no hgc will free then tha min time we have to wait
				freetime = Time - ip.first;
				if(freetime<timerem_tofree)
				{
					index++;
				}
				timerem_tofree = min(timerem_tofree, freetime);
			}
			else
				break;
		}
		if (No_hgc == 0)
		{
			// if hgc's are 0 then till how much time this have to wait
			it.first += timerem_tofree;
// updating hgc time also
           Hgc_Totaltime[index].first=-1;

			// updating to its true value
			timerem_tofree = INT_MAX, freetime = 0;

			// updating no f hgc
			No_hgc++;
		}

		// updating no of hgc
		No_hgc -= 1;
		updated_Totaltime = it.first;
		// updating  time
		Max_time = max(Max_time, updated_Totaltime);
	}

	cout << Max_time << endl;
}
