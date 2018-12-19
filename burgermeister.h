// Joseph Michael Rice  // class cs1570 section c
// File hw10.cpp  // id 12541608 & 12545935 //date: 12-5-18
//course: cs1570  //purpose: simulates a burger eating contest

#ifndef BURGERMEISTER_H
#define BURGERMEISTER_H
#include <iostream>
#include <string>

using namespace std;

class burgermaseister
{
  public:
  burgermaseister(string name,float start_cash);
  burgermaseister();
  //pre
  //post
  //returns the name in the form of a string
  string get_name() const;
  //pre none
  // post none
  // return returns the amount of money this object has
  float get_holdings() const;

  //pre operator can only be used for floats or ints
  //post
  // return adds to the member varable m_holdings
  burgermaseister operator +=(const float money);

  //pre operator can only be used for floats and ints
  // post
  // returns the subtracted part
  burgermaseister operator -=(const float money);

  private:
  // member varable
  string m_name; // name
  float m_holdings; // where the cash will be stored and incrimented


};

#endif // BURGERMEISTER_H
