#include "resolver.h"
#include "networking.h"

namespace fod_networking {

Resolver::Resolver() : resolver_(GetContext()) {
}

asio::ip::tcp::resolver::results_type Resolver::Resolve(const std::string& host,
                                                        uint16_t port) {
  return resolver_.resolve(host, std::to_string(port));
}

}