// Joseph Michael Rice  // class cs1570 section c
// File hw10.cpp  // id 12541608 & 12545935 //date: 12-5-18
//course: cs1570  //purpose: simulates a burger eating contest

#ifndef COOL_OPS_H
#define COOL_OPS_H
#include "burgermeister.h"
#include "Burger.h"
#include "Customer.h"
#include "function.h"
#include <iostream>

using namespace std;

ostream & operator << (ostream & os, burgermaseister & K);
ostream & operator << (ostream & os, Burger & b);
ostream & operator << (ostream & os, Customer & c);

#endif // COOL_OPS_H
