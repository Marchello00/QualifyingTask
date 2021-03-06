#pragma once

#include <stdexcept>

namespace argparse {

class Argparse {
 public:
  Argparse(int default_port = 0);

  bool ParseArgs(int argc, char* argv[]);

  int GetPort() const;

 private:
  int port_;
};

}