#include "Account.h"
#include "Project3.h"





    

int main() {



int decision;

choice outcome;

bool thatt = true;
bool continuee = true;

bool newBool = true;
    bool newBool2 = true;

    Account target;
    Account source;

int k = 0;
int z = 0;

Account newAccount;
string namee;
float amount;
float numberr;
float number2;

cout << "+--------------------------------------------------------------------------+" << endl;
cout << "|                     Computer Science and Engineering                     |" << endl;
cout << "|                    CSCE 1040 - Compute Programming II                    |" << endl;
cout << "|    Jacob Turner              JMT0497          jacobturner6@my.unt.edu    |" << endl;
cout << "+--------------------------------------------------------------------------+" << endl;


vector<Account>bankAccounts;



do{

cout << "***************** M E N U ****************" << endl;
cout << "| Open new account (1)                   |" << endl;
cout << "| Deposit into account (2)               |" << endl;
cout << "| Withdraw from account (3)              |" << endl;
cout<<  "| Quick transfer 40$ (4)                 |" << endl;
cout << "| Print a list with all accounts (5)     |" << endl;
cout << "| End transaction (6)                    |" << endl;
cout << "******************************************" << endl;


    //get the users decision
cin >> decision;
//convert this varible in to the enum type for switch case
outcome = static_cast <choice> (decision);

switch(outcome) {
case 1: 
   //open new account
  
  
  cout << "What is the name for the new account: ";
  cin.ignore();

  getline(cin, namee);
  
  cout << "How much will be deposited: ";
  cin >> amount;

  bankAccounts.push_back(Account(namee, amount));

  cout << "Account details: " << endl <<"Account number: " << bankAccounts.back().getNumber() << endl << "Account name: " << namee << endl << "Account balance: " << fixed << setprecision(2) << amount << endl << endl;


    break;


case 2:
  //deposit into account

//read in account number
cout << "Please enter the account number that you would like to deposit into: ";
cin >> numberr;
for(int i = 0; i < bankAccounts.size(); i++)    {
    if(numberr == bankAccounts[i].getNumber()) {
        thatt = false;
        cout << "Account Found" << endl;
        cout << "Please enter the name for the account: ";
        cin.ignore();
        getline(cin, namee);
        if(namee == bankAccounts[i].getName()) {
            cout << "How much would you like to deposit: ";
            cin >> number2;
            bankAccounts[i].setAccounts(number2);
            cout << "New balance: " << bankAccounts[i].getBalance() << endl;
        }
        else {
            cout << "You entered the incorrect name." << endl;
            }
    }
   
}
    if(thatt == true) {
        cout << "You did not enter a valid account number." << endl;
    }

    break;

case 3:
  //withdraw from account

    cout << "Enter the account number for the account to withdraw: ";
    cin >> numberr;
    cout << endl;

    for(int i = 0; i < bankAccounts.size(); i++)    {
        if(numberr == bankAccounts[i].getNumber()) {
            thatt = false;
            cout << "Account Found" << endl;
            cout << "Please enter the name for the account: ";
            cin.ignore();
            getline(cin, namee);
            cout << endl;
            if(namee == bankAccounts[i].getName()) {
                cout << "How much would you like to withdraw: ";
                cin >> number2;
                if(number2 > bankAccounts[i].getBalance()) {
                    cout << "Insufficient funds to withdraw." << endl;
                }
                else {
                    bankAccounts[i].withdraw(number2);
                    cout << "Funds withdrawn, remaining balance is: " <<  bankAccounts[i].getBalance() << endl;
                }
            }
            else {
                cout << "You entered an invalid name." << endl;
            }
        }
    }

     if(thatt == true) {
        cout << "You did not enter a valid account number." << endl;
    }

    break;

case 4:
    //quick transfer 40$
    int sourceAcct;
    int targetAcct;
    
    cout << "Enter the account you want to take money from: ";
    cin >> sourceAcct;
    cout << endl << "Enter the account you would like to add money to: ";
    cin >> targetAcct;
    cout << endl;

    Account* sourceAcctt;
    Account* targetAcctt;

    for(auto& act : bankAccounts) {
        if(act.getNumber() == sourceAcct) {
            sourceAcctt = &act;
        }
        else  if(act.getNumber() == targetAcct){
            targetAcctt = &act;
        }
    }

    if(sourceAcctt && targetAcctt) {
        *targetAcctt += *sourceAcctt;
    }



    /*

    cout << "Please enter the account number you would like to send the money to: ";
    cin >> targetAcct;

    for(int i = 0; i < bankAccounts.size(); i++)    {
        if(targetAcct == bankAccounts[i].getNumber()) {
            newBool2 = false;
            cout << "Target Account Found" << endl;
            target = bankAccounts[i];

            z = z + 1;
            
        }
    }

    cout << endl << "Please enter the account number you would like to send the money from: ";
    cin >> sourceAcct;

    for(int i = 0; i < bankAccounts.size(); i++)    {
        if(sourceAcct == bankAccounts[i].getNumber()) {
            newBool = false;
            cout << "Source Account Found" << endl;
            source = bankAccounts[i];
            k = k + 1;
            
        }
        
    }
    cout << "Target account: " << target.getName() << endl;
    cout << "Source account: " << source.getName() << endl;

    if(newBool == true) {
        cout << "You entered an invalid bank number for the source account." << endl;
    }
    if(newBool2 == true) {
        cout << "You entered an invalid bank number for the target account." << endl;
     }

    if(newBool == false && newBool2 == false) {
        bankAccounts[k] += bankAccounts[z];
        newBool = true;
        newBool2 = true;
    }

k = 0;
z = 0;
*/
    break;

 
case 5: 
     //print all accounts
    cout << "+------------------------------------------------+" << endl;
    cout << "| Acct Number |      Name         | Balance      |" << endl;
    cout << "+------------------------------------------------+" << endl;
    for(int i = 0; i < bankAccounts.size(); i++) {
    cout << "|    " << bankAccounts[i].getNumber() << "            " << bankAccounts[i].getName() << "              " << bankAccounts[i].getBalance() << "|" << endl;
    }

   break;

case 6:
 //exit
    cout << "You have selected to exit, bye." << endl;
    //set the variblae in the while part of the loop false and it will exit the loop
    continuee = false;
    break;



default:

    cout << "please enter a valid option." << endl;
    break;
}

}
while(continuee);


}
