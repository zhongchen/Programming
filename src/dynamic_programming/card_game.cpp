#include "card_game.h"
#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

struct record
{
    record()
    {
        max_value = 0;
        pick = 0;
    }
    int max_value;
    int pick;
};

void card_game_test()
{
    int n = 54;
    card_game(n);
}

void game_init(vector<int>& vec, int num_cards)
{
    for (int i=1; i<=num_cards; ++i)
    {
        vec[i-1] = i;
    }

    std::random_device rd;
    std::mt19937 gen(rd());

    std::shuffle(vec.begin(), vec.end(), gen);

}

int calculate_index(const int level,
                    const int num_cards,
                    const int pos)
{
    return pos + (num_cards + num_cards-level + 1) * level / 2;
    //int index = pos;
    //for (int i=level; i>0; --i)
    //{
    //    index += (num_cards - level + 1);
    //}
    //return index;
}

void make_move(const int i, const int j,
               const vector<int>& cards,
               const int num_cards,
               vector<record>& result_table)
{
    //assume j >=i
    int level = j - i;
    int index = calculate_index(level, num_cards, i);
    if (i==j)
    {
        result_table[index].max_value = cards[i];
        result_table[index].pick = i;
    }
    else if (i+1==j)
    {
        if (cards[i] > cards[j])
        {
            result_table[index].max_value = cards[i];
            result_table[index].pick = i;
        }
        else
        {
            result_table[index].max_value = cards[j];
            result_table[index].pick = j;
        }
    }
    else
    {
        int value_pick_front = 0;
        int temp_index = calculate_index(j-(i+1), num_cards, i+1);

        if (result_table[temp_index].pick == i+1)
        {
            temp_index = calculate_index(j-(i+2), num_cards, i+2);
        }
        else
        {
            temp_index = calculate_index(j-1-(i+1), num_cards, i+1);
        }
        value_pick_front = cards[i] + result_table[temp_index].max_value;

        int value_pick_back = 0;
        temp_index = calculate_index((j-1)-i, num_cards, i);

        if (result_table[temp_index].pick == i)
        {
            temp_index = calculate_index(j-1-(i+1), num_cards, i+1);
        }
        else
        {
            temp_index =calculate_index(j-2-i, num_cards, i);
        }
            
        value_pick_back = cards[j] + result_table[temp_index].max_value;

        if (value_pick_front > value_pick_back)
        {
            result_table[index].max_value = value_pick_front;
            result_table[index].pick = i;
        }
        else
        {
            result_table[index].max_value = value_pick_back;
            result_table[index].pick = j;
        }
    }
}

//The order of the result_table is (0,0) (1,1)... (n-1,n-1) (0,1)...
//Diagonal order
void card_game(int num_cards)
{
    vector<int> cards(num_cards);
    game_init(cards, num_cards);
    vector<record> result_table(num_cards*(num_cards+1)/2);
    for (int i=0; i<num_cards; ++i)
    {
        for (int j=0; j<num_cards-i; ++j)
        {
            make_move(j, j+i, cards, num_cards, result_table);
        }
    }

}
