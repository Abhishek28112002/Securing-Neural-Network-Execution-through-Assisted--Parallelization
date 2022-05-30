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
	int count_input = 0;
	int count1 = 0;

	// taking input
	while (in.eof() == 0)
	{
		in >> num;
		if (n > 0)
		{
			n--;
			if (count_input == 0)
			{
				Layers[count1] = num;
			}
			else if (count_input == 1)
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

}
