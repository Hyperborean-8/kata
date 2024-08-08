#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

#define SIZE 20

int check_if_exists(char ch, char *(*keys)[2]) {

  printf("IT STOPS HERE!!");

  for (int i = 0; i < SIZE; i++) {
    if (ch == *keys[i][0]) {
      printf("NOT FUCK");

      return i;
    }
  }

  printf("FUCK");

  return -1;
}

size_t duplicate_count(const char *text) {

  char *keys[SIZE][2];
  int values[SIZE];
  int keys_len = 0;

  size_t answer = 0;

  for (int i = 0; i < strlen(text); i++) {
    int ch = text[i];

    printf("Char: %c\n", ch);

    if (isalpha(ch)) {
      ch = toupper(ch);

      printf("New char: %c\n", ch);
    }

    int j = check_if_exists(ch, keys);
    // If not exists in the Keys
    if (j == -1) {
      *keys[keys_len][0] = ch;
      values[keys_len] = 1;
      keys_len++;
    } else {
      values[j]++;
      if (values[j] == 2) {
        answer++;
      }
    }
  }

  printf("%zu", answer);

  return answer;
  //  <----  hajime!
}

int main() {
  const char *text = "abcdea";
  printf("Answer: %zu\n", duplicate_count(text));
}
