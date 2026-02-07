#include <uWebSockets/App.h>
#include <iostream>
int main() {
    uWS::SSLApp({.key_file_name = "PB.key", .cert_file_name = "PB.crt"})
    .listen(9999, [](auto *s) {
        std::cout << (s ? "SSL WORKS!" : "SSL FAILED!") << std::endl;
    }).run();
}
