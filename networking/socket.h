#pragma once

#include "asio.hpp"
#include "acceptor.h"

namespace fod_networking {

using MutableBuffer = asio::mutable_buffer;
using ConstBuffer = asio::const_buffer;

class Socket {
 public:
  static Socket ConnectTo(const std::string& host, uint16_t port);
  static Socket ConnectToLocal(uint16_t port);

  size_t Read(MutableBuffer buffer);

  size_t ReadSome(MutableBuffer buffer);

  void Write(ConstBuffer buffer);

  void ShutdownWrite();

  bool Connect(const asio::ip::tcp::endpoint&);

 private:
  // Only for Acceptor
  friend Socket Acceptor::Accept();
  Socket();

  asio::ip::tcp::socket& GetPlainSocket();
  size_t WriteSome(ConstBuffer buffer);

 private:
  asio::ip::tcp::socket socket_;
};

}