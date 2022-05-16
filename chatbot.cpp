#include<bits/stdc++.h>
using namespace std;
//CHAT BOT 
void chatbot()
{
	map<string,vector<string>> mp;
	mp["whom I am talking to?"] = {"Hi, this is SmartBot 4.0","May I know your name?"};
    
}
void option()
{
    cout<<"Hi, this is SmartBot 4.0"<<endl;
    sleep(3);
    cout<<"May I know your name?"<<endl;
    sleep
    string name;
    cout<<"--------------------------------------|"<<endl;
    cin>>name;
    cout<<"--------------------------------------|"<<endl;
    cout<<"hi, "<<name<<" How can I help you!"<<endl;
    cout<<" -------------------------------------------------------------"<<endl;
    cout<<"|                   FREQUENTLY ASKED QUESTIONS                |"<<endl;
    cout<<"| Q1. Why it is showing transaction pending?                  |"<<endl;
    cout<<"| Q2. Will I lost my money?                                   |"<<endl;
    cout<<"| Q3. How many days it will take to transfer the money        |"<<endl;
    cout<<" -------------------------------------------------------------"<<endl;
    int x=10;
    while (x!=0)
    {
        cin>>x;
        cout<<"press 4 to show the queries"<<endl;
        switch (x)
        {
        case 1:
            cout<<"It can happened due to various reasons like your Bank Server is busy or not responding and maybe receiver's bank is taking extra time"<<endl;
            break;
        case 2:
            cout<<"No you won't lose your money, UPI is direct bank to bank transaction, so even if transaction fails, your money will be refunded to you within 7 days"<<endl;
            break;
        case 3:
            cout<<"Normally it takes 2 days but in some cases it can take upto 7 days and money will either refunded to you or it will reach the receivers account"<<endl;
            break;
        case 4:
            cout<<" -------------------------------------------------------------"<<endl;
            cout<<"|                   FREQUENTLY ASKED QUESTIONS                |"<<endl;
            cout<<"| Q1. Why it is showing transaction pending?                  |"<<endl;
            cout<<"| Q2. Will I lost my money?                                   |"<<endl;
            cout<<"| Q3. How many days it will take to transfer the money        |"<<endl;
            cout<<" -------------------------------------------------------------"<<endl;
            break;
        }
    }
    cout<<name, "I hope I have cleared your queries and thank you for using this app."<<endl;
    

}
int main()
{
    cout<<"*********************************************"<<endl;
    cout<<"|          WELCOME TO SMARTCHAT             |"<<endl;
    cout<<"*********************************************"<<endl;
    string entry = "in";
    string input="";
    int x;
    while(input!="out" || x!=0)
    {
        cout<<"wanna type manually or want options?"<<endl;
        cout<<"Press 1 for options"<<endl;
        cout<<"Press 2 for manual"<<endl;
        cin>>x;
        switch (x)
        {
        case 1:
            option();
            break;
        case 2:
            manual();
        default:
            break;
        }
        
    }
    
}