#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void bubble(vector<int>& v){
	bool swapped;
	int n = v.size();
	for(int i = 0; i < n; i++){
		swapped = false;

		for(int j = 0; j < n - 1 - i; j++){
			if(v[j] > v[j+1]){
				swapped = true;
				swap(v[j], v[j+1]);
			}
		}

		if(!swapped){
			break;
		}
	}
}




int main(int argc, char** argv){
	ifstream inputFile(argv[1]);

	string s;
	vector<int> nums;
	nums.reserve(1000000);
	while(getline(inputFile, s)){
		nums.push_back(stoi(s));

	}
	bubble(nums);
	
	ofstream outputFile(argv[2]);
	n = nums.size();
	for(int i = 0; i < n; i++){
		outputFile << nums[i] << endl;
	}
	
	

	return 0;
}
