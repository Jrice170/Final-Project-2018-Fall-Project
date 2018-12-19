#include "function.h"
#include "burgermeister.h"
#include "Customer.h"
#include<iostream>
#include <string>
#include<cstdlib>

using namespace std;

void greeting()
{
  cout<<"Welcome to my program "<<endl;
  return;
}

bool check_number(int number)
{
  static int array[26] =\
  {0,1,2,3,4,5,6,7
  ,8,9,10,11,12,13,14
  ,15,16,17,18,19,20,
  21,22,23,24,25};

  for(int i = 0;i<26;i++)
  {
    if (array[i] == number)
    {
      array[i] = -1; // unused number
      return 1;
      //break;
    }
  }
  return 0;
}

int Roll_101()
{
  int value = rand()%101+1;
  return value;
}

void chain_reaction(Customer array[],int starting_index)
{
  int incrment = starting_index;
  int constinue_chain;
  int rand_throw;
  do
  {
    constinue_chain = rand()%10 + 1;
    rand_throw=rand()%16;
    // yes they might throw a burger at a dead person
    if(rand_throw !=15)
    {
       array[incrment].print();
       array[rand_throw].print2();
       array[incrment].add_heailth(2);
       incrment = rand_throw;
    }
    else
    {
      array[incrment].print2();
      cout<<" Hit the Burger master !!! "<<endl;
      array[incrment].update_status(0);
    }
  }while(constinue_chain <= 8); /// not 80 percent chance
  return;
}


bool check_All(Customer array[],int size)
{
  int count = 0;
  //int save_index;
  // for loop will work better

  for(int i=0;i<size;i++)
  {
    if(array[i].get_life()==1)
    {
      if(array[i].running_status()==1)
      {
        count++;
        //save_index = i;
      }
    }
  }
  return count;  // more that zero ture else o so false
}


void walk_array(bool vomit_member,Customer array[],\
int array_size,int position)
{
  if((vomit_member == 1) && (array[position].get_life() ==1))
  {
    string actions[8] = {" BLAHHHHA !!! \n"," GLRFMP !!! \n"," BLUOOOPP !!!\n "
    ," LAYYck !!! \n"," NMMSSIOH !!! \n"," BLA BALa BALLLL !!! \n"};
    int increment = position; ///starts here
    vomit_member =0;
    //bool move_prob; //50 percent 1 or 0
    array[increment].print2();
    int rand_number_1 = rand()%7;
    array[increment].add_cash(); // gives them cash when they vomit
    cout<<actions[rand_number_1];
    cout.width(3);

    int direction = -1;
    bool check;
    bool check2;
    do
    {
      // first walk down the array
      // hits zreo walk up to the top max_size-1
      // kills the loop
      increment += direction;
      // when the vomit their heath is haved
      if(increment == -1)
      {
        direction = 1;
        increment = 0;
      }

      if((increment == array_size-1)||(array[increment].get_life()==0))
      {
        break;
      }

      cout.width(4);
      array[increment].print2();
      array[increment].add_cash();
      int rand_number_2 = rand()%8;
      cout<<actions[rand_number_2];
      cout<<endl;
      array[increment].hafe_helth(); // they lose half their heath
      check = rand()%2;

      if(!check)
      {
        int chance = rand()%10 + 1; // 70 %
        if(chance <= 7)
        {
          array[increment].toss(array);
        }
      }
      check2 = rand()%2;
    }while(check2);
  }
}
