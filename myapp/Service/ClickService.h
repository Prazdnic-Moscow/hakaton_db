#pragma once
#include <drogon/drogon.h>
#include "../Model/ClickModel.h"
#include "../Repository/ClickRepository.h"
#include <list>
class ClickService 
{
    public:
        // Конструктор
        explicit ClickService(const drogon::orm::DbClientPtr& dbClient);

        UserData registerUser();

    private:
        std::shared_ptr<ClickRepository> repository; // Доступ к БД
};