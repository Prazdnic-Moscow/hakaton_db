#include "ClickController.h"
void ClickController::add(const HttpRequestPtr& req,
                          std::function<void(const HttpResponsePtr&)>&& callback)
{
  auto resp = HttpResponse::newHttpResponse();
    resp->addHeader("Access-Control-Allow-Origin", "*"); // разрешить всем
  std::string body = std::string (req->getBody());
  if (body != "\"MALAK\"") 
  {
      auto resp = HttpResponse::newHttpResponse();
      resp->setStatusCode(k400BadRequest);
      callback(resp);
      return;
  }
  try
  {
      // 3. Получаем подключение к БД
      auto dbClient = drogon::app().getDbClient();
      // 4. Создаём сервис
      ClickService clickService(dbClient);
      clickService.registerUser();
      auto resp = HttpResponse::newHttpResponse();
      resp->setStatusCode(k200OK);
      callback(resp);
  }
  catch(const std::exception& e)
  {
      auto resp = HttpResponse::newHttpResponse();
      resp->setStatusCode(k400BadRequest);
      callback(resp);
  }
}
void ClickController::options(const HttpRequestPtr& req,
                             std::function<void(const HttpResponsePtr&)>&& callback)
{
    auto resp = HttpResponse::newHttpResponse();
    resp->addHeader("Access-Control-Allow-Origin", "*");
    resp->addHeader("Access-Control-Allow-Methods", "POST, OPTIONS");
    resp->addHeader("Access-Control-Allow-Headers", "Content-Type");
    resp->setStatusCode(k204NoContent);
    callback(resp);
}
