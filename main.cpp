// Joseph Michael Rice // class cs1570 section c
// File hw10.cpp  // id 12541608 & 12545935 //date: 12-5-18
//course: cs1570  //purpose: simulates a burger eating contest
// Program a menu with 7 options input a 5 or less digit number
// enter the base of the number then converts to decimal

#include "burgermeister.h"
#include "Burger.h"
#include "function.h"
#include "Customer.h"
#include "cool_ops.h"
#include <iostream>
#include<string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
  srand(time(NULL));

  const int max_consumer = 15;
  const int max_burger = 40;
  Burger Burger[max_burger];
  Customer Customer[max_consumer];
  burgermaseister Kusty("Krusty",100);

  cout<<" begin the contest !"<<endl;
  cout<<'\t'<<"The contestants are: "<<endl;

  for(int i = 0;i <max_consumer-1;i++)
  {
    cout<<Customer[i]<<endl;
  }

  int countt = 0;
  int Round_num = 1;

  do
  {
    cout<<'\n';
    cout<<" -----------------ROUND "<<Round_num<<"--------------"<<endl;
    cout<<'\n'<<endl;
    for(int i = 0; i<max_consumer;i++)
    {
      Customer[i].Kill(Kusty);
      if(Customer[i].get_life() == 0)
      {
        //Customer[i].print2();
        ///cout<<" Did not survive. "<<endl;
      }
      else if(Customer[i].running_status() == 0)
      {
        if(Customer[i].cash() > 0)
        {
            Kusty += Customer[i].cash(); // Krusty takes all the money
        
            Customer[i].empty_wal();
        }
      //Customer[i].print2();
      //cout<<" Was disqualifed "<<endl;
      }
      else
      {
        int rand_burger = rand()%40;
        // krusty collects cost of burger
        // costomer subtract cost from buger
        if(Customer[i].cash() < Burger[rand_burger].get_cost())
        {
          Customer[i].print2();
          cout<<" Does not have the money to buy a Burger "<<\
          Burger[rand_burger].get_name()<<endl;
          Customer[i].add_cash();
          if(Kusty.get_holdings() < 0)
          {
            cout<<Kusty.get_name()<<" Runs to the bank. "<<endl;
            do
            {
              Kusty += 100;
            }while(Kusty.get_holdings() < 0);
          }
          Kusty -= 15;
        }
        else
        {
          Customer[i].eat(Burger[rand_burger]);
          Kusty += Burger[rand_burger].get_cost();
          walk_array(Customer[i].m_vomet,Customer,max_consumer,i);
        }
      }
    }
    Round_num++;
    countt++;
  }while(check_All(Customer,max_consumer));
  cout<<'\n';
  cout<<Kusty<<endl;
}






