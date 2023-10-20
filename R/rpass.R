#'
#' Creates a password
#' @export
#'
#' @param nwords Number of words
#'

create_pass <- function(nwords = 4,
                        min_l = 4,
                        max_l = 8,
                        sep = "-",
                        complex = FALSE,
                        seed = NULL,
                        words_dir = "data") {
  require(readr)

  if (!is.null(seed)) set.seed(seed)

  file_path <- file.path(words_dir, ifelse(complex, "words.txt", "words_c.txt"))

  words <- read_lines_chunked(file_path,
                              chunk_size = 10000,
                              callback = AccumulateCallback$new(
                                \(x, pos, acc) c(acc, x[grepl(paste0(".{", min_l, ",", max_l, "}"), x)]))
  )

  sample(words, nwords) |>
    paste(collapse = sep)

}

create_pass()
