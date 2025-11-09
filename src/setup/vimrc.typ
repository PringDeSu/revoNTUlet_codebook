#import "../../conf.typ": *

#CodeSpace(
  ```vimrc
  se nu rnu cin ts=4 sw=4 | sy on
  inoremap {<CR> {<CR>}<Esc>O
  nnoremap j gj
  nnoremap k gk
  colo evening
  :bad input.txt
  :let @# = 'input.txt'
  ca Hash w !cpp -dD -P -fpreprocessed \| tr -d "[:space:]" \| md5sum \| cut -c-6
 ```
)

