#pragma once

#include <memory>
#include <string>
#include <vector>
#include "socket.h"

namespace fod_server {

class Client {
 public:
  explicit Client(std::shared_ptr<fod_networking::Socket>);

  void Greeting();

  const std::string& GetWord() const;
  void SetNewWord(const std::string& word);

  void ShowAttempts();

  size_t GetMaxAttemptsNumber() const;

  bool Finished() const;

  void Round();

  void Reset();

  std::string GetMaskedWord() const;

 private:
  std::shared_ptr<fod_networking::Socket> client_;
  std::string word_;

  std::vector<bool> guessed_;

  size_t attempts_ = 0;
  bool finished_ = false;
};

}