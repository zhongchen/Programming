#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <unordered_map>
#include <bitset>
using namespace std;


vector<char> MissingAlphabets(string& inputString)
{
    const unsigned int NUM_ALPHABET = 26;
    std::bitset<NUM_ALPHABET> alphabet_table;
    auto data = inputString.data();

    for (int i=0; i<inputString.size(); ++i)
    {
        auto temp1 = data[i] - 'a';
	auto temp2 = data[i] - 'A';

	if (0<=temp1 && temp1 <=25)
	{
	    alphabet_table.set(temp1);
	    continue;
	}

	if (0<=temp2 && temp2 <=25)
	{
	    alphabet_table.set(temp2);
	}
    }
    vector<char> result;

    char missing_letter = 'a';
    for (int i=0; i<NUM_ALPHABET; ++i)
    {
	if (!alphabet_table[i])
	{
	    result.push_back(missing_letter+i);
	}
    }

    return result;
}

void OutputResult(const vector<char>& result)
{
    for (auto i:result)
    {
	cout<<i<<'\t';
    }
    cout<<endl;
}

void RunCheckAlphabets()
{
    string test1 = "A quick brown fox jumps over the lazy dog";
    string test2 = "A slow yellow fox crawls under the proactive dog";
    string test3 = "Lions, and tigers, and bears, oh my!";

    auto result = MissingAlphabets(test1);
    OutputResult(result);
    result = MissingAlphabets(test2);
    OutputResult(result);
    result = MissingAlphabets(test3);
    OutputResult(result);
}
