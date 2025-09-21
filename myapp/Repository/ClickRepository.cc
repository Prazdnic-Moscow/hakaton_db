#include "ClickRepository.h"
UserData ClickRepository::registerClick()
{
    // 1. Создаём пользователя
    auto result = db_->execSqlSync
    (
        "INSERT INTO clickcount (time_click) "
        "VALUES (NOW()) "
        "RETURNING id, time_click"
    );
    UserData user;
    user.fromDb(result[0]);
    return user;
}