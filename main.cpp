//Right now project has implemented FSM but it need
//mechanism to handle functions from specific Model classes

#include <iostream>
#include "Engine.hpp"
#include <sqlite3.h>

PromptSingleton* PromptSingleton::instancePtr = nullptr;


int main() {

        sqlite3* DB;
        int exit = sqlite3_open("example.db", &DB);

        if (exit) {
            std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl;
            return (-1);
        } else {
            std::cout << "Opened Database Successfully!" << std::endl;
        }

        // Create SQL statement
        std::string sql = "CREATE TABLE IF NOT EXISTS PERSON("
                          "ID INT PRIMARY KEY NOT NULL, "
                          "NAME TEXT NOT NULL);";

        // Execute SQL statement
        char* messageError;
        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

        if (exit != SQLITE_OK) {
            std::cerr << "Error Create Table" << std::endl;
            sqlite3_free(messageError);
        } else {
            std::cout << "Table created Successfully" << std::endl;
        }

        // Insert data
        sql = "INSERT INTO PERSON (ID, NAME) VALUES(1, 'John Doe');";
        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

        if (exit != SQLITE_OK) {
            std::cerr << "Error Insert" << std::endl;
            sqlite3_free(messageError);
        } else {
            std::cout << "Records created Successfully!" << std::endl;
        }

        // Select data
        sql = "SELECT * FROM PERSON;";
        sqlite3_stmt* stmt;
        exit = sqlite3_prepare_v2(DB, sql.c_str(), -1, &stmt, NULL);

        if (exit != SQLITE_OK) {
            std::cerr << "Error Select" << std::endl;
        } else {
            while (sqlite3_step(stmt) == SQLITE_ROW) {
                std::cout << "ID: " << sqlite3_column_int(stmt, 0) << std::endl;
                std::cout << "NAME: " << sqlite3_column_text(stmt, 1) << std::endl;
            }
        }

        sqlite3_finalize(stmt);
        sqlite3_close(DB);

        return 0;

    std::cin.get();

//    Engine eng = Engine();
//    bool finish = false;
//    while(!finish)
//    {
//        eng.run();
//    }
    return 0;
}
