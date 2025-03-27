#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

struct Merchandise
{
    string kind;
    int numSold = 0;
    float price = 0.0;
};

int main()
{
    ifstream input("sales.txt");
    ofstream output("result.txt");

    int size;
    input >> size;
    Merchandise merchandise[size]; // 創一個商品的陣列
    for (int i = 0; i < size; i++)
        input >> merchandise[i].kind;
    input.ignore(1, '\n');

    float totalRevenue = 0.0;

    string temp, date, line; // 宣告temp存沒用的字串
    while (input >> temp >> date)
    {
        input.ignore(1, '\n');
        float dailyRevenue = 0.0;

        // 重置總銷量
        for (int i = 0; i < size; i++)
            merchandise[i].numSold = 0;

        while (getline(input, line))
        {
            if (line.empty() || line.find("Date") != string::npos)
                break; // 終止條件(新的日期或空行)

            istringstream iss(line);
            string kind;
            int quantity;
            float price;

            iss >> kind >> quantity >> price;

            for (int i = 0; i < size; i++)
            {
                if (merchandise[i].kind == kind)
                {
                    merchandise[i].numSold += quantity;
                    merchandise[i].price = price;
                    break;
                }
            }
        }

        output << "Sales Summary for Date " << date << ":" << endl;
        for (int i = 0; i < size; i++)
        {
            float total = merchandise[i].numSold * merchandise[i].price;
            dailyRevenue += total;
            output << merchandise[i].kind << ": " << merchandise[i].numSold
                   << " sold, Total: $" << fixed << setprecision(2) << total << endl;
        }
        output << "Daily Revenue: $" << fixed << setprecision(2) << dailyRevenue << endl
               << endl;

        totalRevenue += dailyRevenue;
    }
    output << "Total Revenue: $" << fixed << setprecision(2) << totalRevenue << endl;

    input.close();
    output.close();
    return 0;
}