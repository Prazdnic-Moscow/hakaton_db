#include "ClickRepository.h"
UserData ClickRepository::registerClick()
{
    auto trans = db_->newTransaction();
    // 1. Создаём пользователя
    auto result = trans->execSqlSync
    (
        "INSERT INTO clickcount (time_click) "
        "VALUES (NOW()) "
        "RETURNING id, time_click"
    );
    UserData user;
    user.fromDb(result[0]);
    return user;
}