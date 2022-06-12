#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<int, int> &a,
			   const pair<int, int> &b)
{
	return (a.second < b.second);
}
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

	// sorted the runtime of hgc in descending order
	sort(Hgc_time.begin(), Hgc_time.end());
	reverse(Hgc_time.begin(), Hgc_time.end());
	sort(Hgc_time.begin(), Hgc_time.begin() + No_hgc, sortbysec);

	// time is like how much time it will take in that step
	long long int Max_time = 0, Time = 0;

	// i have made this to take care of no of hgc's after uses we will increase no of hgc's
	vector<long long int> Totaltime;

	// threepctime take care of threepctime of pervious running layers till that step
	long long int threepctime = 0;

	// calculation of 3pc time till i th layer;
	unordered_map<long long int, long long int> Threepc_timei;
	for (auto it : threepc_time)
	{
		Threepc_timei[it.first] = threepctime;
		threepctime += it.second;
	}
	// we also need to track of free hgc, so these two wil track of time that hgc will take to free
	long long timerem_tofree = INT_MAX, freetime = 0;
	for (auto it : Hgc_time)
	{

		// adding the threepc time till now
		Time = 0;
		if (it.second != 0)
		{
			// add the tiem of just previous layer and comm. time
			Time += Threepc_timei[it.second - 1] + Comm_time[it.second - 1];
		}

		// consdering there is no hgc's left(because if at last totaltime of hgc will less comapre to this then, the persent one can use the free hgc now and save for that one
		for (auto it : Totaltime)
		{
			// if time is greater then there total time then this will free
			if (it <= Time)
			{
				No_hgc++;

				// break here we need only 1 hgc at this point of time and we dont know about others time ,will more or less
				break;

				// updating its totalrun time because this already free and used for this step so we won't count this
				it = -1;
			}
			// if no hgc will free then tha min time we have to wait
			freetime = Time - it;
			timerem_tofree = min(timerem_tofree, freetime);
		}
		if (No_hgc == 0)
		{
			// if hgc's are 0 then till how much time this have to wait
			Time += timerem_tofree;

			// updating to its true value
			timerem_tofree = INT_MAX, freetime = 0;

			// updating no f hgc
			No_hgc++;
		}
		Time += it.first;
		Totaltime.push_back(Time);

		// updating no of hgc
		No_hgc -= 1;

		// updating  time
		Max_time = max(Max_time, Time);
	}

	cout << Max_time << endl;
}
