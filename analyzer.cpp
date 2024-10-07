#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <fstream>
#include "StringData.h"






int linear_search(vector<string> container, string element) {
    int size = container.size();
    for (int i =0; i<size; i++) {
        if(container[i] == element) {
            return i;
        }
    }
    return -1;

}



int binary_search(vector<string> container, string element) {
    int count = 0;
    int high = container.size();
    int low = 0;
    bool done = false;
    int prevMid =-1;
    while(done==false) {
        int middle = low+((high-low)/2);
        if(container[middle] == element) {
            return middle;
        }
        else if(container[middle]<element) {
            if((middle+1)<container.size()) {
                low = middle+1;
            }

        }
        else if(container[middle]>element) {
            if((middle-1)>-1) {
                high = middle-1;
            }
        }
        if(middle==prevMid) {
            return -1;
        }
        prevMid = middle;
    }
    return -1;

}


int main()
{

    vector<string> test = getStringData();
    string test1 = "aaaaa";
    string test2 = "mzzzz";
    string test3 = "not_here";
    double num1=0;
    double num2=0;
     num1 = systemTimeNanoseconds();
    cout << "Index:"<<binary_search(test,test1) << endl;
    num2 = systemTimeNanoseconds();
    cout<< "Binary search time for aaaaa: "<<num2-num1<<endl;

    num1 = systemTimeNanoseconds();
    cout << "Index:"<<linear_search(test,test1) << endl;
    num2 = systemTimeNanoseconds();
    cout<< "Linear search time for aaaaa: "<<num2-num1<<endl;

    num1 = systemTimeNanoseconds();
    cout << "Index:"<<binary_search(test,test2) << endl;
    num2 = systemTimeNanoseconds();
    cout<< "Binary search time for mzzzz: "<<num2-num1<<endl;

    num1 = systemTimeNanoseconds();
    cout << "Index:"<<linear_search(test,test2) << endl;
    num2 = systemTimeNanoseconds();
    cout<< "Linear search time for mzzzz: "<<num2-num1<<endl;

    num1 = systemTimeNanoseconds();
    cout << "Index:"<<binary_search(test,test3) << endl;
    num2 = systemTimeNanoseconds();
    cout<< "Binary search time for not_here: "<<num2-num1<<endl;

    num1 = systemTimeNanoseconds();
    cout << "Index:"<<linear_search(test,test3) << endl;
    num2 = systemTimeNanoseconds();
    cout<< "Linear search time for not_here: "<<num2-num1<<endl;


    return 0;

}
