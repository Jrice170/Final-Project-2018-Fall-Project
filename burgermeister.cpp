#include "burgermeister.h"

burgermaseister::burgermaseister(string name,float start_cash)
{
  m_name = name;
  m_holdings = start_cash;
}

burgermaseister burgermaseister::operator+=(const float money)
{
  // you can add this strate to the buger master
  m_holdings += money;
  return *this;
}

burgermaseister burgermaseister::operator-=(const float money)
{
  m_holdings -= money;
  return *this;
}

string burgermaseister::get_name()const
{
  return m_name;
}

float burgermaseister::get_holdings()const
{
  return m_holdings;
}
