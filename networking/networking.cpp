#include "networking.h"

void fod_networking::SetupNetworking() {
  detail::io_context = std::make_unique<asio::io_context>();
}

void fod_networking::CleenupNetworking() {
  detail::io_context.reset();
}

asio::io_context& fod_networking::GetContext() {
  return *detail::io_context;
}
