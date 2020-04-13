#pragma once

#include <string>
#include <vector>
namespace fod_dictionary {

class Dictionary {
 public:
  void Load(const std::string& filename);

  std::string GetNextWord();

 private:
  size_t index_ = 0;
  std::vector<std::string> words_;
};

}