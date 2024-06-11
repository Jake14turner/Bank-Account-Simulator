#include "Account.h"


Account::Account() {
    ptr = 0;
    name = "Empty";
}

Account::Account(int number, string accountName, const vector<float>& accountVector) {
    ptr = number;
    name = accountName;
    accounts = accountVector;
}

Account::Account(string accountName, float inputAmount): ptr(nextNum++) {
    name = accountName;
    accounts.push_back(inputAmount);
}


int Account::getNumber() {
    return ptr;
}

string Account::getName() {
    return name;
}

vector<float>& Account::getVector() {
    return accounts; // Return the vector
}

float Account::getBalance() {
    return accounts.back();
}

void Account::setNumber(int num) {
    ptr = num;
}

void Account::setName(string accountName) {
    name = accountName;
}

void Account::setAccounts(float amount/*vector<float>accountVector*/) {

    accounts.back() = accounts.back() + amount;

}

void Account::withdraw(float amount) {
    
    accounts.back() = accounts.back() - amount;
  

}

Account& Account::operator+=(Account& other) {
   
   Account newthing;
   newthing = other;
   
   
  /* if (*/
  other.withdraw(40);
  this->accounts.push_back(this->accounts.back() + 40);/*)*/ 
    cout << "Transfer succesful" << endl;
   
   /*
   else {
    cout << "Insufficient funds" << endl;
   }
   */
   return *this;


  // Transfer $40 from other account to this account
  /*
    const float transferAmount = 40.0;
    if (other.withdraw(transferAmount)) {
        this->accounts.back() += transferAmount;
        cout << "Transfer successful" << endl;
    } else {
        cout << "Insufficient funds" << endl;
    }
    return *this;
*/


/*
    // Transfer $40 from other account to this account
    const float transferAmount = 40.0;
    accounts.back() += transferAmount;
   // other.accounts[0] += -transferAmount;
*/
   // return *this;
}

//static variable
int Account::nextNum = 1000;