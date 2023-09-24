#include<iostream>
using namespace std;
int main()
{
    string s;
    cout<<"Enter = ";
    cin>>s;

    for(int i=0;i<s.size();i++)
    {
        if(s[i]<'0' || s[i]>'9')
        {
            cout<<"Not Numeric"<<endl;
            return 0;
        }
    }
    cout<<"Numeric"<<endl;
    return 0;
}
