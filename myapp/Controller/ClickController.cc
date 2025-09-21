#include "ClickController.h"
void ClickController::add(const HttpRequestPtr& req,
                          std::function<void(const HttpResponsePtr&)>&& callback)
                          {
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
