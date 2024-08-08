/*
 * This code sucks ass and I'm not proud of it
 */

#include <alloca.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

const char *const morse[55] = {
    ".-",     "-...",   "-.-.",   "-..",     ".",      "..-.",     "--.",
    "....",   "..",     ".---",   "-.-",     ".-..",   "--",       "-.",
    "---",    ".--.",   "--.-",   ".-.",     "...",    "-",        "..-",
    "...-",   ".--",    "-..-",   "-.--",    "--..",   "-----",    ".----",
    "..---",  "...--",  "....-",  ".....",   "-....",  "--...",    "---..",
    "----.",  ".-.-.-", "--..--", "..--..",  ".----.", "-.-.--",   "-..-.",
    "-.--.",  "-.--.-", ".-...",  "---...",  "-.-.-.", "-...-",    ".-.-.",
    "-....-", "..--.-", ".-..-.", "...-..-", ".--.-.", "...---..."};
const char *const ascii[55] = {
    "A", "B", "C", "D", "E", "F", "G", "H", "I", "J",  "K", "L", "M",  "N",
    "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X",  "Y", "Z", "0",  "1",
    "2", "3", "4", "5", "6", "7", "8", "9", ".", ",",  "?", "'", "!",  "/",
    "(", ")", "&", ":", ";", "=", "+", "-", "_", "\"", "$", "@", "SOS"};

char *add_word(int start, int len, const char *str) {
  char *word = calloc(len + 1, sizeof(char));
  int k = 0;
  for (int i = start; start < start + len; start++) {
    word[k] = str[i];
    k++;
  }
  return word;
}

char *decode_morse(const char *morse_code) {

  char *array[SIZE];
  char *answer = (char *)calloc(SIZE + 1, sizeof(char));
  int answer_len = 0;
  int space_counter = 0;
  int len = 0;
  int morse_counter = 0;

  for (int i; i < strlen(morse_code); i++) {
    if (morse_code[i] == ' ') {
      space_counter++;
      morse_counter = 0;

      array[len] = add_word(i, morse_counter, morse_code);
      len++;

      continue;
    }

    // If 3 or more space encounted
    if (space_counter >= 2) {
      array[len] = " ";
      len++;
    }

    space_counter = 0;
    morse_counter++;
  }

  if (array[0] == morse[54]) {
    return "SOS";
  }

  for (int i; i < SIZE - 1; i++) {

    if (array[i][0] == " ") {

      answer[len] = ' ';
      len++;
    }

    for (int j; j < sizeof(morse) / sizeof(morse[0]); j++) {
      if (array[i] == morse[j]) {
      }
    }
  }

  return answer;
}
