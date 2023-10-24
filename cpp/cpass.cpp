#include <algorithm>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{

  int size = atoi(argv[1]);
  int min_l = atoi(argv[2]);
  int max_l = atoi(argv[3]);
  std::string sep = (std::string)argv[4];
  std::string file_name = "data/words.txt";

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


    file.close();
  }

  std::random_device rd;
  std::mt19937 gen(rd());

  std::vector<int> population {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<std::string> sample;
  std::sample(out_arr.begin(), out_arr.end(),
              std::back_inserter(sample),
              size,
              gen);
  std::shuffle(sample.begin(), sample.end(), gen);

  std::string out_cat;

  for(std::string word: sample)
    out_cat.append(word).append(sep);

  for(int poppers = 0; poppers < sep.size(); poppers ++){
    out_cat.pop_back();
    }

  std::cout << out_cat << "\n";
}
