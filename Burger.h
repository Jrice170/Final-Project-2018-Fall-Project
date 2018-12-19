// Joseph Michael Rice & Gari M Pahayo // class cs1570 section c
// File hw10.cpp  // id 12541608 & 12545935 //date: 12-5-18
//course: cs1570  //purpose: simulates a burger eating contest

#ifndef BURGER_H
#define BURGER_H
#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;


class Burger
{

  public:
  // pre none
  // post none
  //returns the paramiters as private member varables
  Burger(int patties,int bacon,int pickles,bool cheese,\
  bool special,bool pathogen);

  // pre none
  // post none
  // returns randon things about the burger
  Burger();

  /// getters and setters
  // pre
  // post
  // return gets the number of patties
  int get_patties() const; // gets pattys

  // pre
  //post
  // return gets the number of bacon
  int get_bacon()const; // gets bacons 0z

  // pre
  //post
  // return gets the number of pickles
  int get_pickles()const; // gets pickles

  // pre
  //post
  // returns the cost
  double get_cost()const;

  // pre
  //post
  // returns the if their are cheese of not
  bool get_cheese()const; // gets the value of cheese

  // pre
  //post
  // return if their is special sauce
  bool get_special()const; // accsess this inforamtion

  // pre
  //post
  // return if they will get sick or not
  bool get_pathogen()const; // true or false

  // pre
  //post
  // returns the name of the customer
  string get_name();

  /// member functions
  private:
  // member variables
  int m_patties;
  int m_bacon; // ozs of bacon
  int m_pickles; // number of pickles
  bool m_cheese; // T or F
  bool m_special_sauce; // T or F
  bool m_pathogen;// T or F
  double m_cost; //
  string m_name; // set by the other member variables to determine name

  // pre all other varables have to be declared before this function will work
  // property
  // post none
  // returns a string based of the private member varables
  string make_name(); //  m_name = make_name();

  // Makes the member varables true or false
  // pre make sure value is between 1 and 10;
  // post returns true for 1 the rest false 10 %
  bool Add_on(const int value);
};

#endif // BURGER_H
