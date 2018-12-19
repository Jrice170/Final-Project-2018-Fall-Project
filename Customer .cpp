#include "Customer.h"
#include "Burger.h"
#include "burgermeister.h"
#include "function.h"
#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

Customer::Customer()
{
  m_cash = rand()%51 + 25;
  m_weight = rand()%161 + 90;
  m_health = rand()%100 + 1;
  c_level = rand()%271 + 30;
  rand_name();
  m_alive = 1;
  m_vomet = 0; //at first
  m_running_status =1;
  m_weight_gain = 0;// stating it off a zero
}

void Customer::rand_name()
{
   string file_name = "simpson_names.dat"; //make sure file string .dat
   ifstream file;
   file.clear();
   file.open(file_name.c_str());
   ///  get random_name
   //static int line_number = 0;
   bool loop = 1;
   int rand_line;
   do
   {
     rand_line = rand()%25;
     if(check_number(rand_line))
     {
       for(int i = 0; i <= rand_line;i++)
       {
         file.getline(m_name,30);
         loop = 0;
       }
     }
   }while(loop);
   file.close();
   return;
}

void Customer::get_name()const{
  cout<<m_name<<endl;
}


void Customer::eat(Burger & object)
{
  string dead_or_alive; // update message to the screen
  string vomit_or_not; // update message to the screen

  c_level += 2.5*object.get_bacon()+\
  ((object.get_patties()/2)) *object.get_patties()\
  + ((m_weight)/((object.get_pickles()+1)*10));

  m_cash -= object.get_cost();



  m_weight += 0.5*pow(object.get_patties(),2) + \
  (1/8)*pow(object.get_bacon(),2) - \
  (object.get_pickles()/4) + 1.2*object.get_cheese() +2.1*object.get_special();

  m_weight_gain += 0.5*pow(object.get_patties(),2) + \
  (1/8)*pow(object.get_bacon(),2) - \
  (object.get_pickles()/4) + 1.2*object.get_cheese() +2.1*object.get_special();


  m_vomet = 0;
  // checking here
  if (object.get_pathogen() == 1)
  {

    if(Roll_101() > m_health)
    {

      m_alive = 0; // kills the contestant

    }
    if((Roll_101() == m_health) || (m_health < Roll_101()))
    {

      m_vomet = 1;
      add_cash();  /// krusty gives them cash
      m_health = m_health/2;

    }

  }
   //m_vomet = 1; // test
   //cout<<m_alive<<endl;  test print outs
   //cout<<m_vomet<<endl;

   if((m_vomet == 1) && (m_alive == 1))
    {
      vomit_or_not = " And barfs ";

    }

    if(m_alive == 0)
    {
      dead_or_alive = "DEAD";

    }
    if(m_alive == 1)
    {

      dead_or_alive = "ALIVE";

    }
  cout<<m_name<<" eats "<<object.get_name()<<" Wt "<<m_weight<<\
  " chol "<<c_level<<" Heath: "<<m_health <<" and is "\
  <<dead_or_alive<<vomit_or_not<<endl;
  return;
}

double Customer::cash() const{
  return m_cash;
}

int Customer::weight() const{
  return m_weight;
}

int Customer::m_c_level()const{
  return c_level;
}

bool Customer::get_life()const{
  return m_alive;
}

int Customer::get_heailth()const{
  return m_health;
}

bool Customer::get_vomit()const{
  return m_vomet;
}

int Customer::weight_gain()const{
  return m_weight_gain;
}

void Customer::toss(Customer array[])
{
  int randindex = rand()%16;
  if(randindex != 15)
  {
    cout<<m_name<<" tosses a burger at ";
    cout.width(3);
    array[randindex].print2();
    cout<<endl;
    m_health += 2;
    int percent_of_continue = rand()%10 + 1;
    if(percent_of_continue <= 8)
    {
      chain_reaction(array,randindex);
      // start chain reaction with function
      // will stop when the percentage is not 80 percent
    }
  }

  else
  {
    cout<<m_name;
    cout.width(3);
    cout<<" hit the burgermeister ";
    m_running_status = 0;
    cout<<m_name<<" is thrown out "<<endl;
  }
}

bool Customer::running_status()const{
  return m_running_status;
}

void Customer::print()
{
  cout<<m_name<<"   Throws a burger at "<<endl;
}

void Customer::print2()
{
  cout<<"\t"<<m_name;
}

void Customer::add_heailth(int value)
{
  m_health += value;
}

void Customer::update_status(bool value2)
{
  m_running_status = value2;
}

void Customer::hafe_helth()
{
   m_health = (m_health/2);
}

void Customer::empty_wal()
{
  m_cash = 0;
}

void Customer::change_life()
{
  m_alive =0;
}

void Customer::add_cash()
{
  m_cash+= 5;// when they vomit krusty gives them money
  // is then subtracted from them
}

Customer Customer::Kill(burgermaseister MR_K)
{
  /// if person not dead check these conditions
  if(m_alive == 1)
  {
    if(m_weight_gain >= 80)
    {
      // kill person
      print2();
      cout.width(3);
      cout<<" Exploded "<<endl;
      m_alive = 0;
      MR_K -= 35;
    }
    if(m_health<=0)
    {
      // kill person
      print2();
      m_alive =0;
      cout.width(3);
      cout<<" Heath was to low "<<endl;
      MR_K -= 35;
    }
    if(c_level>300)
    {
      // kill person
      print2();
      m_alive = 0;
      cout.width(3);
      cout<<" Had a heart attack "<<endl;
      MR_K -=35;
    }
  }

  if(MR_K.get_holdings() <=0)
  {
    MR_K += 100; // add 100 dollars if funds below 0 dollars
  }
  return *this;
}
