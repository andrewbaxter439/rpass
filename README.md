
<!-- README.md is generated from README.Rmd. Please edit that file -->

# rpass

<!-- badges: start -->

[![R-CMD-check](https://github.com/andrewbaxter439/rpass/actions/workflows/R-CMD-check.yaml/badge.svg)](https://github.com/andrewbaxter439/rpass/actions/workflows/R-CMD-check.yaml)
<!-- badges: end -->

The goal of rpass is to create xkcd-style passwords.

## Installation

You can install the development version of rpass from
[GitHub](https://github.com/) with:

``` r
# install.packages("devtools")
devtools::install_github("andrewbaxter439/rpass")
```

## Example

This is a basic example which shows you how to customise a muti-word
password of a custom length, complexity an with any set of separators:

``` r
library(rpass)

create_pass()  # Default settings
#> [1] "rhode-finishing-shame-community"

create_pass(
  nwords = 4,
  min_l = 4,
  max_l = 10,
  sep = "***",
  complex = TRUE
)
#> [1] "slaister***lupinosis***gachupin***servaline"
```
