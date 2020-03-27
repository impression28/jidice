#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>

struct transaction
{
  std::string date;
  std::string category;
  std::string title;
  int amount; // quantia em centavos
};

int amount_to_int(std::string amount)
{
  if (amount.size() == 0)
  {
    return 0;
  }
  int sinal = 0;
  int cursor = 0;
  if (amount[cursor] == '-')
  {
    sinal = -1;
    cursor++;
  }
  else if (amount[cursor] == '+')
  {
    sinal = 1;
    cursor++;
  }
  else
  {
    sinal = 1;
  }

  int total = 0;
  while (cursor < amount.size())
  {
    if (amount[cursor] != '.')
    {
      total = total*10 + (amount[cursor]-'0');
      cursor++;
    }
    else
    {
      cursor++;
      break;
    }
  }

  for (int j = 0; j < 2; j++)
  {
    if (cursor+j >= amount.size())
    {
      total *= 10;
    }
    else
    {
      total = total*10 + (amount[cursor]-'0');
    }
  }
  
  return sinal*total;
}


int main()
{
  std::ifstream fatura;
  fatura.open("nubank-2020-03.csv");
  std::string date, category, title, amount;
  std::vector<transaction> expenses;
  transaction temp_transaction;
  std::getline(fatura, date);
  while (std::getline(fatura, date, ',')) 
  {
    temp_transaction.date = date;

    std::getline(fatura, category, ',');
    temp_transaction.category = category;

    std::getline(fatura, title, ',') ;
    temp_transaction.title = title;

    std::getline(fatura, amount);
    temp_transaction.amount = amount_to_int(amount);
    
    expenses.push_back(temp_transaction);
  }

  std::cout << "      date " 
    << std::setw(7) << "amount"
    << std::setw(9) << "balance" << std::endl;
  int total = 0;
  for (const auto t : expenses)
  {
    total += t.amount;
    std::cout << t.date << " " 
              << std::setw(7) << t.amount 
              << std::setw(9) << total << std::endl;
  }

  return 0;
}
