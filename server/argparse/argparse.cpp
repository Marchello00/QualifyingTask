#include <string>
#include "argparse.h"

argparse::Argparse::Argparse(int default_port) : port_(default_port) {
}

bool argparse::Argparse::ParseArgs(int argc, char** argv) {
  if (argc > 2) {
    throw std::runtime_error("Too much arguments");
  }
  if (argc == 1) {
    return true;
  }
  port_ = std::stoi(argv[1], NULL, 10);
  return true;
}
