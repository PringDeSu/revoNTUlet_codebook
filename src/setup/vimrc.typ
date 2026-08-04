#import "../../conf.typ": *

#CodeSpace(
  ```vimrc
  se nu rnu cin ts=4 sw=4 | sy on
  inoremap {<CR> {<CR>}<Esc>O
  colo evening
  bad input.txt
  let @# = 'input.txt'
  ca Hash w !cpp -dD -P -fpreprocessed \| tr -d "[:space:]" \| md5sum \| cut -c-5
  "colo zaibatsu
  "let loaded_matchparen = 1
  ```
)

