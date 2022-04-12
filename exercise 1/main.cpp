//#include "zlasdtest/test.hpp" 
#include "zmytest/test.hpp"

/* ************************************************************************** */

#include <iostream>

/* ************************************************************************** */

int main() {

  do {
      std::cout<<"===================================================== \n"<<std::endl;
      std::cout<<" \t\tEXERCISE 1- Lucia Brando \t \n "<<std::endl;
      std::cout<<"===================================================== \n"<<std::endl;
       
        std::cout << "1.Test professore" << std::endl;
        std::cout << "2.My Test" << std::endl;
        std::cout << "3. Chiudi programma" << std::endl;
        std::cout << ": ";
        int res = 0;

        std::cin >> res;

        if(res == 1)
          zmytest();

        else if(res == 2)
          //zlasdtest();

        else if(res == 3)
          break;

    }while(true);

  
  return 0;

}
