#pragma once

#include <cstdint>
#include <asio.hpp>

namespace fod_networking {

class Socket;

class Acceptor {
 public:
  Acceptor();

  void Listen(uint16_t port);

  // Returns port number
  uint16_t ListenAvailablePort();

  uint16_t GetPort() const;

  Socket Accept();

 private:
  asio::ip::tcp::acceptor acceptor_;
};

}