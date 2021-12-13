#include <iostream>
#include <string.h>
#include <stdlib.h>
#include<ctime>

using namespace std;

class car
{
private:
    char *car_name, *manufacturer, *model;
    float *price;
    int *stock;

public:
    car()
    {
        car_name = new char[20];
        manufacturer = new char[20];
        model = new char[20];
        price = new float;
        stock = new int;
    }
    void feeddata(char[], char[]);
    void feeddataO(char[], char[]);
    void editdata();
    void showdata();
    int getIndex(int i, char[], char[]);
    int search(char[], char[]);
    void buycar();
};
/*int car:: getIndex(int i,char n[20],char m[20])
{
      if((strcmp(car_name,c_name)==0)&& (strcmp(model,m_name)==0))
      return 1;
   return 0;
}*/

void car::feeddataO(char n[20], char m[20])
{
    // cin.ignore();

    int k;
    cout << "\nEnter number of cars you're adding to collection: ";
    cin >> k;
    *stock = *stock + k;
    cout << "\n"
         << k << " Cars added to showroom and updated stock of car: " << car_name << " is " << *stock;
    return;
}
void car::feeddata(char n[20], char m[20])
{
    //cin.ignore();
    car_name = n;
    model = m;
    cout << "\nThis car is new to store...";
    cout << "\nEnter manufacturer: ";
    cin.getline(manufacturer, 20);
    cout << "\nEnter price: ";
    cin >> *price;
    cout << "\nEnter number of cars to be added: ";
    cin >> *stock;
}

void car::editdata()
{

    cout << "\nEnter car name: ";
    cin.getline(car_name, 20);
    cout << "\nEnter model number: ";
    cin.getline(model, 20);
    cout << "\nEnter manufacturer: ";
    cin.getline(manufacturer, 20);
    cout << "\nEnter price: ";
    cin >> *price;
    cout << "\nEnter stock position: ";
    cin >> *stock;
}

void car::showdata()
{

    cout << "\nCurrent stock of " << car_name << " with model number: '" << model << "' is " << *stock;
    cout << "\nManufacturer: " << manufacturer;
    cout << "\nPrice: " << *price;
}

int car::search(char cbuy[20], char mbuy[20])
{
    if ((strcmp(cbuy, car_name) == 0) && (strcmp(mbuy, model) == 0))
        return 1;
    else
        return 0;
}

void car::buycar()
{
    int count;
    cout << "\nEnter Number of Cars to buy: ";
    cin >> count;
    if (count <= *stock)
    {
        *stock = *stock - count;
        cout << "\nCar bought Succesfully";
        cout << "\nAmount: Rs. " << (*price) * count;
    }
    else
        cout << "\nRequired number (" << count << ") of cars " << car_name << " of model: "
             << model << " not available in stock.";
}




class login : public car
{
private:
    char *password, *user;

public:
    login()
    {
        password = new char[20];
        user = new char[20];
    }
    void setPassword();
    void changePassword();
    int searchP(char[]);
    int checkPassword();
};

void login::setPassword()
{
    cout << "\nEnter user name: ";
    cin.getline(user, 20);
    cout << "\nEnter password: ";
    cin.getline(password, 20);
    cout << "\nYou're registered succesfully! Now login for further actions.";
}
void login::changePassword()
{
    cout << "\nEnter current password: ";
    char *pass1 = new char[20];
    cin.getline(pass1, 20);
    if (strcmp(pass1, password) == 0)
    {
        cout << "\nEnter new password: ";
        cin.getline(password, 20);
        cout << "\nYour password have been changed succesfully: ";
    }
    else
    {
        cout << "\nCurrent password not correct! Try again..";
    }
}
int login::checkPassword()
{
    char *pass2 = new char[20];
    cout << "\nEnter Password: ";
    cin.getline(pass2, 20);
    if (strcmp(pass2, password) == 0)
    {
        cout << "\nLogin Succesful!";
        return 1;
    }

    else
        cout << "\nPassword incorrect,Try again!";
    return 0;
}
int login::searchP(char userN[20])
{
    if (strcmp(userN, user) == 0)
        return 1;
    else
        return 0;
}

class utility: public login{ 
public:
void rent();
void garage();
void login_utility(login *log[], int &l, car *B[]);
};


char userN[20];
int  i = 0;


int main()
{
    car *B[100];    //100 cars can be placed here in the store
    login *log[20]; //20 employees can work most
    int l = 0;
    int r, t, choice;
    char namebuy[20], modelbuy[20], passN[20];
    utility temp;
    while (1)
    {
        cout << "\n\n\t\tWelcome to RideSure!, Please choose an option: "
             << "\n1. Rent a car"
             << "\n2. Buy car"
             << "\n3. Check for car"
             << "\n4. Register/login as employee"
             << "\n5. Want a repair"
             << "\n6. Exit\n";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
        {
            //CAR RENTING SYSTEM TO BE DESIGNED
            temp.rent();
            break;
        }
        case 2:
        {
            if (i == 0)
            {
                cout << "\nStore is Empty";
            }
            else
            {   
              cout<<"\nCurrent selection of cars in the showroom: \n";			
 			  for (t = 1; t <= i; t++)
                { B[t] ->showdata();
                    cout<<endl;
                }
                cout<<"------------------------------------";
                cout << "\nEnter name of car you wish to buy: ";
                cin.getline(namebuy, 20);
                cout << "\nEnter model number: ";
                cin.getline(modelbuy, 20);
                int z = i + 1;
                for (t = 0; t <= i; t++)
                {
                    if ((B[t]->search(namebuy, modelbuy)))
                    {
                        z = t;
                        B[t]->buycar();
                        break;
                    }
                }
                if (z > i)
                    cout << "\nThis Car is not in stock.";
            }
            break;
        }
        case 3:
        {
            if (i == 0)
                cout << "\nStore is empty";
            else
            {   
                cout << "\nEnter name of car: ";
                cin.getline(namebuy, 20);
                cout << "\nEnter Model number: ";
                cin.getline(modelbuy, 20);
                int r = i + 1;
                for (t = 0; t <= i; t++)
                {
                    if (B[t]->search(namebuy, modelbuy))
                    {
                        r = t;
                        break; 
                    }
                }
                if (r < i + 1)
                {
                    B[r]->showdata();
                }
                else
                {
                    "\nThis car is not in stock! Please enter the car's full name in case of descrepency.'";
                }
            }
            break;
        }
        case 4:
        {   temp.login_utility(log, l, B);
            break;
        }
        case 5:
        {   
            temp.garage();
            break;
        }
        case 6:
        {
            exit(0);
        }
        default:
            cout << "\nPlease select a valid option!";
        }
    }
}


void utility::rent(){
	cout << "\nWelcome to RideSure,Safety with pace.";
            string cv;
            int ride;
            cout << "\nPlease enter the approximate fare of ride (in KM): ";
            cin >> ride;
            int am;
            if (ride < 10)
                am = (rand() % 10) * (rand() % 5) * ride;
            else
                am = (rand() % 15) * (rand() % 7) * ride;
            cout << "\nIs this your first ride on RideSure(Y/N)? ";
            cin >> cv;
            if (cv == "Y" || cv == "y")
            {
                cout << "\nCongratulations you're now eligible for Rs." << am / 10 << " discount...";
                am = am - am / 10;
            }
            cout << "\nProceed to pay Rs." << am;
            cout << "\nThanks! Travel with us again.";
            
}

void utility::garage(){
cout << "\nWelcome to Garage section of RideSure!";
            cout << "\nWas this car brought from RideSure?(Y/N)";
            char b;
            cin >> b;
            int date = 0;
            if (b == 'Y'||b=='y')
                cout << "\nCongratulations you're eligible for Rs.100 discount";
            time_t now = time(0);
            char* date_time = ctime(&now);
            cout<<"\nThe current date is: "<<date_time<<"\n";
            cout<<"What date would you like to bring the car into the garage? (Enter day of the month):";
            cin>>date;
            if (date>31){
            	cout<<"Please enter a valid date.";
			}
            cout << "\nYour appointement fee to be paid is Rs." << rand() % 100;
            cout << "\nThank you! Visit Again!";
}


void utility::login_utility(login *log[], int &l, car *B[]){
	 int choice2;
            cout << "\n\t\tSelect an option: "
                 << "\n1.Register"
                 << "\n2.Login"
                 << "\n3.Exit\n";

            cin >> choice2;
            cin.ignore();
            switch (choice2)
            {
            case 1:
            {
                log[l] = new login;
                log[l]->setPassword();
                l++;
                break;
            }
            case 2:
            {
  cout << "\nEnter user name(Unique): ";
                cin.getline(userN, 20);
                int y = l + 1;
                for (int t = 0; t < l; t++)
                {
                    if (log[t]->searchP(userN))
                    {
                        y = t;
                        break;
                    }
                }
                if (y >= l + 1)
                {
                    cout << "\nNo such Person with user name '" << userN << "' exitsts. Try again!";
                    break;
                }
                else
                {
                    int x = log[y]->checkPassword();
                    if (x)
                    {
                        cout << "\nWelcome! You've been verified as an employee of the store. Choose an option: ";

                        int choice3;
                        cout << "\nChoose an option: \n1.Add cars to store.\n2.Exit\n";
                        cin >> choice3;
                        cin.ignore();
                        switch (choice3)
                        {
                        case 1:
                        {

                            if (i == 0)
                                B[i] = new car;
                            //case 1: store already have some of car

                            char *c_name = new char[20];
                            char *m_name = new char[20];

                            cout << "\nEnter car name: ";
                            cin.getline(c_name, 20);
                            cout << "\nEnter model number: ";
                            cin.getline(m_name, 20);

                            int z = i;
                            for (int b = 0; b < i; b++)
                            {
                                if (B[b]->search(c_name, m_name))
                                {
                                    z = b;
                                    break;
                                }
                            }
                            if (z < i)
                                B[z]->feeddataO(c_name, m_name);
                            // case 2: car is new
                            else
                            {
                                i++;
                                B[i] = new car;

                                B[i]->feeddata(c_name, m_name);
                            }

                            break;
                        }
                        case 2:
                            break;
                        default:
                            cout << "\nPlease choose a valid option.";
                        }
                    }
                }
                break;
            }
            case 3:
                break;

            default:
                cout << "\nPlease select valid option!";
            }
}
