#include <iostream>
#include <string>
#include <algorithm>
#define LETTERS 55
using namespace std;

pair<string, char> dziel_pisem(string number,int base_start, int base_end)
{
    string new_number = "";
    int remainder = 0;
    int size = number.size();
    int x = number[0];
    int counter = 1;

    if (char(x) >= 'A' and char(x) <= 'Z')
        x = x - LETTERS;
    else
        x = x - '0';

    while (size > 0)
    {
        remainder = x % base_end;
        if (remainder == 0)
        {
            if (x / base_end >= 10 and x / base_end <= 36)
            {
                new_number += char(x / base_end + LETTERS);
            }
            else
                new_number += x / base_end + '0';
        }
        else
        {
            if (x / base_end >= 10 and x / base_end <= 36)
            {
                new_number += char(x / base_end + LETTERS);
            }
            else
            {
                new_number += x / base_end + '0';
            }
        }

        if (char(number[counter]) >= 'A' and char(number[counter]) <= 'Z')
        {
            x = remainder * base_start + (number[counter] - LETTERS);
        }
        else
            x = remainder * base_start + (number[counter] - '0');

        size--;
        counter++;
    }

    char ret;
    if (remainder >= 10 and remainder <= 36)
    {
        ret = char(remainder + LETTERS);
    }
    else
        ret = char(remainder + '0');
 
    return make_pair(new_number, ret);
}

string change_base(string number, int base_start, int base_end)
{
    string new_number = "";
    pair<string, char> result;

   while (number != "0")
   {
        result = dziel_pisem(number, base_start, base_end);
        number = result.first;
        new_number += result.second;
        while (number.length() > 1 && number[0] == '0')
            number.erase(0, 1);
   }

    reverse(new_number.begin(), new_number.end());
    return new_number;
}

int main()
{
    int n, base_start, base_end;
    string number;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> number;
        cin >> base_start;
        cin >> base_end;
        if (number != "0")
            number = change_base(number, base_start, base_end);
        cout << number << endl;
    }

    return 0;
}

