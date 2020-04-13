#include <fstream>
#include "dictionary.h"

void fod_dictionary::Dictionary::Load(const std::string& filename) {
  std::ifstream dict_file(filename);
  if (!dict_file.is_open()) {
    throw std::runtime_error("Dictionary not found");
  }
  std::string word;
  while (dict_file >> word) {
    words_.emplace_back(std::move(word));
  }
  dict_file.close();
}

std::string fod_dictionary::Dictionary::GetNextWord() {
  if (words_.empty()) {
    throw std::runtime_error("Dictionary is empty");
  }

  int ret_index = index_++;
  if (index_ == words_.size()) {
    index_ = 0;
  }
  return words_[ret_index];
}
