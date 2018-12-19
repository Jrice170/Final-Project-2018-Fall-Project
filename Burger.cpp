#include "Burger.h"
#include <iostream>
using namespace std;

Burger::Burger(int patties,int bacon, int pickles,bool cheese,\
bool special,bool pathogen){


  m_pickles = pickles;
  m_patties = patties;
  m_bacon = bacon;
  m_special_sauce = special;
  m_pathogen = pathogen;
  m_cheese = cheese;
  m_name = make_name();

}
double Burger::get_cost() const{
  return m_cost;
}
int Burger::get_patties()const{

   return m_patties;
}
int Burger::get_bacon()const{

   return m_bacon;
}
int Burger::get_pickles()const{

  return m_pickles;

}

bool Burger::get_special()const{

   return m_special_sauce;

}
bool Burger::get_pathogen()const{
   return m_pathogen;

}
bool Burger::get_cheese()const{

   return m_cheese;
}
string Burger::get_name()
{

   return m_name;

}
// default constructor random things
Burger::Burger()
{
  m_patties = 1 + rand()%4;
  m_bacon =  rand()%5;
  m_pickles =  rand()%5;
  int rand1 = 1 + rand()%10; //1-10 range of values
  int rand2 = 1 + rand()%10; // hence 10% of the time
  int rand3 = 1 + rand()%10;

  m_pathogen = Add_on(rand1); // 10% of the time
  m_special_sauce = Add_on(rand2);
  m_cheese = Add_on(rand3);
  m_name = make_name(); /// must be made after everything else
}
// pre must be declared after the other varable are declared a value
string Burger::make_name(){

  /// cost caluculations
  const double patty$ = 0.75;
  const double bacon$ = 0.50;
  const double pickle$ = 0.25;
  const double bun$ = 0.50;
  const double chese = 0.25;
  const double Sasils = 0.10;
  bool sum = m_patties + m_bacon - 6;
  string Patty;
  string Bacon;
  string Pickies;
  string return_string;
  m_cost += bun$;
  if(m_patties == 1)
  {
    Patty = "Single";
    m_cost += patty$;

  }
  if(m_patties ==2)
  {
    Patty = "Double";
    m_cost += patty$*2;
  }
  if(m_patties ==3)
  {
    Patty = "Triumph";
    m_cost += patty$*3;
  }
  if(m_patties ==4)
  {
    Patty = "Monster";
    m_cost += patty$*4;
  }
  if(m_bacon == 1)
  {
    m_cost += bacon$;
    Bacon = "Bacon";
  }
  if(m_bacon == 2)
  {
    Bacon = "Willbur";
    m_cost += bacon$*2;
  }
  if(m_bacon == 3)
  {
    Bacon = "Klogger";
    m_cost += bacon$*3;
  }
  if(m_bacon == 4)
  {
    Bacon = "Pork slab";
    m_cost += bacon$*4;
  }
  if(m_bacon == 0)
  {

    Bacon = "Health Master";

  }
  if(m_pickles ==0)
  {

    m_cost += pickle$*0;
    Pickies = "Tasteless";
  }
  if(m_pickles ==1)
  {
    m_cost += pickle$;
    Pickies = "Pickly";
  }
  if(m_pickles == 2)
  {
    m_cost += pickle$*2;
    Pickies = "Garden Fresh";
  }
  if(m_pickles == 3)
  {
    m_cost += pickle$*3;
    Pickies = "Kermit";

  }
  if(m_pickles == 4)
  {
    m_cost += pickle$*4;
    Pickies = "Greenee";

  }
  if(m_special_sauce == 1)
  {
    m_cost += Sasils;
   // cout<<" m_cost sa "<<m_cost<<endl;
  }
  if(m_cheese == 1)
  {

    m_cost += chese;
    //cout<<" m_cost ch"<<m_cost<<endl;
  }

  if((m_pickles >= (m_patties + m_bacon)))
  {
     if((m_special_sauce ==1) && (m_cheese ==0) )
     {

       return_string = "Krusty Veggie Sauce Burger";
       return return_string;

     }
     else if((m_cheese == 1) && (m_special_sauce == 0))
     {
       return_string = "Krusty Veggie Cheesey Burger";
       return return_string;
     }
     else if ((m_cheese == 1) && (m_special_sauce == 1))
     {
       return_string = "Krusty Veggie Cheesey Sauce Burger";
       return return_string;
     }
     else
     {

       return_string = "Krusty Veggie Burger";
       return return_string;
     }



  }
  else if(((m_pickles == 0) || (m_pickles ==1)) && (!sum))
  {
     if((m_special_sauce ==1) && (m_cheese ==0))
     {

       return_string = "Krusty Koroary Sauce Burger";
       return return_string;
     }
     else if((m_cheese == 1) && (m_special_sauce == 0))
     {
       return_string = "Krusty Koroary Cheesey Burger ";
       return return_string;
     }
     else if ((m_cheese == 1) && (m_special_sauce == 1))
     {

       return_string = "Krusty Koroary  Cheesey and Sauce Burger";
       return return_string;
     }
     else
     {

       return_string = "Krusty Koroary Burger";
       return return_string;
     }




  }
  else
  {
     if((m_special_sauce ==1) && (m_cheese ==0))
     {

       return_string = Patty + " " + Bacon + " "+Pickies +" With Sauce Burger";
       return return_string;
     }
     else if((m_cheese == 1) && (m_special_sauce == 0))
     {
       return_string = Patty + " " + Bacon + " "+Pickies + " Cheesey Burger";
       return return_string;
     }
     else if ((m_cheese == 1) && (m_special_sauce == 1))
     {
       return_string = Patty + " " + Bacon + " "+Pickies +\
       " Cheesey and With Sauce Burger";
       return return_string;
     }
     else
     {

       return_string = Patty + " " + Bacon + " "+Pickies + " Burger";
       return return_string;

     }


  }


}
// returns ture if value is a one else false
bool Burger::Add_on(const int value)
{
    if((value == 1))
    {
      return 1; // ture

    }
    else
    {

      return 0;

    }

}
