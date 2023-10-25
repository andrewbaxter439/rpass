#'
#' Creates a password
#' @export
#'
#' @param nwords Number of words
#' @param min_l Minimum word length
#' @param max_l Maximum word length
#' @param sep Separator between words
#' @param complex Whether to allow the full dictionary set of complex words
#' @param seed Set random seed (unset by default)
#' @param words_dir Directory containing word files
#'

create_pass <- function(nwords = 4,
                        min_l = 4,
                        max_l = 8,
                        sep = "-",
                        complex = FALSE,
                        seed = NULL,
                        words_dir = "data") {

  if (!is.null(seed)) set.seed(seed)

  file_path <- file.path(words_dir, ifelse(complex, "words.txt", "words_c.txt"))

  words <- .read_cpp(file_path, min_l, max_l)

  sample(words, nwords) |>
    paste(collapse = sep)

}

