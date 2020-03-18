#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

int solution(vector<vector<int>> baseball) {
    int answer = 0;
    int first, second, third;
    int strikes = 0, balls = 0, cnt = 0;
    for (int i=1;i<=9;i++)
    {
        for (int j=1;j<=9;j++)
        {
            for (int k=1;k<=9;k++)
            {
                if (i == j || j == k || k == i)
                    continue;
                cnt = 0;
                for (int l=0;l<baseball.size();l++)
                {
                    first = baseball[l][0]/100;
                    second = (baseball[l][0]%100)/10;
                    third = (baseball[l][0]%100)%10;
                    strikes = 0;
                    balls = 0;

                    if (first == i) strikes++;
                    if (second == j) strikes++;
                    if (third == k) strikes++;
                    if (i == second || i == third) balls++;
                    if (j == first || j == third) balls++;
                    if (k == first || k == second) balls++;
                    if (strikes != baseball[l][1] || balls != baseball[l][2])
                        break;
                    cnt++;
                }
                if (cnt == baseball.size())
                    answer++;
            }
        }
    }
    return answer;
}