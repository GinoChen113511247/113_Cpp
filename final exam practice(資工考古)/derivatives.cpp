#include <iostream>
#include <sstream>
using namespace std;

struct terms
{
    int coeff = 0;
    int expo = 0;
};

int exponent(int base, int expo)
{
    if (expo == 0)
        return 1;
    else if (expo == 1)
        return base;
    else
        return base * exponent(base, expo - 1);
}

// get the sop of fast exponent

int main(void)
{
    string input, temp, temp2;
    terms poly[100];
    int xValue, times;
    getline(cin, input); // review the syntax of getline
    cin >> xValue >> times;

    // main point 1:manipulation of ostringstream
    ostringstream processedInput;
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == '+' || input[i] == '-')
            processedInput << " ";
        processedInput << input[i];
    }
    input = processedInput.str();

    istringstream iss(input);
    while (times > 0)
    {
        int value = 0, size = 0;
        temp2.clear();
        for (int i = 0; i < 100; i++)
            poly[i] = {0, 0};

        while (iss >> temp)
        {
            int coeff = 0, expo = 0;

            // main point 2:find the character in a string
            size_t index = temp.find('^');
            size_t index2 = temp.find('x');
            if (index == std::string::npos)
            {
                if (index2 == std::string::npos)
                    temp += "x^0";
                else
                    temp += "^1";
            }

            for (int i = 0; i < temp.length(); i++)
            {
                if (temp[i] == 'x' || temp[i] == '^')
                    temp[i] = ' ';
            }
            istringstream iss2(temp);
            iss2 >> coeff >> expo;
            coeff *= expo;
            expo -= 1;
            if (expo >= 0)
            {
                poly[size] = {coeff, expo};
                // main point 3:the existence of to_string function
                temp2 += to_string(coeff) + "x^" + to_string(expo) + " ";
                value += coeff * exponent(xValue, expo);
                size++;
            }
        }

        // main point 4:reset the istringstream
        iss.clear();
        iss.str(temp2);
        times--;

        if (poly[0].coeff != 0 && poly[0].expo != 0)
        {
            if (poly[0].expo == 1)
                cout << poly[0].coeff << "x";
            else
                cout << poly[0].coeff << "x^" << poly[0].expo;
        }
        else if (poly[0].expo == 0)
            cout << poly[0].coeff;

        for (int i = 1; i < size; i++)
        {
            if (poly[i].expo == 0)
            {
                if (poly[i].coeff > 0)
                    cout << "+" << poly[i].coeff;
                else if (poly[i].coeff < 0)
                    cout << poly[i].coeff;
            }
            else if (poly[i].expo == 1)
            {
                if (poly[i].coeff > 0)
                    cout << "+" << poly[i].coeff << "x";
                else if (poly[i].coeff < 0)
                    cout << poly[i].coeff << "x";
            }
            else
            {
                if (poly[i].coeff > 0)
                    cout << "+" << poly[i].coeff << "x^" << poly[i].expo;
                else if (poly[i].coeff < 0)
                    cout << poly[i].coeff << "x^" << poly[i].expo;
            }
        }
        cout << endl
             << value << endl;
    }
    return 0;
}