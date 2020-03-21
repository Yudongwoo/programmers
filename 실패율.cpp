#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    float people_in_stage[510] = {0,};
    float stage_clear_people[510] = {0,};
    float failure_rate[510] = {0,};
    float nbr_of_users = stages.size();
    float temp = nbr_of_users;
    for (int i = 0;i < nbr_of_users;i++)
        people_in_stage[stages[i]]++;
    for (int i = 1;i <= N;i++)
    {
        temp -= people_in_stage[i - 1];
        stage_clear_people[i] = temp;
    }
    for (int i = 1;i <= N;i++)
    {
        if (stage_clear_people[i] == 0)
            failure_rate[i] = 0;
        else
            failure_rate[i] = people_in_stage[i] / stage_clear_people[i];
    }
    int inx = -1;
    float max_rate = -1;

    for (int i = 1;i <= N;i++)
    {
        inx = -1;
        max_rate = -1;
        for (int j = 1;j <= N;j++)
        {
            if (max_rate < failure_rate[j])
            {
                max_rate = failure_rate[j];
                inx = j;
            }
        }
        answer.push_back(inx);
        failure_rate[inx] = -1;
    }
    return answer;
}