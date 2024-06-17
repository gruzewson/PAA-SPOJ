#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <deque>
using namespace std;

int main()
{
    unsigned long long int n, buffer;
    unordered_map<unsigned long long int, unsigned long long int> weights; // weights and index
    vector<vector<pair<unsigned long long int, unsigned long long int>>> numbers;
    vector<pair<unsigned long long int, unsigned long long int>> right_hand;
    vector<pair<unsigned long long int, unsigned long long int>> left_hand;

    cin >> n;

    for (unsigned long long int i = 0; i < n; ++i)
    {
        cin >> buffer;
        weights[buffer] = i + 1;
    }

    deque<pair<unsigned long long int, unsigned long long int>> weights_order(weights.begin(), weights.end());
    sort(weights_order.begin(), weights_order.end());


    //zbieranie b,a,b-a
    unsigned long long int counter = 0;
    while (weights_order.size() > 1)
    {
        vector<pair<unsigned long long int, unsigned long long int>> number; //clear numbers

        pair<unsigned long long int, unsigned long long int> largest = weights_order.back();
        weights_order.pop_back();
        pair<unsigned long long int, unsigned long long int> second_largest = weights_order.back();
        weights_order.pop_back();

        pair<unsigned long long int, unsigned long long int> difference;
        difference.first = largest.first - second_largest.first;
        difference.second = largest.second;

        number.push_back(largest); //b
        number.push_back(second_largest); //a
        number.push_back(difference); //b-a
        numbers.push_back(number);
        counter++;

        weights_order.push_front(difference);
        sort(weights_order.begin(), weights_order.end());
    }

    //backtracking
    right_hand.push_back(weights_order[0]);

    while (counter > 0)
    {
        for (unsigned long long int i = 0; i < right_hand.size(); i++)
        {
            if (right_hand[i].first == numbers[counter - 1][2].first)
            {
                right_hand[i] = numbers[counter - 1][0];
                left_hand.push_back(numbers[counter - 1][1]);
                break;
            }
            else if (left_hand[i].first == numbers[counter - 1][2].first)
            {
                left_hand[i] = numbers[counter - 1][0];
                right_hand.push_back(numbers[counter - 1][1]);
                break;
            }
        }

        counter--;
    }
    
    sort(right_hand.begin(), right_hand.end());

    for (unsigned long long int i = 0; i < right_hand.size(); ++i)
    {
        cout << right_hand[i].second << endl;
    }

    return 0;
}

