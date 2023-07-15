#include<bits/stdc++.h>
using namespace std;

class bank
{
    protected:
    string name;
    int age;
    int account_number;
    float balance;
    public:
    bank(string name,int age,int account_number,float balance):name(name),age(age),account_number(account_number),balance (balance){}

       int getAccountNumber()const
        {
            return account_number;
        }
        string getName() const
        {
            return name;
        }
        int getAge()const
        {
            return age;
        }
        float getBalance()const
        {
            return balance;
        }
        void setBalance(float updatebalance)
        {
            balance=updatebalance;

        }





};
class open_close :public  bank {
  protected:
      vector<bank> account;


  public:


     open_close(string name,int age,int account_number,float balance):bank(name,age,account_number,balance){}
      void open_account()
    {


         if(age>=18){
        account_number = rand() % 90000 + 10000;
       balance=0.0;

         bank A1( name, age,account_number,balance);
        cout<<"-------------------------------"<<endl;
        cout<<"YOUR ACCOUNT IS OPENED SUCCESSFULLY\n";

       account.push_back(A1);

        cout<<"YOUR ACCOUNT IS CREATED .YOUR ACCOUNT DETAILS"<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"|ACCOUNT     DETAILS "<<endl;
        cout<<"|NAME: "<< getName()<<endl;
        cout<<"|AGE: " << getAge() << endl;
        cout<<"|ACCOUNT NUMBER: "<< getAccountNumber()<<endl;
        cout<<"|BALANCE: "  << getBalance()<< endl;
        cout<<"--------------------------------"<<endl;
        }
        else
        {
            cout<<"                           SORRY YOUR AGE LIMIT IS BELOW 18 .YOU ARE NOT ELIGIBLE!!!!!"<<endl;
        }
              cout<<"--------------------------------------------------------------------------------------"<<endl;
        }


        void close_account(int account_number)
        {

        for (auto it = account.begin(); it != account.end(); ++it) {
            if (it->getAccountNumber() ==account_number) {
                account.erase(it);
                cout << "****************************ACCOUNT IS CLOSED***************************************" << endl;
                 return;
            }
        }

        cout << "************************************ACCOUNT NOT FOUND*************************************** "<< endl;

        }

         vector<bank>& getAccount()  {
        return account;
        }





};
class DisplayAccount {
private:
     vector<bank>& account;

public:
    DisplayAccount( vector<bank>& account)
        : account(account) {}

   void display(int account_number) {
    for (auto it = account.begin(); it != account.end(); ++it) {
        if (it->getAccountNumber() == account_number) {
                      cout<<"-------------------------------"<<endl;
                      cout<<"|ACCOUNT     DETAILS "<<endl;
                      cout<<"|NAME: "<< it->getName()<<endl;
                      cout<<"|AGE: " << it->getAge() << endl;
                      cout<<"|ACCOUNT NUMBER: "<< it->getAccountNumber()<<endl;
                      cout<<"|BALANCE: "  << it->getBalance()<< endl;
                      cout<<"--------------------------------"<<endl;
                      return;

    }

    }


             cout << "                                    ACCOUNT NOT FOUND                                  " << endl;
    }
};
class DepositAccount
{
protected:
    vector<bank>&account;
    public:
    DepositAccount( vector <bank>&account):account(account){}
    void deposit(int account_number)
    {
        for (auto it = account.begin(); it != account.end(); ++it)
          {
              if(it->getAccountNumber()==account_number){

        cout<<"***********************************ENTER THE AMOUNT YOU WANT TO DEPOSIT********************\n";
        float amount;
       cout<<"                                           "; cin>>amount;
       float currentbalance= it->getBalance();
       float updatebalance=currentbalance+amount;
       (*it).setBalance(updatebalance);
       cout<<"************************************YOUR AMOUNT IS DEPOSITED YOUR BALANCE IS="<<it->getBalance()<<"************"<<endl;
        return;
      }

          }
          cout<<"                                         ACCOUNT NUMBER DO NOT MATCH\n";
          }

};
class WithdrawAccount
{
protected:
    vector<bank>&account;
    public:
    WithdrawAccount( vector <bank>&account):account(account){}

    void withdraw(int account_number)
    {
        for (auto it = account.begin(); it != account.end(); ++it)
          {
              if(it->getAccountNumber()==account_number){

        cout<<"*************************ENTER THE AMOUNT YOU WANT TO WITHDRAW****************\n";
        float amount;
        cout<<"                                         ";cin>>amount;
        if(it->getBalance()>=amount){
       float currentbalance= it->getBalance();
       float updatebalance=currentbalance-amount;
       (*it).setBalance(updatebalance);
         cout<<"************************YOUR AMOUNT IS WITHDRAWN YOUR BALANCE IS="<<it->getBalance()<<"***************************"<<endl;
        }
        else
            cout<<"*********************YOU HAVE INSUFFICIENT BALANCE**************************************\n";
        return;
      }

          }
        cout<<"************************ACCOUNT NUMBER DO NOT MATCH********************************************\n";
          }

};




int main()
{
    open_close A1("",0,0,0.0);


cout<<"                                   DO YOU WANT TO START THE SOFTWARE.IF YES PRESS 1 ELSE 0"<<endl;
int start;
cin>>start;
while(start){
        cout<<"------------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"|**************************************DO YOU HAVE A BANK ACCOUNT?*****************************************|"<<endl;
        cout<<"|**************************************IF YES, PRESS 1 IF NO PRESS 0***************************************|"<<endl;
        cout<<"|**************************************IF YOU WANT TO LOG OUT OF THE SYSTEM ,PRESS2************************|"<<endl;
        int press;;
       cin>>press;
        cout<<"------------------------------------------------------------------------------------------------------------"<<endl;
        system("cls");
        if(press==0)
        {
          string name;
         int age;
          cout<<"----------------------------"<<endl;
          cout<<"|ENTER YOUR NAME            |"<<endl;
          cout<<" ";cin.ignore();  getline(cin,name);
          cout<<"|ENTER YOUR AGE             |" <<endl;
          cout<<" ";  cin>>age;
          cout<<"----------------------------|"<<endl;
system("cls");
A1=open_close(name,age,0,0.0);
A1.open_account();
        }
        else if(press==1){
while(1){

         cout<<"|----------------------------------------------------------------------------------------------------------|"<<endl;
         cout<<"|*************************************DO YOU WANT TO CLOSE YOUR BANK ACCOUNT.PRESS 2***********************|"<<endl;
         cout<<"|*************************************DO YOU WANT TO DISPLAY  YOUR BANK ACCOUNT DETAILS.PRESS 3************|"<<endl;
         cout<<"|*************************************DO YOU WANT TO DEPOSIT FROM YOUR BANK ACCOUNT.PRESS 4****************|"<<endl;
         cout<<"|*************************************DO YOU WANT TO WITHDRAW FROM YOUR BANK ACCOUNT.PRESS 5********* *****|"<<endl;
         cout<<"|*******************************DO YOU WANT TO LOG OUT OF YOUR ACCOUNT ,PRESS 0****************************|"<<endl;
         cout<<"|----------------------------------------------------------------------------------------------------------|"<<endl;

int key ;
cin>>key;
system("cls");
if(key==0)
{
    break;
}

else if  (key==2)
{
    cout<<"*************************ENTER YOUR ACCOUNT NUMBER TO CLOSE YOUR BANK ACCOUNT**********"<<endl;
    int account_number;
    cout<<"                                        ";cin>>account_number;

    A1.close_account(account_number);

}
else if (key==3)
{
     cout<<"*******************************ENTER YOUR ACCOUNT NUMBER******************************\n";
 int account_number;
 cout<<"                                        ";    cin>>account_number;



                DisplayAccount D(A1.getAccount());
                D.display(account_number);
                ///system("cls");

}
else if (key==4)
{
 cout<<"***********************************ENTER YOUR ACCOUNT NUMBER*****************************\n";
 int account_number;
 cout<<"                                          ";  cin>>account_number;
 DepositAccount De(A1.getAccount());

 De.deposit(account_number);

}
else if (key==5)
{
 cout<<"*******************************ENTER YOUR ACCOUNT NUMBER******************************\n";
 int account_number;
 cout<<"                                        ";    cin>>account_number;
 WithdrawAccount W(A1.getAccount());

 W.withdraw(account_number);


}
else if (key==0)
    break;
}
}
else if (press==2)
    break;
}
}



