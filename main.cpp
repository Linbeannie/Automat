/*
Title: project-1
Abstract: This program works like a vending machine. taking the input of a food and a drink objects and displays the user's selections. 
Name: Madeleine Macaulay
Email: mmacaulay@csumb.edu
Time: 20 hrs
Date: 02/29/2020
*/

#include <iostream>
using namespace std;

const int AUTOMAT_MAX = 10;
const int ORDER_MAX = 5;

class Food{
  public:
    Food();
    Food(string name, int calories, double price);
    string getName();
    int getCalories();
    double getPrice();
    void setName(string name);
    void setCalories(int calories);
    void setPrice(double price);
    void display();

  private:
    string myName;
    int myCalories;
    double myPrice;

};

class Drink {
  public:
    Drink();
    Drink(string name, int ounces, double price);
    string getName();
    int getOunces();
    double getPrice();
    void setName(string name);
    void setOunces(int ounces);
    void setPrice(double price);
    void display();

  private:
    string myName;
    int myOunces;
    double myPrice;

};

class Automat{
  public:
    Automat();
    bool emptyFood();
    bool emptyDrink();
    void enqueue(Food f);
    void enqueue(Drink d);
    void dequeueFood();
    void dequeueDrink();
    Food frontFood();
    Drink frontDrink();
    int foodCount();
    int drinkCount();
    int getTotalCalories();
    int getTotalOunces();
    double getTotalPrice();
    void display();

  private:
    int myFoodFront = 0;
    int myFoodBack = 0;
    Food myFood[AUTOMAT_MAX];
    int myDrinkFront = 0;
    int myDrinkBack = 0;
    Drink myDrink[AUTOMAT_MAX];
};

class Order{
  public:
    Order();
    bool emptyfood();
    bool emptydrink();
    void push(Food f);
    void push(Drink d);
    void popFood();
    void popDrink();
    Food topFood();
    Drink topDrink();
    int foodCount();
    int drinkCount();
    double getTotalPrice();
    void display();
    void cancel(Automat &);
    void purchase();
    static int getTotalOrders();

  private:
    int myFoodTop = 0;
    int myDrinkTop = 0;
    Food myFood[ORDER_MAX];
    Drink myDrink[ORDER_MAX];
    static int myTotalOrders;
};

//Default Constructors
Food::Food(){
}

Drink::Drink(){
}

int Order:: myTotalOrders = 0;
Order::Order():myFoodTop(-1), myDrinkTop(-1){
  myTotalOrders++; 
}

//Starts Constructor def.
Food::Food(string name, int calories, double price): 
myName(name), myCalories(calories), myPrice(price){
}

Drink::Drink(string name, int ounces, double price):
myName(name), myOunces(ounces), myPrice(price){
}

Automat::Automat():
myFoodFront(0), myFoodBack(0), myDrinkFront(0), myDrinkBack(0)
{} 

// Start function defintions
// S.Food Def.
void Food::setName(string name){
  name = myName;
}

string Food::getName(){
  return myName;
}

void Food::setCalories(int calories){
  calories = myCalories;
}

int Food::getCalories(){
  return myCalories;
}

void Food::setPrice(double price){
  price = myPrice;
}

double Food::getPrice(){
  return myPrice;
}

void Food::display(){
  cout << myName << ": " << myCalories << " calories, $" << myPrice << endl;
}

//e.Food Def.
//s.Drink Def.
void Drink::setName(string name){
  name = myName;
}

string Drink::getName(){
  return myName;
}

void Drink::setOunces(int ounces){
  ounces = myOunces;
}
int Drink::getOunces(){
  return myOunces;
}

void Drink::setPrice(double price){
  price = myPrice;
}

double Drink::getPrice(){
  return myPrice;
}

void Drink::display(){
  cout << myName << ": " << myOunces << " ounces, $" << myPrice << endl;
}

//e.Food Def.
//s.Automat Def.
bool Automat::emptyFood(){
  return (myFoodFront == myFoodBack);
}
bool Automat::emptyDrink(){
  return(myDrinkFront == myDrinkBack);
}
void Automat::enqueue(Food f){
  int newFoodBack = (myFoodBack + 1) % AUTOMAT_MAX;
  if (newFoodBack != myFoodFront){

    myFood[myFoodBack] = f;
    myFoodBack = newFoodBack;

  }else{
    cerr << " Automat food full; new food not added" << endl;
  }
}

void Automat::enqueue(Drink d){
  int newDrinkBack = (myDrinkBack + 1) % AUTOMAT_MAX;
  if (newDrinkBack != myDrinkBack){

    myDrink[myDrinkBack] = d;
    myDrinkBack = newDrinkBack;

  }else
  cerr << " Automat food full; new food not added" << endl;
}

Food Automat::frontFood(){
  if(!emptyFood()){
    return(myFood[myFoodFront]);
  }else{
    cerr << "Queue food returning garbage value\n";
    Food garbage;
    return garbage;
  }
}

Drink Automat::frontDrink(){
  if(!emptyDrink()){
    return(myDrink[myDrinkFront]);
  }else{
    cerr << "Queue drink returning garbage value\n";
    Drink garbage;
    return garbage;
  }
}

void Automat::dequeueFood(){
  if( !emptyFood() ){
    myFoodFront = (myFoodFront + 1) % AUTOMAT_MAX;
  }else{
    cerr << " Queue food is empty\n";
  }
}

void Automat::dequeueDrink(){
  if( !emptyDrink() ){
    myDrinkFront = (myDrinkFront + 1) % AUTOMAT_MAX;
  }else{
    cerr << " Queue drink is empty\n";
  }
}

int Automat::foodCount(){
  int foodcount = 0;
  for(int i = myFoodFront; i != myFoodBack; i = (i + 1) % AUTOMAT_MAX){
    foodcount++;
  }
  return foodcount;
}

int Automat::drinkCount(){
  int drinkcount = 0;
  for(int i = myDrinkFront; i != myDrinkBack; i = (i + 1) % AUTOMAT_MAX)
  {
    drinkcount++;
  }
  return drinkcount;
}

int Automat::getTotalCalories(){
  int sumFoodCal = 0;
  for(int i = myFoodFront; i != myFoodBack; i = (i + 1) % AUTOMAT_MAX){
    sumFoodCal += myFood[i].getCalories();
  }
  return sumFoodCal;
}

int Automat::getTotalOunces(){
  int sumDrinkOunces = 0;
  for(int i = myDrinkFront; i != myDrinkBack; i = (i + 1) % AUTOMAT_MAX){
    sumDrinkOunces += myDrink[i].getOunces();
  }
  return sumDrinkOunces;
}

double Automat::getTotalPrice(){
  double TotalPrice = 0;
  double DrinkPrice = 0;
  double FoodPrice = 0;
  for(int i = myFoodFront; i != myFoodBack; i = (i + 1) % AUTOMAT_MAX){
    FoodPrice += myFood[i].getPrice();
  }
  for(int i = myDrinkFront; i != myDrinkBack; i = (i + 1) % AUTOMAT_MAX){
    DrinkPrice += myDrink[i].getPrice();
  }
  TotalPrice = FoodPrice + DrinkPrice;
  return TotalPrice;
}

void Automat::display(){
  cout << "Automat: \n";
  cout << " Food:\n"; 
  for(int i = myFoodFront; i != myFoodBack; i = (i + 1) % AUTOMAT_MAX){
    cout << "\t"; 
    myFood[i].display(); 
  }
  cout << "\t" << foodCount() << " food items - Total Calories: " << getTotalCalories() << endl;

  cout << "Drinks:\n";
  for(int i = myDrinkFront; i != myDrinkBack; i = (i + 1) % AUTOMAT_MAX){
    cout << "\t"; 
    myDrink[i].display();    
  }
  cout << "\t" << drinkCount() << " drinks - Total Ounces: " << getTotalOunces() << endl;

  cout << endl;
}
//-- End Automat

//start Order
bool Order::emptyfood(){
  return(myFoodTop == -1);
}

bool Order::emptydrink(){
  return(myDrinkTop == -1);
}

void Order::push(Food f){
  if(myFoodTop < ORDER_MAX){
    ++myFoodTop;
    myFood[myFoodTop] = f;
  }else{
    cerr << "* Order food full -- new food not added*\n" << endl;
  }
}

void Order::push(Drink d){
  if(myDrinkTop < ORDER_MAX){
    ++myDrinkTop;
    myDrink[myDrinkTop] = d;
  }else{
    cerr << "* Order drink full --  new drink not added*\n" << endl;
  }
}

Food Order::topFood(){
  if(!emptyfood()){
    return (myFood[myFoodTop]);
  }else{
    cerr << "Food stack empty -- returning garbage value\n";
    Food garbage;
    return garbage;
  }
}

Drink Order::topDrink(){
  if(!emptydrink()){
    return (myDrink[myDrinkTop]);
  }else{
    cerr << "Food stack empty -- returning garbage value\n";
    Drink garbage;
    return garbage;
  }
}

void Order::popFood(){
  if(!emptyfood()){
    myFoodTop--;
  }else{
    cerr << "* Food stack Empty, can't remove value\n";
  }
}

void Order::popDrink(){
  if(!emptydrink()){
    myDrinkTop--;
  }else{
    cerr << "* Food stack Empty, can't remove value\n";
  }
}

int Order::foodCount(){
  return myFoodTop + 1;
}

int Order::drinkCount(){
 return myDrinkTop + 1;
}

void Order::cancel(Automat& a) {
  int fitems = foodCount();
  for(int i = 0; i < fitems; i++){
    a.enqueue(topFood());
    popFood();
  }
  int ditems = drinkCount();
  for(int i = 0; i < ditems; i++){
    a.enqueue(topDrink());
    popDrink();
  }
}

double Order::getTotalPrice(){
  double TotalPrice = 0;
  double DrinkPrice = 0;
  double FoodPrice = 0;
  for(int i = 0; i < drinkCount(); i++){
    //increment drink price 
    DrinkPrice += myDrink[i].getPrice();
  }
  for(int i = 0; i < foodCount(); i++){ 
     //increment food price 
     FoodPrice += myFood[i].getPrice();
   }
  TotalPrice = FoodPrice + DrinkPrice;
  return TotalPrice;
}
void Order::purchase(){
  myFoodTop = -1;
  myDrinkTop = -1;
}

int Order::getTotalOrders() {
  return myTotalOrders; 
}

void Order::display(){
  cout << "Order:\n";
  cout << "\t Food " << "(" << foodCount() << " items):" << endl;
    for(int i = 0; i < foodCount(); i++){
     cout << "\t \t"; myFood[i].display();
   }
  cout << "\t Drink " << "(" << drinkCount() << " items):" << endl;
    for(int i = 0; i < drinkCount(); i++){
      cout << "\t \t"; myDrink[i].display();
   }

  cout << " \t Order total: $" << getTotalPrice() << endl;
  cout << endl;
}
