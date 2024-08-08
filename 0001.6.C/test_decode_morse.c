#include <stdlib.h>
#include <criterion/criterion.h>

extern char *decode_morse(const char *morse_code);
static void tester(const char *morse_test, char *expected);

Test(Example_Tests, should_pass_all_the_tests_provided) {
    tester(".... . -.--   .--- ..- -.. .", "HEY JUDE");
}

static void tester(const char *input, char* expected) {
    char *submitted = decode_morse(input);
    cr_assert_str_eq(submitted, expected,
        "Input:\n\n\"%s\"\n\nExpected:\n\n\"%s\"\n\n\nSubmitted:\n\n\"%s\"\n\n",
        input,              expected,                submitted
    );
    free(submitted);
}
