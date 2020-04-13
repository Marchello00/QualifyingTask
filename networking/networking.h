#pragma once

#include "asio.hpp"

namespace fod_networking {

namespace detail {
static std::unique_ptr<asio::io_context> io_context;
}

void SetupNetworking();

void CleenupNetworking();

asio::io_context& GetContext();

}