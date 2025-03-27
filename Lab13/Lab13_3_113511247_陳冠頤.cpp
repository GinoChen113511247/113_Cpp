#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

struct Info
{
    string username;
    int numIn = 0;
    int numOut = 0;
};

int findUser(Info users[], int size, const string &username)
{
    for (int i = 0; i < size; i++)
    {
        if (users[i].username == username)
            return i; // 用戶存在的話就返回其編號
    }
    return -1; // 用戶不存在
}

int main()
{
    ifstream input("status.log");
    ofstream output("summary.txt");

    Info users[20];    // 宣告一個陣列用來存用戶資料
    int userCount = 0; // 數有幾個用戶

    string line;
    while (getline(input, line))
    {
        istringstream iss(line);
        string temp, username, action;

        iss.ignore(100, ']'); // "INFO:"前的東西都忽略
        iss >> temp;

        if (temp == "INFO:")
        {
            iss >> temp >> username >> temp >> action;

            int idx = findUser(users, userCount, username); // 檢查此用戶是否已被記錄
            if (idx == -1)
            {
                users[userCount].username = username; // 沒的話就新增用戶
                idx = userCount++;
            }

            if (action == "in")
                users[idx].numIn++;
            else if (action == "out")
                users[idx].numOut++; // 更新用戶登入登出次數
        }
    }

    sort(users, users + userCount, [](const Info &a, const Info &b)
         { return a.username < b.username; }); // 按字母順序排序

    // 輸出結果到檔案
    for (int i = 0; i < userCount; i++)
    {
        output << users[i].username << ": " << users[i].numIn;
        output << " login(s), " << users[i].numOut << " logout(s)" << endl;
    }

    input.close();
    output.close();
    return 0;
}