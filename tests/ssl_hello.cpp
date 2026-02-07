#include <uWebSockets/App.h>
#include <iostream>

int main() {
    uWS::SSLApp({
        .key_file_name = "PB.key",
        .cert_file_name = "PB.crt"
    }).get("/*", [](auto *res, auto *req) {
        res->end("Hello from SSL!");
    }).listen(9443, [](auto *token) {
        if (token) {
            std::cout << "Listening on https://0.0.0.0:9443" << std::endl;
        }
    }).run();
}
