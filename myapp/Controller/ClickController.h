#include <drogon/drogon.h>
#include <drogon/orm/DbClient.h>
#include <json/json.h>
#include <drogon/HttpController.h>
#include "../Service/ClickService.h"
using namespace drogon;
class ClickController:public HttpController<ClickController>
{
    public:
        METHOD_LIST_BEGIN
        ADD_METHOD_TO (ClickController::add, "/add", Post);
        METHOD_LIST_END

        void add(const HttpRequestPtr& req,
                  std::function<void(const HttpResponsePtr&)>&& callback);

};