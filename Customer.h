// Joseph Michael Rice // class cs1570 section c
// File hw10.cpp  // id 12541608 & 12545935 //date: 12-5-18
//course: cs1570  //purpose: simulates a burger eating contest

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Burger.h"
#include "burgermeister.h"
#include <iostream>
#include<string>
#include<cstring>
#include<cstdlib>
#include<fstream>
using namespace std;

 class Customer
 {
   public:
   // pre none
   // post none
   // randomly pick values for all the private memeber varables
   Customer();

   // pre returns
   // post
   // returns the same call with differnt alive value
   Customer Kill(burgermaseister MR_k);

   /// public member varables
   bool m_vomet; // vomit status might have to turn off;
   /// getters and setters ////

   // pre none
   // post none
   // return gets the name
   void get_name()const;

   // pre none
   // post none
   // returns sets member varable m_cash to zero
   void empty_wal();

   // pre Only takes in a Burger object
   // post none
   // return minipulated member varables
   void eat(Burger & object); // updates statiuse of consumer

   //descript: causes contestants to throw burgers at each other
   //pre: none
   //post: none
   void toss(Customer array[]);

   // pre none
   // post none
   // return the memeber varavble cash
   double cash() const;

   // pre none
   // post none
   // returns the member varable weight
   int weight() const;

   //descript: gets chol lvl
   //pre: none
   //pos: returns chol lvl
   int m_c_level()const;

   //descript: gets wt gain
   //pre: none
   //pos: returns wt gain
   int weight_gain()const;

   //descript: gets life
   //pre: none
   //pos: returns laifu
   bool get_life()const;

   //descript: gets vomit value
   //pre: none
   //pos: returns 1 or 0
   bool get_vomit()const;

   //descript: gets customer hp
   //pre:none
   //pos: returns hp
   int get_heailth()const;

   //descript: krusty rewards contestants that vomit
   //pre: none
   //pos: gives contestant 5 dollars
   void add_cash();

   //descript: changes life to 0
   //pre: none
   //pos: life is now 0
   void change_life();

   //descript: gets running status
   //pre: none
   //pos: returns running status
   bool running_status()const;

   //descript: prints name
   //pre: none
   //pos: prints name and "throws a burger at"
   void print(); // prints name to the screen

   // pre: none
   // post: none
   // returns adds the heath by that value
   void add_heailth(int value);

   //descript: prints name
   //pre: none
   //pos: prints name and " "
   void print2();

   //pre:
   //post:
   // updates the status of the costomer
   void update_status(bool value2);

   //descript:halves hp
   //pre:none
   //pos:halves contestant hp
   void hafe_helth();

   private:
   double m_cash;
   int m_weight;
   int c_level; // colesteral level
   bool m_alive; // alive or died
   int m_health;
   char m_name[30];
   int m_weight_gain;
   bool m_running_status;

   // pre none
   // post none
   // return a random generaed name
   void rand_name();

 };

#endif // CUSTOMER_H
