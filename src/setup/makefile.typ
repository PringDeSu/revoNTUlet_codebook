#import "../../conf.typ": *

#CodeSpace(
  ```make
  .SUFFIXES:
  .PHONY: force
  %: %.cpp force
    vim $< && g++ $< -std=c++20 -D MIKU && ./a.out < ./input.txt
  %f: %.cpp force
    vim $< && g++ -std=c++20 -fsanitize=address,undefined -g -Wall -Wextra -Wshadow -D MIKU $< && ./a.out < ./input.txt
  ```
)

