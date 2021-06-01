
#include <iostream>
#include <string>
#include <map>
#include <vector>

bool fun(char ch = ' ', bool x = 0, bool y = 0)
{
    if (ch == '~')
    {
        return !y;
    }
    if (ch == '&')
        return x && y;

    if (ch == 'v')
        return x || y;
    if (ch == '|')
        return x || y;

    if (ch == '+')
        return x ^ y;

    if (ch == '=')
        return x == y;

    if (ch == '>')
        return !x || y;

    if (ch == '<')
        return x || !y;

    if (ch == '!')
        return !x && !y;

    if (ch == '@')
        return !x || !y;

    if (ch == '?')
        return 1;
     
}

bool calc(std::string str)
{
    std::map<char, bool>tmp;
    std::vector<char>v = { '~' , '&' , '|' , 'v' , '>' , '<' , '=' , '!' , '@' , '?'};
    std::cout << "Enter your function: ";
    std::getline(std::cin, str);
    for (int i = 0; i < str.length(); ++i)
    {
        if (str[i] == ' ') str.erase(str.begin() + i), --i;
    }
    for (int i = 0; i < str.length(); ++i)
    {
        if (str[i] != '(' && str[i] != ')' && str[i] != '~' && str[i] != '&' && str[i] != '|' && str[i] != 'v' && str[i] != '>' && str[i] != '<' && str[i] != '+' && str[i] != '=' && str[i] != '!' && str[i] != '@' && str[i] != '?')
        {
            int a = 0;
            do
            {
                std::cout << "Enter the value of " << str[i] << "(0 or 1): ";
                std::cin >> a;
            } while (a != 0 && a != 1);
            tmp[str[i]] = a;
        }
    }
    while (str.length() > 1)
    {
        for (int i = 0; i < v.size(); ++i)
        {
            int l=-1;
            for (int j = 0; j < str.length(); ++j)
            {
                if (str[j] == '(') l = j;
            }
            int r = str.length();
            for (int j = 0; j < str.length(); ++j)
            {
                if (str[j] == ')')
                {
                    r = j;
                    break;
                }
            }
            for (int j = l + 1; j < r; ++j)
            {
                if (str[j] == v[i])
                {
                    bool bl;
                    if (str[j] == '~')
                    {
                        if (str[j + 1] >= '0' && str[j + 1] <= '9')
                            bl = fun(str[j], 1, str[j + 1] - 48);
                        else
                            bl = fun(str[j], 1, tmp[str[j + 1]]);
                        str[j + 1] = bl + 48;
                        str.erase(str.begin() + j);
                        j -= 1;
                        r -= 1;
                    }
                    else
                    {
                        if (str[j + 1] >= '0' && str[j + 1] <= '9')
                            bl = fun(str[j], tmp[str[j - 1]], str[j + 1] - 48);
                        else
                            bl = fun(str[j], tmp[str[j - 1]], tmp[str[j + 1]]);
                        str[j - 1] = bl + 48;
                        str.erase(str.begin() + j);
                        str.erase(str.begin() + j);
                        j -= 1;
                        r -= 2;
                    }
                }
            }
        }
        for (int i = 1; i < str.length() - 1; ++i)
        {
            if (str[i - 1] == '(' && str[i + 1] == ')')
            {
                str.erase(str.begin() + i + 1);
                str.erase(str.begin() + i - 1);
            }
        }
    }
    if (str[0]>='0' && str[0]<='9') return str[0]-48;
    else return tmp[str[0]];
}