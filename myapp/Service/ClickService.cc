#include "ClickService.h"

// Конструктор — инициализируем репозиторий
ClickService::ClickService(const drogon::orm::DbClientPtr& dbClient)
{
    repository = std::make_shared<ClickRepository>(dbClient);
}
UserData ClickService::registerUser()
{
    return repository -> registerClick();
}