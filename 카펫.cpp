#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer;
    int cal_brown = 0, cal_red = 0, rec = 0;
    int col = 3, row = 0;

    rec = brown + red;
    while (rec/col >= col)
    {
        if (rec % col != 0)
        {
            col++;
            continue;
        }
        row = rec / col;
        cal_brown = 2 * (row + col - 2);
        cal_red = rec - cal_brown;
        if (cal_brown == brown && cal_red == red)
            break;
        col++;
    }
    answer.push_back(row);
    answer.push_back(col);
    return answer;
}
