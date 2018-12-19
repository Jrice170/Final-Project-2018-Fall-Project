#include "cool_ops.h"

ostream & operator << (ostream & os, burgermaseister & K)
{
  os<<"The total amount krusty has now is: "<<endl;
  os<<"$ "<<K.get_holdings()<<endl;
  return os;
}

ostream & operator << (ostream & os, Burger & b)
{
  os<<"The cost of the burger is $"<<b.get_cost()<<endl;
  os<<"Burger name "<<b.get_name()<<endl;
  return os;
}

ostream & operator << (ostream & os, Customer & c)
{
  string name1 = " ALIVE ";
  string name2 = " DEAD ";
  string heath_action;
  string statice;
  bool cheak = c.get_life();

  if (cheak == 1)
  {
    statice = name1;
  }
  else
  {
    statice = name2;
  }
  if(c.m_vomet == 1)
  {
    heath_action = " And Vomits ";
  }
  else
  {
    heath_action = "";
  }
  c.get_name();
  os<< " "<<"Weighs "<<c.weight()<< " lbs Has $" <<c.cash();
  os<<" IBU "<<c.m_c_level()<<" "<<" and is "<<statice<<heath_action<<endl;
  return os;
}
