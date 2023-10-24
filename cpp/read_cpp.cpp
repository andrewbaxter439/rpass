#include <Rcpp.h>
#include <fstream>
#include <iterator>
#include <string>
using namespace Rcpp;

// This is a simple example of exporting a C++ function to R. You can
// source this function into an R session using the Rcpp::sourceCpp
// function (or via the Source button on the editor toolbar). Learn
// more about Rcpp at:
//
//   http://www.rcpp.org/
//   http://adv-r.had.co.nz/Rcpp.html
//   http://gallery.rcpp.org/
//


// [[Rcpp::export]]
CharacterVector read_cpp_len(String file_name, unsigned long min_l, unsigned long max_l) {

  // std::vector<std::string> out_arr;
  Rcpp::StringVector out_arr;
  // std::vector<char> in_arr = {"a", "aaaaa", "aaaaaa", "aaaaaaaaaa"};
  std::ifstream file(file_name, std::ios::binary);
  // std::vector<char> fileContents((std::istreambuf_iterator<char>(file)),
  //                                std::istreambuf_iterator<char>());
  // int i = 0;

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
      // ++i;
    }

    // std::copy_if(fileContents.begin(), fileContents.end(), std::back_inserter(out_arr),
    //              [](std::string word) {
    //                return (word.length() >= 4) & (word.length() <= 8);
    //                });

    file.close();
  }
  // return Rcpp::StringVector::create(out_arr);
  return out_arr;

}



// You can include R code blocks in C++ files processed with sourceCpp
// (useful for testing and development). The R code will be automatically
// run after the compilation.
//

/*** R
read_cpp_len("data/words_c.txt", 4, 8)
*/
