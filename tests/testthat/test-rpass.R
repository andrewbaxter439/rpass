test_that("pass output works", {
  expect_equal(create_pass(seed = 121, words_dir = "../../data"), "notify-although-nasa-magnitude")
})
