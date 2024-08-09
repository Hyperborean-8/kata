#include <ctype.h>
#include <stddef.h>
#include <stdio.h>

#define SIZE 20

int check_if_exists(char ch, char keys[SIZE]) {

  for (int i = 0; i < SIZE; i++) {
    if (ch == keys[i]) {
      return i;
    }
  }

  return -1;
}

size_t duplicate_count(const char *text) {

  char keys[SIZE] = {0};
  int values[SIZE];
  int keys_len = 0;

  size_t answer = 0;

  for (int i = 0; text[i] != '\0'; i++) {
    int ch = text[i];

    if (isalpha(ch)) {
      ch = toupper(ch);
    }

    int j = check_if_exists(ch, keys);
    // If not exists in the Keys
    if (j == -1) {
      keys[keys_len] = ch;
      values[keys_len] = 1;
      keys_len++;
    } else {
      values[j]++;
      if (values[j] == 2) {
        answer++;
      }
    }
  }

  return answer;
}

/*int main() {*/
/*  const char *text = "abcdea";*/
/*  printf("Answer: %zu\n", duplicate_count(text));*/
/*}*/
