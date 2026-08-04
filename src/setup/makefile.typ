#import "../../conf.typ": *

#CodeSpace(
  ```make
  .SUFFIXES:
  .PHONY: force
  %: %.cpp force
    vim $< && g++ $< -D MIKU && ./a.out < ./input.txt
  %f: %.cpp force
    vim $< && g++ -fsanitize=address,undefined -g -D MIKU $< && ./a.out < ./input.txt
  ```
)

