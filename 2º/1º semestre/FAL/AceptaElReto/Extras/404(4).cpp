#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stdio.h>
#include <math.h>
#include <string>
using namespace std;

long long counter;

map<string,int> record;

bool val(string dat)
{
    if(dat[0]=='X')
    {
        if(dat[1]=='\0')
        {
            //X
        }
        else
        {
            return false;
        }
    }
    else if(dat[0]=='I')
    {
        if(dat[1]=='I')
        {
            if(dat[2]=='I'&&dat[3]==0)
            {
                //III
            }
            else if(dat[2]==0)
            {
                //II
            }
            else
            {
                return false;
            }
        }
        else
        {
            if(dat[1]==0)
            {
                //I
            }
            else if(dat[1]=='V'&&dat[2]==0)
            {
                //IV
            }
            else if(dat[1]=='X'&&dat[2]==0)
            {
                //IX
            }
            else
            {
                return false;
            }
        }
    }
    else if(dat[0]=='V')
    {
        if(dat[1]==0)
        {
            //V
        }
        else if(dat[1]=='I')
        {
            if(dat[2]=='I')
            {
                if(dat[3]=='I'&&dat[4]==0)
                {
                    //VIII
                }
                 else if(dat[3]==0)
                 {
                    //VII
                }
                else
                {
                    return false;
                }
                
                
            }
            else if(dat[2]==0)
            {
                //VI
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        //Nothing should reach here
    }
    return true;
}

void recur(string s)
{
    if(s.length()==0)
    {
        counter++;
        return;
    }
    while(s[0]=='X')
    {
        s=s.substr(1,s.length()-1);
    }
    if(s.length()==0)
    {
        counter++;
        return;
    }
    if(record.find(s)!=record.end())
    {
        counter+=record[s];
        return;
    }

    string a,b;
    long long x;

    x=counter;
    
    for(int i=1;i<=min((int)s.length(),4);i++)
    {
        a=s.substr(i,s.length()-i);
        b=s.substr(0,i);
        if(val(b))
        {
            recur(a);
        }
    }
    record.insert(make_pair(s,counter-x));
}

int main() 
{
    string str;

    while(getline(cin,str))
    {
        counter=0;
        recur(str);
        cout<<counter<<"\n";
    }
    return 0;
}