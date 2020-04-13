#include <string>
#include <iostream>
#include "client.h"
#include "networking.h"
#include "socket.h"

int main(int argc, char* argv[]) {
  // Argparse
  std::string host(argv[1]);
  uint16_t port = std::stoi(argv[2]);
  fod_networking::Socket server = fod_networking::Socket::ConnectTo(host, port);
  char c;
  while (std::cin >> c) {
    server.Write(c);
  }

  return 0;
}