#include <string>
#include <stdio.h>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> guess[3] = {{1, 2, 3, 4, 5}, {2, 1, 2, 3, 2, 4, 2, 5}, {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}};
    int table[3] = {5, 8, 10};
    int math_score[3] = {0,};
    int score;
    int max_score = -1;

    for (int i=1;i<=3;i++){
        score = 0;
        for(int j=0;j<answers.size();j++){
            if (guess[i-1][j%table[i-1]] == answers[j])
                score++;
        }
        math_score[i-1] = score;
        if (max_score < score)
            max_score = score;
    }
    for (int i=0;i<3;i++)
    {
        if (max_score == math_score[i])
            answer.push_back(i+1);
    }
    return answer;
}