#include "client.h"

fod_server::Client::Client(std::shared_ptr<fod_networking::Socket> client)
    : client_(std::move(client)) {
}

void fod_server::Client::Greeting() {
  // TODO: greeting
  client_->Write("Hello! This is Field Of Dreams game.\n");
}

const std::string& fod_server::Client::GetWord() const {
  return word_;
}

void fod_server::Client::SetNewWord(const std::string& word) {
  word_ = word;
  guessed_.resize(word_.size());
  guessed_.assign(word_.size(), false);
  attempts_ = 0;
  finished_ = false;
}

void fod_server::Client::ShowAttempts() {
  std::string message =
      "You have " + std::to_string(GetMaxAttemptsNumber()) + " attempts.\n";
  client_->Write(message);
}

size_t fod_server::Client::GetMaxAttemptsNumber() const {
  return word_.size() + 2;  // magic constant
}

void fod_server::Client::Round() {
  if (attempts_ == GetMaxAttemptsNumber()) {
    finished_ = true;
    return;
  }
  ++attempts_;
}

bool fod_server::Client::Finished() const {
  return finished_;
}

std::string fod_server::Client::GetMaskedWord() const {
  std::string result;
  for (int i = 0; i < word_.size(); ++i) {
    if (guessed_[i]) {
      result += word_[i];
    } else {
      result += '*';
    }
  }
  return std::move(result);
}
