#include "acceptor.h"
#include "networking.h"
#include "socket.h"

namespace fod_networking {

Acceptor::Acceptor() : acceptor_(GetContext()) {
}

void Acceptor::Listen(uint16_t port) {
  asio::ip::tcp::endpoint local_port_ep(asio::ip::tcp::v4(), port);
  acceptor_.open(local_port_ep.protocol());
  acceptor_.bind(local_port_ep);
  acceptor_.listen(asio::socket_base::max_listen_connections);
}

uint16_t Acceptor::ListenAvailablePort() {
  Listen(0);
  return GetPort();
}

Socket Acceptor::Accept() {
  Socket client;
  acceptor_.accept(client.GetPlainSocket());
  return std::move(client);
}

uint16_t Acceptor::GetPort() const {
  return acceptor_.local_endpoint().port();
}

}