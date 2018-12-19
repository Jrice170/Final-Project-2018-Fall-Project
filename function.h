// Joseph Michael Rice & Gari M Pahayo // class cs1570 section c
// File hw10.cpp  // id 12541608 & 12545935 //date: 12-5-18
//course: cs1570  //purpose: simulates a burger eating contest

#ifndef FUNCTION_H
#define FUNCTION_H
#include "Customer.h"
#include "burgermeister.h"
#include<iostream>
#include<string>
using namespace std;

//pre none
// post none
// return a nice message
void greeting();

// pre the number must be an intiger between 0-25
// post useds a satic array
// returns wether number was used in the array
// for this progrogram it is used to track the names used for
// the file
bool check_number(int number);

//pre
// post
// returns a dice value between 0-101;
int Roll_101();

// pre starting index should be the size of the costomer array
// post this function goes with the walk_array function
// return continues the chain reaction if a sertant condition is meet
void chain_reaction(Customer array[],int starting_index);

// pre stating index should be to start
// post thie function should be used in the main loop
// return Ture if one or more players is not dead
bool check_All(Customer array[],int size);

/// pre array size is only should be size 15
// post none
// returns the minipulated array of Customers
void walk_array(bool vomit_member,Customer array[],\
int array_size,\
int position);

#endif
