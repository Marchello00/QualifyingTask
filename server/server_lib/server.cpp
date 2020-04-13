#include <thread>
#include "server.h"
#include "networking.h"
#include "acceptor.h"
#include "socket.h"
#include "client.h"

using fod_networking::Acceptor, fod_networking::Socket;

void fod_server::Server::Run(int port, const std::string& dict_path) {
  LoadDictionary(dict_path);
  Acceptor acceptor;
  acceptor.Listen(port);
  while (true) {
    Socket client = acceptor.Accept();
    std::shared_ptr client_ptr = std::make_shared<Socket>(std::move(client));
    std::thread(std::bind(&Server::ServeClient, this, client_ptr)).detach();
  }
}

void fod_server::Server::ServeClient(std::shared_ptr<Socket> client_ptr) {
  Client client(client_ptr);
  client.Greeting();
  // TODO: while true + another game
  auto word = dictionary_.GetNextWord();
  client.SetNewWord(word);
  client.ShowAttempts();
  while (!client.Finished()) {
    client.Round();
  }
}

void fod_server::Server::LoadDictionary(const std::string& dict_path) {
  dictionary_.Load(dict_path);
}
