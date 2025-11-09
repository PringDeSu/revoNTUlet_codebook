#import "@preview/zebraw:0.5.4": *
#import "@preview/digestify:0.1.0": *

#let VAR_TEAM_NAME = "National Taiwan University - revoNTUlet"

#let CodeSpace(args) = text(
  size: 9pt,
  block(
    stroke: (left: 1pt + black),
    outset: (2pt),
    zebraw(
      background-color: (rgb(0, 0, 0, 0)),
      indentation: 4,
      numbering: false,
      lang: false,
      args
    )
  )
)

#let FileMd5(filename) = {
  let content = read(filename)
    .split("\n")
    .map(line => line.split("//").first())
    .join("\n")
    .replace(regex("\\s"), "")
  
  let file_hash = md5(bytes(content))
  bytes-to-hex(file_hash)
}

#let CodeBlocks(name, filename) = {
  heading(
    level: 2, 
    supplement: [
      \[#FileMd5(filename).slice(0, 5)\]
    ],
  )[#name]
  CodeSpace(
    raw(
      block: true,
      lang: "c++",
      read(filename)
    )
  )
}

