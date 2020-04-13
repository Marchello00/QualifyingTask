#pragma once

#include "asio.hpp"

namespace fod_networking {

class Resolver {
 public:
  asio::ip::basic_resolver<asio::ip::tcp>::results_type Resolve(
      const std::string& host, uint16_t port);

  explicit Resolver();

 private:
  asio::ip::tcp::resolver resolver_;
};

}