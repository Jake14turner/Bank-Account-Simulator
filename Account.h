#ifndef Account_h
#define Account_h

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Account {
    private:

    int ptr; //canvas said pointer was not required, so just using a regular int.
    string name;
    vector<float>accounts;

    public:

    Account(); //default constructor
    Account(string accountName, float inputAmount);
    Account(int number, string accountName, const vector<float>& accountVector); //overloaded constructor
    //~Account(); //destructor
    //accesors
    int getNumber();
    string getName();
    vector<float>& getVector();
    float getBalance();
    //mutators
    void setNumber(int num);
    void setName(string accountName);
    void setAccounts(float amount/*vector<float>accountVector*/);
    void withdraw(float amount);

     Account& operator+=(Account& other);
  
    static int nextNum;


};

#endif