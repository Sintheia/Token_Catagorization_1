#include<iostream>
using namespace std;
int main()
{
    string s;
    cout<<"Enter = ";
    cin>>s;

    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            continue;
        }
        else
        {
            cout<<s[i]<<endl;
        }
    }
}
