#include <string>
#include <vector>

using namespace std;

void recursive(int inx, vector<int> numbers, char op[], int target, int *answer)
{   
    if (inx >= numbers.size())
    {
        int i = -1;
        int sum = 0;
        
        while (++i < inx)
        {
            if (op[i] == '+')
                sum += numbers[i];
            else
                sum -= numbers[i];
        }
        if (sum == target)
        {
            (*answer)++;
            return;
        }
    }
    else
    {
        op[inx] = '+';
        recursive(inx + 1, numbers, op, target, answer);
        op[inx] = '-';
        recursive(inx + 1, numbers, op, target, answer);
    }
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    char op[30];
    
    recursive(0, numbers, op, target, &answer);
    return answer;
}