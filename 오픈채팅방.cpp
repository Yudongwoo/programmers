#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
vector <string> solution(vector <string> record)
{
    vector <string> answer;
    vector <string> to_print;
    vector <string> uid;
    map <string,string> uid_to_nick;
    stringstream ss;
    string temp_flag; string temp_uid; string temp_nick;
    for (int i=0;i<record.size();i++)
    {
        ss.str(record[i]);
        ss >> temp_flag;
        if (temp_flag == "Enter")
        {
            ss >> temp_uid;
            ss >> temp_nick;
            uid.push_back(temp_uid);
            uid_to_nick[temp_uid] = temp_nick;
            to_print.push_back("님이 들어왔습니다.");
        }
        else if (temp_flag == "Leave")
        {
            ss >> temp_uid;
            uid.push_back(temp_uid);
            to_print.push_back("님이 나갔습니다.");
        }
        else
        {
            ss >> temp_uid;
            ss >> temp_nick;
            uid_to_nick[temp_uid] = temp_nick;
        }
        ss.clear();
    }
    for (int i=0;i<to_print.size();i++)
        answer.push_back(uid_to_nick[uid[i]] + to_print[i]);
    return (answer);
}
