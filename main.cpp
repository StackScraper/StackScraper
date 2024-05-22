//Right now project has implemented FSM but it need
//mechanism to handle functions from specific Model classes

#include <iostream>
#include "Engine.hpp"
#include "Logic/Database/DBmanager.hpp"

PromptSingleton* PromptSingleton::instancePtr = nullptr;


int main() {

    std::string log1 = "Michal";
    std::string log2 = "Kroma";
    std::string pas1 = "Gej";
    std::string pas2 = "Obciagacz";

    DBmanager michal = DBmanager();

    michal.insertUser(log1,pas1);
    michal.insertUser(log2,pas2);

    std::vector<std::pair<std::string,std::string>> ret = michal.getUsers();
    for(int i =0;i<ret.size();i++) {
        std::cout<<ret[i].first<<" "<< ret[i].second<<std::endl;
    }


    michal.updateUserPassword(2,log1);

    ret = michal.getUsers();
    std::cout<<std::endl;
    std::cout<<std::endl;
    for(int i =0;i<ret.size();i++) {
        std::cout<<ret[i].first<<" "<< ret[i].second<<std::endl;
    }

    michal.deleteUser(2);

    ret = michal.getUsers();
    std::cout<<std::endl;
    std::cout<<std::endl;
    for(int i =0;i<ret.size();i++) {
        std::cout<<ret[i].first<<" "<< ret[i].second<<std::endl;
    }

    // Engine eng = Engine();
    // bool finish = false;
    // while(!finish)
    // {
    //     eng.run();
    // }
    return 0;
}
