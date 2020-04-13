#include "socket.h"
#include "resolver.h"
#include "networking.h"

namespace fod_networking {

Socket Socket::ConnectTo(const std::string& host, uint16_t port) {
  // TODO: Resolver should be a singleton
  Resolver resolver;
  auto endpoints = resolver.Resolve(host, port);
  Socket socket;
  for (const auto& endpoint : endpoints) {
    auto successful_connect = socket.Connect(endpoint);
    if (!successful_connect) {
      continue;
    }
    return std::move(socket);
  }
  throw std::runtime_error("cannot connect to endpoint");
}

Socket Socket::ConnectToLocal(uint16_t port) {
  return ConnectTo("127.0.0.1", port);
}

bool Socket::Connect(const asio::ip::tcp::endpoint& endpoint) {
  socket_.connect(endpoint);
  if (!socket_.is_open()) {
    return false;
  }
  return true;
}

size_t Socket::ReadSome(MutableBuffer buffer) {
  asio::error_code error;
  size_t bytes_received = socket_.read_some(buffer, error);
  if (error && error != asio::error::eof) {
    throw asio::system_error(error);
  }
  return bytes_received;
}

size_t Socket::WriteSome(ConstBuffer buffer) {
  return socket_.write_some(buffer);
}

size_t Socket::Read(MutableBuffer buffer) {
  size_t bytes_received = 0;
  while (buffer.size() > 0) {
    auto bytes_read = ReadSome(buffer);
    bytes_received += bytes_read;
    buffer += bytes_read;
    if (bytes_read == 0) {
      break;
    }
  }
  return bytes_received;
}

void Socket::Write(ConstBuffer buffer) {
  while (buffer.size() > 0) {
    auto bytes_sent = WriteSome(buffer);
    buffer += bytes_sent;
  }
}

void Socket::ShutdownWrite() {
  socket_.shutdown(asio::ip::tcp::socket::shutdown_send);
}

asio::ip::tcp::socket& Socket::GetPlainSocket() {
  return socket_;
}

Socket::Socket() : socket_(GetContext()) {
}

}