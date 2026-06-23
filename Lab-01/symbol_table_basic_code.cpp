#include <bits/stdc++.h>

using namespace std;

struct symbolInfo
{
    string name;
    string type;
};


class symbolTable
{
    vector<symbolInfo> vec[10];

    public:

    int hashfunction(string name)
    {
        int sum=0;
        int len=name.length();
        for (int i=0; i<len; i++)
        {
            sum+=name[i];
        }
        return sum%10;
    }

    void insertt(string name, string type)
    {
        symbolInfo * ob=new symbolInfo();

        ob->name=name;
        ob->type=type;

        int hashval=hashfunction(name);

        vector<symbolInfo>v = vec[hashval];
        int flag=0;
        for(auto find=v.begin(); find!=v.end(); find++)
        {
            if(find->name==name && find->type==type)
            {
                flag=1;
                break;
            }
        }

        if (flag==1)
        {
            cout<<"Already inserted"<<endl;
        }
        else
        {
            vec[hashval].push_back(*ob);
            cout<<"Symbol inserted"<<endl;
        }
    }

    int lookup(string name)
    {
        int flag=0; //flag=0 means name does not exist in the table, if flag=1 then name exist in the table
        int hashval=hashfunction(name);
        vector<symbolInfo>v = vec[hashval];

        for(auto find=v.begin(); find!=v.end(); find++)
        {
            if(find->name==name)
            {
                flag=1;
                break;
            }
        }
        return flag;
    }


    void deletee(string name, string type)
    {
        int index=0, i=0;
        int check=lookup(name);
        if (check==0)
            cout<<"The name doesn't exist"<<endl;
        else
        {
            int hashval=hashfunction(name);
            vector<symbolInfo>v=vec[hashval];
            for(auto find=v.begin(); find!=v.end(); find++)
            {
                if(find->name==name && find->type==type)
                {
                    index=i;
                }
                i++;
            }
            vec[hashval].erase(vec[hashval].begin()+index);
            cout<<"Successfully deleted"<<endl;
        }
    }

    void print()
    {
        vector<symbolInfo>::iterator it;
        for(int i=0; i<10; i++)
        {
            cout<<i+1<<"-->";
            for(auto it:vec[i])
            {
                cout<<"<"<<it.name<<","<<it.type<<">";
            }
            cout<<endl;
        }
    }

};

int main()
{
    symbolTable s;
    s.insertt("abrar", "identifier");
    cout<<s.lookup("abrar")<<endl;
    cout<<s.lookup("wasi")<<endl;
    s.deletee("wasi", "identifier");
    s.print();
}
