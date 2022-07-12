#include<iostream>
#include<cstring>
#include<ctime>
#include<algorithm>
#include<vector>
using namespace std;
class Register{
  string name,Mobile_number,bank_account,password, PhoneNo,Name;
  float dep_money,send_money,trans_money,bank_data;
  int PaymentPin;
  int c = 0;
  vector<int>v = {385,112,468,679,100};
  const float charge = 0.5;
  public:
  void Details();
  void Login();
  void Paytm_info();
  void Transaction();
  void Payment();
  void Info_profile();
  void Show_Bill();
  void NewTranscation();
  void menu(){
      M:
      cout<<"1.Register"<<endl;
      cout<<"2.About us"<<endl;
      cout<<"3.exit"<<endl;
      int optn;
      cout<<"Enter your option: "<<endl;
      cin>>optn;
      switch(optn){
          case 1:
          Details();
          break;
          case 2:
          cout<<"app in update";
          goto M;
          break;
          case 3:
          exit(0);
          break;
          default:
          cout<<"Jarviis: error unknown input";
          goto M;
      }
  }
  
};
void Register :: Details(){
      cout<<"Welcome to cpp payment services\nProvide your info to continue further\n\t----Note: this is just a sample no need to type original details------\n"<<endl;
      cout<<"Enter Your Name: "<<endl; cin>>name;
      cout<<"Enter Your Password: "<<endl; cin>>password;
      A:
      cout<<"Enter Your Mobile Number: "<<endl; cin>>Mobile_number;
      int a = Mobile_number.size();
      if(a == 10){
          int random = rand()%v.size();
          int otp = v[random];
        cout<<"____________________\n"<<endl;
        cout<<"OTP: "<<otp<<endl;
        cout<<"____________________________________\n"<<endl;
          int new_otp;
        cout<<"enter your one-time-password: "<<endl;
        cout<<"_____________________________________\n"<<endl;
          cin>>new_otp;
          if(otp == new_otp){
              cout<<"account created successfully"<<endl;
            Login();
          }
          else{
              cout<<"Jarviis: invalid otp"<<endl;
          }
      }
          else{
              cout<<"Bhai kya kar raha hai tu.......!"<<endl;
              cout<<"Jarviis: enter correct 10-digit mobile number"<<endl;
              goto A;
          }

      }
  void Register :: Login(){
     string lname,lpassword;
        cout<<"It's time for login: \n"<<endl;
        cout<<"____________________\n"<<endl;
        cout<<"  Login"<<endl;
        cout<<"____________________\n"<<endl<<endl;
     cout<<"Enter UserName: "<<endl; cin>>lname;
     cout<<"Enter Password: "<<endl; cin>>lpassword;
     if(lname == name && lpassword == password){
         cout<<"Successfull......!";
     Paytm_info();
     }
     else{
              cout<<"Bhai kya kar raha hai tu.......!"<<endl;
         cout<<"Jarviis: invalid username or password"<<endl;
        
         
     }
     
  }
void Register :: Paytm_info(){
     cout<<"Set Your Pin: "<<endl;
     cin>>PaymentPin;
     cout<<"pin seted successfully"<<endl;
     cout<<"it's time to add some more info\n"<<endl;
     cout<<"______________________________"<<endl<<endl;
     cout<<"Enter additional information"<<endl;
     cout<<"______________________________\n"<<endl<<endl;
    cout<<"Hey "<<name<<" Enter your details "<<endl;
    cout<<"Enter you bank account number: "<<endl; cin>>bank_account;
    cout<<"Enter amount for deposit"<<endl; cin>>dep_money;
    if(dep_money == 0){
        cout<<"Bhai kya kar raha hai tu......!"<<endl;
    }
    else{
        cout<<"Money added to your account"<<endl;
        cout<<"____________________________"<<endl;
    }
        T:
        cout<<"_____________________________"<<endl<<endl;
        cout<<"Transcations and Money corner"<<endl;
        cout<<"_____________________________"<<endl<<endl;
         cout<<"1.Send Money"<<endl;
         cout<<"2.Profile"<<endl;
         cout<<"3.Create your own Wallet"<<endl;
         int option;
         cout<<"Enter your option: "<<endl; cin>>option;
         switch(option){
             case 1:
             Transaction();
             break;
             case 2:
             cout<<"Jarviis: Do your first Transaction to visit your Profile"<<endl;
             goto T;
             break;
             case 3:
             cout<<"Jarvis: App is in Update this feature will come soon."<<endl;
             goto T;
             break;
            default:
            cout<<"Jarvis: unknown input";   
             goto T;

}

}

void Register :: Transaction(){
    int b = PhoneNo.size();
    cout<<"Enter Receiver Name: "<<endl; cin>>Name;
    cout<<"Enter Phone number of receiver: "<<endl; cin>>PhoneNo;
    if(b != 10){
        cout<<"Account found"<<endl;
        cout<<"Enter money to send: "<<endl; cin>>trans_money;
        if(trans_money>dep_money){
            cout<<"Bhai kya kar raha hai tu"<<endl;
        }
        else{
            Payment();
        }
    }
    else{
        cout<<"Enter correct 10-digit Phone number"<<endl;
    }
}
void Register :: Payment(){
    cout<<"_____________________"<<endl;
    cout<<"Payment"<<endl;
    cout<<"_____________________"<<endl<<endl;
    int net_pin;
    cout<<"Enter your payment pin: "<<endl; cin>>net_pin;
    if(net_pin == PaymentPin){
        bank_data = dep_money-trans_money-charge;
        cout<<"Transcation Successfull"<<endl;
        cout<<"To check you current balance visit profile section"<<endl;
        Info_profile();

    }
    else{
        cout<<"Jarviis: Enter your pin correctly"<<endl;
    }

}
void Register :: Info_profile(){
    cout<<"_________________________"<<endl<<endl;
    cout<<"  Your Profile  "<<endl;
    cout<<"_________________________"<<endl<<endl;
    cout<<"Name: "<<name<<"\n\n"<<"PhoneNumber: "<<Mobile_number<<endl;
    cout<<"\nBank accunt no:"<<bank_account<<endl;
    Z:
    cout<<" "<<endl;
    cout<<"_________________________"<<endl<<endl;
    cout<<"1.Bank Balance"<<endl;
    cout<<"2.Know about previous Transaction"<<endl;
    cout<<"3.New Transcation"<<endl;
    cout<<"4.Back to menu"<<endl;
    cout<<"_________________________"<<endl<<endl;

    int hero;
    cout<<"Enter your option: "<<endl; cin>>hero;
   switch(hero) {
       case 1:
       int hero_pin;
       cout<<"Enter your pin: "<<endl; cin>>hero_pin;
       if(hero_pin== PaymentPin){
           cout<<"__________________________________"<<endl;
           cout<<"Your account balance is: "<<bank_data<<endl;
           cout<<"__________________________________"<<endl;
       }
       else{
           cout<<"Jarviis: Wrong Pin";
       }
       goto Z;
       break;
       case 2:
       Show_Bill();
       goto Z;
       break;
       case 3:
       NewTranscation();
       break;
       case 4:
       system("cls");
       exit(0);
       default:
       cout<<"Jarviis: Wrong input";
   }
}
void Register :: NewTranscation(){
    cout<<"__New transcation__"<<endl;
    cout<<"Enter Receiver Name: "<<endl; cin>>Name;
    cout<<"Enter Receiver PhoneNumer: "<<endl; cin>>PhoneNo;
    cout<<"Enter your amount: "<<endl; cin>>trans_money;
    if(trans_money>dep_money){
        cout<<"Bhai kya kar raha hai tu.......!";
    }
    else{
    int trans_pin;
    cout<<"Enter Your Pin: "; cin>>trans_pin;
    if(trans_pin == PaymentPin){
        cout<<"Transcation initiated.......!"<<endl;
        cout<<"Transcation successfull"<<endl;
        cout<<"Your Bank Balance update: "<<bank_data-trans_money-charge<<endl;
    }
    else{
        cout<<"Jarvis: Enter Your pin correctly"<<endl;
    }
    }
    cout<<"_________________________"<<endl<<endl;
    cout<<"1.Receipt of the current transcation"<<endl;
    cout<<"2.Exit"<<endl;
    cout<<"_________________________"<<endl<<endl;

    int choice;
    cout<<"Enter your choice: ";cin>>choice;
    switch(choice){
        case 1:
        Show_Bill();
        break;
        case 2:
        exit(0);
        break;
        default:
        cout<<"bhai kya kar raha hai tu.........!"<<endl;
        cout<<"Jarvis: Invalid input enter correct option";
    }

}
void Register :: Show_Bill(){
    cout<<"_______________________________________________"<<endl;
    cout<<" Transcation Receipt "<<endl;
    cout<<"_______________________________________________"<<endl<<endl;
    cout<<"Name: "<<name<<" | "<<"sent to | "<<" "<<"Name: "<<Name<<endl;
    cout<<"Amount: "<<trans_money<<endl;
    cout<<"Transcation_ID: idk99898731314684"<<endl;
    cout<<"Total receipt"<<endl;
    cout<<"___________________________________"<<endl<<endl;
    cout<<"final money including charges: "<<trans_money+charge<<endl;
    cout<<"___________________________________"<<endl;

}
int main(){
    cout<<"____________________"<<endl;
    cout<<"\nCPP Payment Services\t"<<endl;
    cout<<"____________________"<<endl<<endl;
    Register obj;
    obj.menu();
}