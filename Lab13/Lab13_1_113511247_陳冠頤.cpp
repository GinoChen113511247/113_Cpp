#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

int findIdx(const string &name);
void printTree(ofstream &out, int idx, int level);

struct Member
{
    string name;
    int age;
    string children[10];
    int numChild;
};
Member members[100];              // 宣告一陣列用來儲存家庭成員的資訊
int count = 0;                    // 統計家族有幾個成員
bool hasParentArr[100] = {false}; // 標記哪些成員有父母
int rootIdx = -1;                 // 輩分最大的人的索引

int main()
{
    ifstream infile("family.txt");
    ofstream outfile("familyTree.txt");
    string line;
    getline(infile, line);
    infile.close();

    stringstream ss(line);
    string memInfo;
    while (getline(ss, memInfo, ','))
    {

        size_t firstSlash = memInfo.find('/');
        size_t secondSlash = memInfo.find('/', firstSlash + 1);
        string name = memInfo.substr(0, firstSlash);
        members[count].name = name; // 提取名字

        string ageStr = memInfo.substr(firstSlash + 1, secondSlash - firstSlash - 1);
        members[count].age = atoi(ageStr.c_str()); // 提取年齡

        string childrenStr = memInfo.substr(secondSlash + 1); // 提取子女

        childrenStr = childrenStr.substr(1, childrenStr.size() - 2); // 去除大括號

        members[count].numChild = 0;
        if (childrenStr != "NULL")
        {
            stringstream css(childrenStr);
            string child;
            while (getline(css, child, '&'))
            {
                size_t start = child.find_first_not_of(" ");
                size_t end = child.find_last_not_of(" ");
                if (start != string::npos && end != string::npos)
                    child = child.substr(start, end - start + 1); // 提取孩子的名字

                members[count].children[members[count].numChild] = child;
                members[count].numChild++;
            }
        }
        count++;
    }

    // 標記有父母的成員
    for (int i = 0; i < count; ++i)
    {
        for (int j = 0; j < members[i].numChild; ++j)
        {
            int childIdx = findIdx(members[i].children[j]);
            if (childIdx != -1)
                hasParentArr[childIdx] = true;
        }
    }

    // 找出輩分最大的人
    for (int i = 0; i < count; ++i)
    {
        if (!hasParentArr[i])
        {
            rootIdx = i;
            break;
        }
    }

    // 輸出資訊到檔案裡
    outfile << "\"" << members[rootIdx].name << "\" (age " << members[rootIdx].age << ")\n";
    for (int i = 0; i < members[rootIdx].numChild; ++i)
    {
        int childIdx = findIdx(members[rootIdx].children[i]);
        if (childIdx != -1)
            printTree(outfile, childIdx, 1);
    }

    outfile.close();
    return 0;
}

int findIdx(const string &name)
{
    for (int i = 0; i < count; ++i)
    {
        if (members[i].name == name)
            return i;
    }
    return -1;
} // 根據名字查找成員的編號

void printTree(ofstream &out, int idx, int level)
{
    for (int i = 0; i < level; ++i)
        out << "*";
    if (level > 0)
        out << " ";
    out << "Child: \"" << members[idx].name << "\" (age " << members[idx].age << ")\n";

    for (int i = 0; i < members[idx].numChild; ++i)
    {
        int childIdx = findIdx(members[idx].children[i]);
        if (childIdx != -1)
            printTree(out, childIdx, level + 1); // 輸出下一代子女的家族樹
    }
}