#include <iostream>
#include "argparse.h"
#include "server.h"
#include "acceptor.h"
#include "networking.h"

void PrintUsage(char* path) {
  std::cout << "Usage: " << std::string(path) << " [port]\n";
}

int main(int argc, char* argv[]) {
  argparse::Argparse parser;
  try {
    parser.ParseArgs(argc, argv);
  } catch (std::exception& error) {
    std::cout << error.what();
    PrintUsage(argv[0]);
    return 0;
  }

  fod_networking::SetupNetworking();

  fod_server::Server server;
  server.Run(0, "data/dictionary.txt");

  fod_networking::CleenupNetworking();

  return 0;
}