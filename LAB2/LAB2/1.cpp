#include <iostream>
#include <fstream>
#include <string>
#include <array>
using namespace std;

void subString(string str, string *arr);
bool isKeyword(string s);
bool isOperator(string s);
bool isIdentifier(string s);
bool isSkipable(string s);
bool isConstant(string s);

int main()
{
    fstream file;
    string str, temp;
    string arr[10] = {};
    int len = sizeof(arr)/sizeof(arr[0]);


    file.open("text.txt", ios ::in);

    if (file.is_open())
    {
        while (getline(file, str))
        {
        }
        file.close();
    }

    subString(str, arr);

    for (int i = 0; i < 7; i++)
    {
        if (isSkipable(arr[i]))
        {
            cout << arr[i] << " is a PUNCTUATION.\n";
        }
        else if (isKeyword(arr[i]))
        {
            cout << arr[i] << " is a KEYWORD.\n";
        }
        else if (isConstant(arr[i]))
        {
            cout << arr[i] << " is a CONSTANT.\n";
        }
        else if (isOperator(arr[i]))
        {
            cout << arr[i] << " is an OPERATOR.\n";
        }
        else if (isIdentifier(arr[i]))
        {
            cout << arr[i] << " is a VALID IDENTIFIER.\n";
        }
        
        else if (!isIdentifier(arr[i]))
        {
            cout << arr[i] << " is NOT a VALID IDENTIFIER.\n";
        }
    }
}

void subString(string str, string *arr)
{
    string subStr;
    int idx = 0;

    if (str[0] != ' ')
        str = " " + str;

    str = str + " \0";

    for (int i = 0; i < str.length();)
    {
        if (str[i] == ' ')
        {
            int j = i + 1;
            while (str[j] != ' ')
            {
                string s(1, str[i]);
                if (str[j] == '\0')
                {
                    break;
                }
                subStr.push_back(str[j]);
                j++;
            }
            arr[idx] = subStr;
            subStr.clear();
            idx++;
            i = j;
        }
    }
}

bool isKeyword(string s)
{
    string keyword[] = {"int", "float", "double", "string", "char"};

    int len = sizeof(keyword) / sizeof(keyword[0]);

    for (int i = 0; i < len; i++)
    {
        if (keyword[i] == s)
        {
            return true;
            break;
        }
    }
    return false;
}

bool isOperator(string s)
{
    string opr[] = {"+", "-", "*", "/", "%", "="};

    int len = sizeof(opr) / sizeof(opr[0]);

    for (int i = 0; i < len; i++)
    {
        if (opr[i] == s)
        {
            return true;
            break;
        }
    }
    return false;
}

bool isIdentifier(string s)
{
    if (s[0] == '_' || (s[0] >= 'a' && s[0] <= 'z') || (s[0] >= 'A' && s[0] <= 'Z'))
    {
        if (s.find("!") || s.find("%") || s.find(" ") || s.find("#") || s.find("-"))
        {
            return false;
        }
        else
            return true;
    }
    else
    {
        return false;
    }
}

bool isConstant(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[0] == '"' && s[s.length() - 1] == '"' && s.length() != 1)
        {
            return true;
        }
        if (s[0] == '\'' && s[s.length() - 1] == '\'' && s.length() != 1)
        {
            return true;
        }
        if (s[i] >= '0' && s[i] <= '9')
        {
        }
        else
        {
            return false;
        }
    }
    return true;
}

bool isSkipable(string s)
{
    string skip[] = {";", "(", ")", "{", "}", "[", "]"};

    int len = sizeof(skip) / sizeof(skip[0]);

    for (int i = 0; i < len; i++)
    {
        if (skip[i] == s)
        {
            return true;
        }
    }
    return false;
}