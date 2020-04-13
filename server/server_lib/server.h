#pragma once

#include <string>
#include "dictionary.h"
#include "socket.h"

namespace fod_server {

class Server {
 public:
  void Run(int port, const std::string& dict_path);

 private:
  void ServeClient(std::shared_ptr<fod_networking::Socket>);
  void LoadDictionary(const std::string& dict_path);

 private:
  fod_dictionary::Dictionary dictionary_;
};

}