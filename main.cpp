//Right now project has implemented FSM but it need
//mechanism to handle functions from specific Model classes

#include <iostream>
#include "Engine.hpp"
#include "Logic/Database/DBmanager.hpp"
#include "Logic/Database/LoginManager.hpp"
#include "Logic/Database/QueryHelper.hpp"

/**
 * Declaration of PromptSingleton - class responsible for holding information about actual
 * user input in the application
 */
PromptSingleton* PromptSingleton::instancePtr = nullptr;

/**
 * Main class of the program
 * Creates Engine and start main lop
 * @return 0 if everything executes fine
 */
int main() {

   //  std::string log1 = "Michal";
   //  std::string log2 = "Kroma";
   //  std::string pas1 = "Gej";
   //  std::string pas2 = "Obciagacz";
   //
     DBmanager michal = DBmanager();
   //
   // // michal.insertUser(log1,pas1);
   //
   //  // std::vector<std::pair<std::string,std::string>> ret = michal.getUsers();
   //  // for(int i =0;i<ret.size();i++) {
   //  //     std::cout<<ret[i].first<<" "<< ret[i].second<<std::endl;
   //  // }
   //
   //  if(michal.loginUser(log1,pas1)) {
   //      std::cout<<"YEAH! michal zalogowanon";
   //  }
   //  else std::cout<<":( michal";
   //
   //  if(michal.loginUser(log1,pas2)) {
   //      std::cout<<"YEAH! kromka";
   //  }
   //  else std::cout<<":( kormka";


    Engine eng = Engine();
    bool finish = false;
    while(!finish)
    {
        eng.run();
    }
    return 0;
}
