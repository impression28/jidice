#include <iostream>
#include <fstream>

int main()
{
  std::ifstream fatura;
  fatura.open("nubank-2020-03.csv");
  std::string date, category, title, amount;
  while (std::getline(fatura, date, ',')) {
    std::cout << "data: " << date << " ";

    std::getline(fatura, category, ',');
    std::cout << "categoria: " << category << " ";

    std::getline(fatura, title, ',') ;
    std::cout << "título: " << title << " ";

    std::getline(fatura, amount);
    std::cout << "quantia: " <<  amount<< " " << std::endl;
  }
  return 0;
}
