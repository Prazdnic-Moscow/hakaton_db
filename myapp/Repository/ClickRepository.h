#pragma once
#include <drogon/orm/DbClient.h> // Подключение к PostgreSQL
#include <string>
#include "../Model/ClickModel.h"
#include <list>
class ClickRepository 
{
    public:
        // Конструктор принимает подключение к БД
        ClickRepository(const drogon::orm::DbClientPtr &dbClient) : db_(dbClient) {}

        // Создать пользователя в БД
        UserData registerClick();

    private:
        drogon::orm::DbClientPtr db_; // Подключение к PostgreSQL
};