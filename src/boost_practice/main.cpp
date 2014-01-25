#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<char> MissingAlphabets(string& inputString)
{
   
    std::transform(inputString.begin(), inputString.end(),
                   inputString.begin(), ::tolower);
    
    cout<<inputString<<endl;
    unordered_map<char, int> countMap;
    

}
int main(int argc, char* argv[])
{
    string test1 = "A quick brown fox jumps over the lazy dog";
    auto result = MissingAlphabets(test1);
}    











