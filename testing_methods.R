library(readr)
library(data.table)

file_path <- file.path("data", "words.txt")
min_l <- 4
max_l <- 8

read_straight_grep <- function() {

  read_lines(file_path) |>
    grep("^.{4,8}$", x = _, value = TRUE)

}

read_straight_grep()

read_straight_len <- function() {

  words <- read_lines(file_path)

  words[nchar(words) >= 4 & nchar(words) <= 8]

}

read_straight_len()

read_chunked_grepl <- function() {
  read_lines_chunked(file_path,
                              chunk_size = 150000,
                              progress = FALSE,
                              callback = AccumulateCallback$new(
                                \(x, pos, acc) c(acc, x[grepl("^.{4,8}$", x)]))
  )
}

read_chunked_grepl()

read_chunked_len <- function() {
  read_lines_chunked(file_path,
                              chunk_size = 150000,
                              progress = FALSE,
                              callback = AccumulateCallback$new(
                                \(x, pos, acc) c(acc, x[nchar(x) >= 4 & nchar(x) <= 8]))
  )
}

read_chunked_len()

read_fread_grep <- function() {

  fread(file_path, header = FALSE, col.names = "words") |>
    _[grepl("^.{4,8}$", words)] |>
    _$words

}

read_fread_grep()

read_fread_len <- function() {

  fread(file_path, header = FALSE, col.names = "words") |>
    _[nchar(words) >= 4 & nchar(words) <= 8] |>
    _$words

}

read_fread_len()

Rcpp::sourceCpp("cpp/read_cpp.cpp")

read_cpp_len(file_path, min_l, max_l)

microbenchmark::microbenchmark(
  read_straight_grep(),
  # read_straight_len(),
  read_chunked_grepl(),
  # read_chunked_len(),
  read_fread_grep(),
  # read_fread_len(),
  read_cpp_len(file_path, min_l, max_l)
)
