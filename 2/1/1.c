#include <stdio.h>

int htoi(char s[]) {
    int number;
    sscanf(s, "%x", &number);
    return number;
}

int main() {
  int htoi();
  printf("htoi('9a8fc') = %d\n", htoi("9a8fc"));
  printf("htoi('f') = %d\n", htoi("f"));
  printf("htoi('F0') = %d\n", htoi("F0"));
  printf("htoi('12fab') = %d\n", htoi("12fab"));
}
