#include <string>
#include <vector>
#include <stdio.h>
#include <iostream>

using namespace std;
int prime_table[10000010];
string p_result = "";
int check[10];

void initialize()
{
    check[10] = {0,};
    p_result.clear();
}

void permutation(int inx, string numbers, int *answer, int r)
{
    if (inx >= r)
    {
        int num = stoi(p_result);
        if (prime_table[num] != 0)
        {
            prime_table[num] = 0;
            (*answer)++;
        }
    }
    else
    {
        for (int i=0;i<numbers.size();i++)
        {
            if (check[i] || (inx == 0 && numbers[i] == '0'))
                continue;
            p_result.push_back(numbers[i]);
            check[i] = 1;
            permutation(inx + 1, numbers, answer, r);
            check[i] = 0;
            p_result.pop_back();
        }
    }
}
int solution(string numbers) {
    int answer = 0;

    p_result.reserve(10);
    prime_table[2] = 1;
    for(int i=1;i<10000000;i++)
        prime_table[i] = i;

    prime_table[1] = 0;
    for(int i=2;i<10000000;i++)
    {
        if (prime_table[i] == 0)
            continue;
        for(int j=i+i;j<10000000;j+=i)
            prime_table[j] = 0;
    }

    for(int i=1;i<=numbers.size();i++)
    {
        initialize();
        permutation(0, numbers, &answer, i);
    }
    return answer;
}