#include <iostream>
#include <string>
#include "data_structures/stack.cpp"

using namespace std;

//Importing data from the user
string importData();
//Expression validation
bool expressionIsValid(string data,Stack<char> &stackData);

int main()
{
    //User insert data
    string data = importData();
    int n = data.length();

    //Create stack
    Stack<char> stackData(n);

    //Expression validation
    bool ret;
    ret = expressionIsValid(data,stackData);
    cout<<"\n\nValid = 1|Not valid = 0\n\nResult: "<<ret<<endl;

    return 0;
}

string importData()
{
    cout<<"Please enter some math expression:"<<endl;
    string data;
    getline(cin,data);
    return data;
};

bool expressionIsValid(string data, Stack<char> &stackData)
{
    for(int i = 0 ; i < data.length() ; i++)
    {
        if(data[i] == '{' || data[i] == '(' || data[i] == '[')
        {
            stackData.push(data[i]);
            continue;
        }

        if(data[i] == '}' || data[i] == ')' || data[i] == ']')
        {
            if(stackData.isEmpty())
            {
                return false;//Stack is empty, no opened brackets, example ] or ) or }
            }

            if(stackData.getTop() == '(' && data[i] == ')')
            {
                stackData.pop(); //()
                continue;
            }

            if(stackData.getTop() == '[' && data[i] == ']')
            {
                stackData.pop();//[]
                continue;
            }

            if(stackData.getTop() == '{' && data[i] == '}')
            {
                stackData.pop();//{}
                continue;
            }

            return false;//Example [} or (] or etc..
        }
    }
    return stackData.isEmpty();
};
