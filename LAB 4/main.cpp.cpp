#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <unordered_set>
#include <regex>
using namespace std;

void subString(string str, string *arr);
bool isKeyword(string s);
bool isOperator(string s);
bool isIdentifier(string s);
bool isSkipable(string s);
bool isConstant(string s);

int main()
{
    string str, temp;
    string arr[10] = {};
    int len = sizeof(arr)/sizeof(arr[0]);


    ifstream inputFile("Program.cpp");

    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open the file." << std::endl;
        return 1;
    }

    unordered_set<std::string> functionNames;

    regex functionRegex(R"(\b[a-zA-Z_]\w*\s+[a-zA-Z_]\w*\s*\([^)]*\)\s*\{)");


    string line;
    while (getline(inputFile, line)) {

        smatch match;
        if (regex_search(line, match, functionRegex)) {

            string matchedString = match[0];
            istringstream iss(matchedString);
            string returnType, functionName;
            iss >> returnType >> functionName;


            functionNames.insert(functionName);
        }
    }

    inputFile.close();

    cout << "Unique Function Names and their Count:" << endl;
    for (const auto& functionName : functionNames) {
        if(functionName != "main(){")
            cout << functionName << endl;
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

