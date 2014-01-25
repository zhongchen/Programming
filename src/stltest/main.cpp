#include "SetTest.h"
#include "HashTest.h"
#include "RandomTest.h"
#include "SortTest.h"
#include "SearchTest.h"
#include "ThreadTest.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv){
    string line;
    ifstream inputFile;
    inputFile.open("testFile");
    if (inputFile.is_open())
    {
        while (getline(inputFile, line))
        {
            cout<<line<<endl;
        }
        inputFile.close();
    }
    
    //ThreadTest();
    //SearchTest();
    //SortTest();
    //SetTest();
    //HashTest();
    //RndomTest();
    return 0;
}
