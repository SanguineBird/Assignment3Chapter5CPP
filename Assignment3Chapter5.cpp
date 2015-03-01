/*
Meghan Moore
February 14, 2015
CIT 245 - Data Structures and Programming C++
Assignment 3 - Chapter 5
Purpose: Write a program that generates random numbers between 1 and 10 and fill an array of size 20 with them.
Use the STL sort function to sort your array.
*/

#include <cstdlib> //srand, rand
#include <ctime> //time
#include <algorithm> //sort
#include <iostream> //cin, cout, cerr
#include <cstdlib> //system
using namespace std;

int d10Roll();
/*Precondition: none. Postcondition: returns pseudo-randon int between 1 and 6.*/
void count(int mainArray[], int size);
/*Precondition: receives initialized array where indexes are values 1-10.
Postcondition: prints tally of occurances of each integer.*/
bool repeatPrompt();
/*Precondition: function is called into a loop dependent on a boolean value
where a return value of 'false' will end the loop.
Postcondition: If the user selects 1 for 'yes', the function will return
true. If the user selects 0 for 'exit', the function will return 'false'.
If any other input is given, the prompt will repeat.*/


//------------------------------
int main(){
  int random[20];
  bool tryAgain;
  srand(time(NULL));
  
  cout << "This program generates random numbers and tabulates the results\n\n";
  
  do{
    //initialize random[]
    for(int i = 0; i < 20; i++){
      random[i] = d10Roll();
    }
    
    sort(random, random + 20);
    
    //print random[]
    cout << "Original List Sorted:\n";
    for(int j = 0; j < 20; j++){
      cout << "a[" << j << "]\t" << random[j] << endl;
    }
    cout << endl;
    
    //tally and print occurances of each int
    count(random, 20);
    
    tryAgain = repeatPrompt();
  }while(tryAgain);
  
  system("pause");
  return 0;
} //end main
//------------------------------
int d10Roll(){
  int roll;
  
  roll = rand() % 10 + 1;
  return roll;
} //end d10Roll
//------------------------------
void count(int mainArray[], int size){
  int countArray[10] = {0};
  
  for(int n = 0; n < size; n++){
    switch (mainArray[n]){
      case 1:
        countArray[0]++;
        break;
      case 2:
        countArray[1]++;
        break;
      case 3:
        countArray[2]++;
        break;
      case 4:
        countArray[3]++;
        break;
      case 5:
        countArray[4]++;
        break;
      case 6:
        countArray[5]++;
        break;
      case 7:
        countArray[6]++;
        break;
      case 8:
        countArray[7]++;
        break;
      case 9:
        countArray[8]++;
        break;
      case 10:
        countArray[9]++;
        break;
      default:
        cerr << "Error: Ending Program";
        exit(1);
    } //end switch
  } //end for
  
  //display results
  cout << "N Count\n";
  for(int x = 0; x < 10; x++){
    cout << (x + 1) << ": \t" << countArray[x] << endl;
  } //end for
  cout << endl;
} //end count
//------------------------------
bool repeatPrompt(){
  bool validInput, repeat;
  int input;

  do{
    cout << "Try Again? (1 = yes, 0 = exit)\n";
    cin >> input;
    cout << endl << endl;
  
    switch (input){
      case 0:
        validInput = true;
        repeat = false;
        break;
      case 1:
        validInput = true;
        repeat = true;
        break;
      default:
        validInput = false;
    } //end switch
  } while(validInput == false);
  
  return repeat;
} //end repeatPrompt
