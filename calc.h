
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

    
}

bool calc(std::string s)
{
    std::map<char, bool>tmp;
    std::vector<char>v = { '~' , '&' , '|' , 'v' , '>' , '<' , '=' , '!' , '@' };
    std::cout << "Enter your function: ";
    std::getline(std::cin, s);
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == ' ') s.erase(s.begin() + i), --i;
    }
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] != '(' && s[i] != ')' && s[i] != '~' && s[i] != '&' && s[i] != '|' && s[i] != 'v' && s[i] != '>' && s[i] != '<' && s[i] != '+' && s[i] != '=' && s[i] != '!' && s[i] != '@')
        {
            int a = 0;
            do
            {
                std::cout << "Enter the value of " << s[i] << "(0 or 1): ";
                std::cin >> a;
            } while (a != 0 && a != 1);
            tmp[s[i]] = a;
        }
    }
    while (s.length() > 1)
    {
        for (int i = 0; i < v.size(); ++i)
        {
            int l=-1;
            for (int j = 0; j < s.length(); ++j)
            {
                if (s[j] == '(') l = j;
            }
            int r = s.length();
            for (int j = 0; j < s.length(); ++j)
            {
                if (s[j] == ')')
                {
                    r = j;
                    break;
                }
            }
            for (int j = l + 1; j < r; ++j)
            {
                if (s[j] == v[i])
                {
                    bool bl;
                    if (s[j] == '~')
                    {
                        if (s[j + 1] >= '0' && s[j + 1] <= '9')
                            bl = fun(s[j], 1, s[j + 1] - 48);
                        else
                            bl = fun(s[j], 1, tmp[s[j + 1]]);
                        s[j + 1] = bl + 48;
                        s.erase(s.begin() + j);
                        j -= 1;
                        r -= 1;
                    }
                    else
                    {
                        if (s[j + 1] >= '0' && s[j + 1] <= '9')
                            bl = fun(s[j], tmp[s[j - 1]], s[j + 1] - 48);
                        else
                            bl = fun(s[j], tmp[s[j - 1]], tmp[s[j + 1]]);
                        s[j - 1] = bl + 48;
                        s.erase(s.begin() + j);
                        s.erase(s.begin() + j);
                        j -= 1;
                        r -= 2;
                    }
                }
            }
        }
        for (int i = 1; i < s.length() - 1; ++i)
        {
            if (s[i - 1] == '(' && s[i + 1] == ')')
            {
                s.erase(s.begin() + i + 1);
                s.erase(s.begin() + i - 1);
            }
        }
    }
    if (s[0]>='0' && s[0]<='9') return s[0]-48;
    else return tmp[s[0]];
}