#pragma once
#include <drogon/drogon.h>
#include<string>
class UserData 
{
    private:
        // Регистрация с полными данными пользователя
        std::string timeClick;
        int id;

    public:
        void fromDb(const drogon::orm::Row &result) 
        { 
            id = result["id"].as<int>();
            timeClick = result["time_click"].as<std::string>();
        }

        // Setters
        void setId(const int& id) 
        { 
            this->id = id; 
        }
        
        void setTimeClick(const std::string& time) 
        { 
            this->timeClick = time; 
        }

       
        // Getters
        int getId()
        { 
            return id;
        }

        std::string getTimeClick()
        { 
            return timeClick; 
        }
};