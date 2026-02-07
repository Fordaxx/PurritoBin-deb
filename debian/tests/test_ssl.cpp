#include <uWebSockets/App.h>
#include <iostream>

int main() {
    uWS::SSLApp({
        .key_file_name = "PB.key",
        .cert_file_name = "PB.crt"
    }).get("/*", [](auto *res, auto *req) {
        res->end("Hello!");
    }).listen(9999, [](auto *listen_socket) {
        if (listen_socket) {
            std::cout << "Listening on port 9999" << std::endl;
        } else {
            std::cout << "Failed to listen on port 9999" << std::endl;
        }
    }).run();
}
