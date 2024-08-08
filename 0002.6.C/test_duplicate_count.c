#include <criterion/criterion.h>
#include <stddef.h>

size_t duplicate_count(const char *text);

Test(Sample_Cases, should_pass_these_three_tests) {
  cr_assert_eq(duplicate_count("abcde"), 0);
  cr_assert_eq(duplicate_count("abcdea"), 1);
  cr_assert_eq(duplicate_count("indivisibility"), 1);
}
