#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void bubble(vector<int>& v){
	bool swapped;
	for(int i = 0; i < v.size(); i++){
		swapped = false;

		for(int j = 0; j < v.size() - 1 - i; j++){
			if(v.at(j) > v.at(j + 1)){
				swapped = true;
				int hold = v.at(j);
				v.at(j) = v.at(j + 1);
				v.at(j + 1) = hold;
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
	while(getline(inputFile, s)){
		nums.push_back(stoi(s));

	}
	bubble(nums);
	
	ofstream outputFile(argv[2]);
	for(int i = 0; i < nums.size(); i++){
		outputFile << nums.at(i) << endl;
	}
	
	

	return 0;
}
