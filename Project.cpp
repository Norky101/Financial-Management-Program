


// user == Y and pass == N

#include<iostream>
#include <fstream>
#include<iomanip>
#include<cmath>
#include <string>

using namespace std;

// declare function prototypes
void login();
void compoundInterest();
void menu();
void savingsCalculator(double& fd, double& he, double& ut, double& ho, double& le, double& tr, double& ed);
void currencyConverter();
void spendingTracker();
//void largestExpenditure(double& result[], int& n, int& size);

//char result;
int choice;
double fd, he, ut, ho, le, tr, ed, finalIncome;
double result[7]= {fd, he, ut, ho, le, tr, ed};


void login () //logins in regardless of result NOT WORKING
    {

        string username = "";
        string password = "";
        bool loginSuccess = false;

        cout << "Welcome to your personal finance manager\n\n\n";
        cout << "Lets login to make amendments\n\n";

        do
        {
            cout << "Enter username: \n";
            cin >> username;
            cout << "Enter password: \n";
            cin >> password;

            if (username == "Y" && password == "N") {
                cout << "Successful login\n\n";
                loginSuccess = true;
            } else {
                cout << "Incorrect username password combo\n\n";
                cout << "Please Re-Enter";
            }
        }
        while (!loginSuccess);

    }

void menu ()   //gets stuck when a none valid value is entered
    {
        do
        {
            system("clear");//clears the screen on the menu

            cout << "1. Calculate compound interest \n";
            cout << "2. Use the savings calculator\n";
            cout << "3. Use the currency converter\n";
            cout << "4. Spending tracker\n";
            cout << "5. Biggest expense\n";
            cout << "6. Quit this program\n\n";
            cout << "What would you like to do?\nPlease choose the options between 1-6 :";
            cin.clear();
            cin.ignore(100, '\n');   //clears the cin answer ( BUFFER)
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << " You have selected the 1st option ";
                    compoundInterest();
                    break;

                case 2:
                    cout << " You have selected the 2nd option ";
                    savingsCalculator(fd, he, ut, ho, le, tr, ed);
                    break;

                case 3:
                    cout << " You have selected the 3rd option ";
                    currencyConverter();
                    // test(double& fd,double& he, double& ut, double& ho, double& le , double& tr, double& ed);
                    break;

                case 4:
                    cout << " You have selected the 4th option ";
                    spendingTracker();
                    break;

                case 5:
                    cout << " You have selected the 5th option\n\n ";
                    cout << "Sorry this feature is under repair, see the Read me Doc to find out more\n\n";
                   // largestExpenditure(result[],n, size);
                    //CHECK
                    //bubbleSort(data, size)
                    //cout << "Sorted Array in Ascending Order:\n";
                  //  printArray(data, size);
                    break;

                case 6:
                    cout << " You have selected the 6th option ";
                    cout << " See you soon! ";
                    break;

                default:
                    cout << "You didnt enter a valid number between 1 to 6\n\n\n\n Try again\n";
                    menu();
                    break;
            }
        } while (choice != '6'); // loops program back to menu
    } //end of menu

void compoundInterest() // Complete
    {
        float principle, rate, time, perctRate, finalBalance,finalBalanceTwo, final, totInterest;

// asks user for input and assigns input to the variable

    cout << "How much did you invest? : ";
    cin >> principle;
    cout << "What interest rate did you receive on your investment? : ";
    cin >> rate;
    cout << "How many years will you let it grow? : ";
    cin >> time;

    // need to add in a section for compounding more than once per year

    finalBalance = principle * pow((1 + (rate/100)) , time);

    totInterest = finalBalance - principle  ;

    cout << " =========================================================================== \n\n\n ";
    // setpreciision adjusts the decimals points to your desire/removes SI notation
    cout<< fixed << showpoint <<setprecision(2);
    cout << " Your interest rate: " << rate << "%" << endl ;
    cout << " Amount of times the interest is compounded: " << time << endl ;
    cout << " Your principle investment: $" << principle << endl ;
    cout << " Total Interest: $" << totInterest <<  endl ;
    cout << " Your final compounded balance: $" << finalBalance << endl ;

    cout << " ===========================================================================\n\n\n ";
    return menu();

    }

void spendingTracker()
    {

        double income, food, health, utils, house,leisure, travel, education; //input variables

            cout << "This program will calculate your spending in each category, your income and present it.\n\n\n";

            cout << " How much do you earn each month? :"<< endl;
            cin >> income;

            cout << "How much do you spend on food per month? :"<< endl ;
            cin >>  food;

                cout << "How much do you spend on health and wellness per month? :"<< endl ;
            cin >>  health;

                cout << "How much do you spend on utilities per month? :" << endl;
            cin >>  utils;

                cout << "How much do you spend on housing/rent per month? :"<< endl ;
            cin >>  house;

                cout << "How much do you spend on leisure per month? :"<< endl ;
            cin >>  leisure;

                cout << "How much do you spend on travel per month? :" << endl;
            cin >>  travel;

                cout << "How much do you spend on education per month :" << endl;
            cin >>  education;


            //inputted amt / income * 100

            //category converted to a Percentage

            fd = ((food / income) * 100);
        he = ((health / income) * 100);
        ut = ((utils / income) * 100);
        ho = ((house / income) * 100);
        le = ((leisure / income) * 100);
        tr = ((travel / income) * 100);
        ed = ((education / income) * 100);

        savingsCalculator(fd, he, ut, ho, le, tr, ed);

            cout << "sending values to a file ...\n";

            // send values to a file
        ofstream outPutFile;
        outPutFile.open("SpendingTrackerFile.txt");

        outPutFile << "This is a list of your expenditures as a percentage:\n\n\n\n  ";
        outPutFile << "FOOD:\t" << fd <<" %" << endl;
        outPutFile << "HEALTH:\t" << he <<" %" << endl;
        outPutFile << "UTILITIES:\t" << ut <<" %" << endl;
        outPutFile << "HOUSE:\t" << ho <<" %" << endl;
        outPutFile << "LEISURE:\t" << le <<" %" << endl;
        outPutFile << "TRAVEL:\t" << tr <<" %" << endl;
        outPutFile << "EDUCATION:\t " << ed <<" %" << endl;

        outPutFile.close();

            finalIncome = income - food - health - utils - house - leisure - travel - education ;

        cout << fixed << setprecision(2);
            cout << " =========================================================================== "  << endl << endl<< endl;

            cout << "This is your expenditure report\n\n\n" ;

            cout << "Percentage each month spent on... \t\t\t\tFood :"<< fd << "%" << endl;
            cout << "Percentage each month spent on... \t\t\t\tHealth and Wellness :" << he << "%" << endl;
            cout << "Percentage each month spent on... \t\t\t\tUtilities :"<< ut << "%" << endl;
            cout << "Percentage each month spent on... \t\t\t\tHousing :"<< ho << "%" << endl;
            cout << "Percentage each month spent on... \t\t\t\tLeisure :"<< le << "%" << endl;
            cout << "Percentage each month spent on... \t\t\t\tTravel :"<< tr << "%" << endl;
            cout << "Percentage each month spent on... \t\t\t\tEducation :"<< ed << "%" << endl<< endl<< endl;

            cout << " Your final income after your expenditures is: $" << finalIncome << endl;

            cout << " =========================================================================== "  << endl << endl<< endl;

    }   //Complete

void savingsCalculator(double& fd,double& he, double& ut, double& ho, double& le, double& tr, double& ed )
    {
    // values passed by reference
        cout << fixed << setprecision(2);
        //cout<< fd<<endl<<he<<endl<<ut<<endl<<ho<<endl<<le<<endl<<tr<<endl<<ed<<endl<< endl<< endl;

        cout<< "Lets loop through an array\n";

        double result[7]= {fd, he, ut, ho, le, tr, ed};
        for (int i = 0; i < 7; i++) {
            cout << "%"<< result[i] << "\n";
        }
    }
/*
    void bubbleSort(int array[], int size)
    {

        // loop to access each array element
        for (int step = 0; step < size; ++step)
        {

            // loop to compare array elements
            for (int i = 0; i < size - step; ++i)
            {

                // compare two adjacent elements
                // change > to < to sort in descending order
                if (array[i] > array[i + 1])
                {

                    // swapping elements if elements
                    // are not in the intended order
                    int temp = array[i];
                    array[i] = array[i + 1];
                    array[i + 1] = temp;
                }
            }
        }
    }

    // print array
    void printArray(int array[], int size)
    {
        for (int i = 0; i < size; ++i)
        {
            cout << "  " << array[i];
        }
            cout << "\n";
    }

    */

class Currency
    {
        private:
            string country, symbol;
            double value;

        public:
            //constructor
            Currency (string c = "n/a", string s = "n/a", double  v = 0.00)  //default results ( Constructor)
            {
                country = c;
                symbol = s;
                value = v;
            }
            //member functions

            string getCountry()
            {
                return country;
            }

            ///////

            string getSymbol()
            {
                return symbol;
            }

            ///////

            double getValue()
            {
                return value;
            }

    };

void currencyConverter()
    {

    cout << " All currencies are compared against 1 United States Dollar (USD)" << endl << endl;

        cout<< fixed << showpoint <<setprecision(2);

        Currency USD("United States of America", "USD", 1.00);
        cout << USD.getCountry() << endl << USD.getSymbol() << endl << USD.getValue() << endl<< endl;

        Currency GBP("Great Britain", "GBP", 0.78);
        cout << GBP.getCountry() << endl << GBP.getSymbol() << endl << GBP.getValue() << endl<< endl;

        Currency AUD("Australia", "AUD", 1.38);
        cout << AUD.getCountry() << endl << AUD.getSymbol() << endl << AUD.getValue() << endl<< endl;

        Currency EUR("Europe", "EUR", 0.93);
        cout << EUR.getCountry() << endl << EUR.getSymbol() << endl << EUR.getValue() << endl<< endl;

        Currency RUS("Russia", "₽", 77.38);
        cout << RUS.getCountry() << endl << RUS.getSymbol() << endl << RUS.getValue() << endl<< endl;

        Currency JPY("Japan", "JPY", 128.68);
        cout << JPY.getCountry() << endl << JPY.getSymbol() << endl << JPY.getValue() << endl<< endl;


        cout << " USD/GBP:  " << USD.getValue() << "/" << GBP.getValue() << endl << endl;
        cout << " USD/AUD:  " << USD.getValue() << "/" << AUD.getValue() << endl << endl;
        cout << " USD/EUR:  " << USD.getValue() << "/" << EUR.getValue() << endl << endl;
        cout << " USD/₽:  " << USD.getValue() << "/" << RUS.getValue() << endl << endl;
        cout << " USD/JPY:  " << USD.getValue() << "/" << JPY.getValue() << endl << endl;

    }

int main()
    {

        cout<< "THIS IS NOT A REAL FINANCIAL APP. DO NOT ENTER ANY PERSONAL DATA. THANK YOU\n\n";
        cout << "Find the login info in the read me file.\n";

        login();

        menu();

        return 0;
    }
