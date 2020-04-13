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

  bool Finished() const;

  void Round();

 private:
  size_t GetMaxAttemptsNumber() const;

  std::string GetMaskedWord() const;

  void UpdateMask(char letter);

  bool IsWin() const;

  void Lose();
  void Congratulations();

 private:
  std::shared_ptr<fod_networking::Socket> client_;
  std::string word_;

  std::vector<bool> guessed_;

  size_t attempts_ = 0;
  bool finished_ = false;
};

}