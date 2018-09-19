//File Name: assign1_jla160.cpp
//
//Author: Jakob Arsement
//Date: 8/23/2018
//Assignment Number: 1
//CS 2308.004 Fall 2018
//Instructor: Jill Seaman
//
/*
This program is designed to allow the user to interact with a table
representing a predetermined monthly budget of $1150. Table changes
will correspond to the user input in a straight forward manner.
Users can deduct spendings from the budget. The program will
calculate the over/under of spending vs budget and display
proper values.
*/

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

void table(struct Category []);
int user(struct Category [], int);
double spent(struct Category [], int i);

//<- 'struct Category budget[]' array size
const int CATS = 6;
//variables to store into char name[20]
double HOUS = 500, UTIL = 150, TRANS = 50, FOOD = 250, ENTER = 150,
        MISC = 50;

//declare struct globally to allow access throughout all fns
struct Category
{
    char name[20];      //<- for category name
    double allocation;  //<- for total budget per category
    double spent;       //<- for total money spent
};

//***********************************************************
// function name: main fn that stores values in array
// of structs and calls on fns user(), table(), and spent()
//
// returns: zero
//***********************************************************

int main()
{


    int num; //num is widely used for the user input value

    //fill array of structs with budget table entries
    Category budget[CATS] = {{"Housing", HOUS, 0.00},{"Utilities", UTIL, 0.00},
    {"Transportation", TRANS, 0.00}, {"Food", FOOD, 0.00},
    {"Entertainment", ENTER, 0.00}, {"Miscellaneous", MISC, 0.00}};

    table(budget);      //to show budget table before user input

    do
    {
        num = user(budget,num);     //call user() function and stores return
    }                               //value in 'num'
    while(num != 8);     //8 is quit



    return 0;
}




//***********************************************************
// table: prints budget table for user in an easy-to-read format
//
// p2: array of structures for budget values
// returns: void
//***********************************************************

void table(struct Category budget[])
{
    cout << setw(24) << left << "\n  Category" << setw(15) << "Allocated"
    << setw(10) << "Spent"
    << setw(15) << "over/under" << endl <<
    "-------------------------------------------------------------" << endl;

    cout << setprecision(2) << fixed << left;
    cout << "1. " << setw(20) << budget[0].name << setw(15) <<
    budget[0].allocation << setw(10) << budget[0].spent <<
    setw(8) << spent(budget, 0)
    << endl;

    cout << "2. " << setw(20) << budget[1].name << setw(15) <<
    budget[1].allocation << setw(10) << budget[1].spent <<
    setw(8) << spent(budget, 1)
    << endl;

    cout << "3. " << setw(20) << budget[2].name << setw(15) <<
    budget[2].allocation << setw(10) << budget[2].spent <<
    setw(8) << spent(budget, 2)
    << endl;

    cout << "4. " << setw(20) << budget[3].name << setw(15) <<
    budget[3].allocation << setw(10) << budget[3].spent <<
    setw(8) << spent(budget, 3)
    << endl;

    cout << "5. " << setw(20) << budget[4].name << setw(15) <<
    budget[4].allocation << setw(10) << budget[4].spent <<
    setw(8) << spent(budget, 4)
    << endl;

    cout << "6. " << setw(20) << budget[5].name<<  setw(15) <<
    budget[5].allocation << setw(10) << budget[5].spent <<
    setw(8) << spent(budget, 5)
    << endl;
}

//***********************************************************
// function name: makes decision based on user input
//
// p1: array of structures for budget values
// p2: user input variable
// returns: user input
//***********************************************************

int user(struct Category budget[], int num)
{
     double addSpent = 0;
     //for primary user interface prompt
     cout << "Enter the category number to record money spent, or enter 7\nto";
     cout << " display table or 8 to quit:  ";
     cin  >> num;

     //switch statement evaluates user input (1-8) and acts accordingly
     //also verifies that user input is only 1-8 integer
     switch(num)
     {
        case 1:
            cout << "Please enter the amount to add to that category:\n";
            cin  >> addSpent;
            budget[0].spent = budget[0].spent + addSpent;
            break;
        case 2:
            cout << "Please enter the amount to add to that category:\n";
            cin  >> addSpent;
            budget[1].spent = budget[1].spent + addSpent;
            break;
        case 3:
            cout << "Please enter the amount to add to that category:\n";
            cin  >> addSpent;
            budget[2].spent = budget[2].spent + addSpent;
            break;
        case 4:
            cout << "Please enter the amount to add to that category:\n";
            cin  >> addSpent;
            budget[3].spent = budget[3].spent + addSpent;
            break;
        case 5:
            cout << "Please enter the amount to add to that category:\n";
            cin  >> addSpent;
            budget[4].spent = budget[4].spent + addSpent;
            break;
        case 6:
            cout << "Please enter the amount to add to that category:\n";
            cin  >> addSpent;
            budget[5].spent = budget[5].spent + addSpent;
            break;
        case 7:
            table(budget);              //prints table for user
            break;
        case 8:
            spent(budget, 8);         //passes 8 into spent(), which
            break;                    //calculates monthly over/under
        default:
            cout << "ERROR: Invalid Input\n\n";     //ERROR when input != 1-8
            break;
     }

     return num;        //gives user input to main fn for further use
}


//***********************************************************
// spent: calculates over/under for individual categories
// and for entire month
//
// p1: array of structures for budget values
// p2: an argument to determine which section of spent fn to use
// returns: budget for specific category if argument is < 6
//***********************************************************

double spent(struct Category budget[], int i)
{
    //calculates over/under relative to i, which is table location.
    //See 'spent(budget, #)' in table format fn
    if(i < 6)
    {
        double catBudget;           //used to evaluate category budget
        catBudget = budget[i].allocation - budget[i].spent;
        return catBudget;
    }

    //when 'spent(budget, 8)', calculate total over/under for the month
    //See case 8 of switch statement
    else if (i = 8)
    {
        double totalSpent;      //<- for total $ spent so far
        double overUnder;       //<- for total monthly over/under

        totalSpent = budget[0].spent + budget[1].spent + budget[2].spent
        + budget[3].spent + budget[4].spent + budget[5].spent;

        overUnder = 1150 - totalSpent;      //1150 comes from total budget
        if(overUnder < 0)                   //for entire month
            cout << "\nNegative Balance for the month: $" << overUnder;
        if(overUnder > 0)
            cout << "\nRemaining Budget for the month: $" << overUnder;
        cout << "\n\nEXITING PROGRAM...\n";
    }
}









