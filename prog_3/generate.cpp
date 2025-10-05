#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

int main(int argc, char** argv){
    try {
        if(argc > 4){
            throw out_of_range("Out of range");
        }
        for(int i = 0; i < argc; i++){
            cout << "argv[" << i << "]:" << argv[i] << endl;
        }
        ofstream outputFile("numbers.dat");
        srand(time(NULL)); 
        int maxVal = stoi(argv[3]);
        int minVal = stoi(argv[2]);
        for(int i = 0; i < stoi(argv[1]); i++){
            outputFile << rand() % (maxVal - minVal + 1) - int((maxVal - minVal) / 2) << endl;
        }
    } 
    
    catch(out_of_range& e){
        cout << "Caught exception: " << e.what() << endl;
    }
    return 0;
}