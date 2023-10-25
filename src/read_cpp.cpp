#include <Rcpp.h>
#include <fstream>
#include <iterator>
#include <string>
using namespace Rcpp;


// [[Rcpp::export]]
StringVector read_cpp_len(String file_name, unsigned long min_l, unsigned long max_l) {

  // Rcpp::StringVector out_arr;
  // std::vector<char> in_arr = {"a", "aaaaa", "aaaaaa", "aaaaaaaaaa"};
  // std::vector<char> fileContents((std::istreambuf_iterator<char>(file)),
  //                                std::istreambuf_iterator<char>());
  // int i = 0;

  std::vector<std::string> out_arr;
  std::ifstream file(file_name, std::ios::binary);
  std::string word;

  if (file.is_open()) {
    std::istream_iterator<std::string> fileIterator(file);
    std::istream_iterator<std::string> endIterator;

    while (fileIterator != endIterator) {
      word = *fileIterator;
      if ((word.length() >= min_l) & (word.length() <= max_l)) {
        out_arr.push_back(word);
      }

      ++fileIterator;
    }

    // std::copy_if(fileContents.begin(), fileContents.end(), std::back_inserter(out_arr),
    //              [](std::string word) {
    //                return (word.length() >= 4) & (word.length() <= 8);
    //                });

    file.close();
  }
  // return Rcpp::StringVector::create(out_arr);

  Rcpp::StringVector out_vec(out_arr.size());

  out_vec = out_arr;

  return out_vec;

}
