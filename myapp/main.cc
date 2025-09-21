#include <drogon/drogon.h>
int main() {

    // Настройка сервера
    drogon::app()
        .addListener("0.0.0.0", 5555)
        .loadConfigFile("../config.json")
        .run();
    return 0;
}
