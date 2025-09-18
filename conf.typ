#import "@preview/zebraw:0.5.4": *

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

#let CodeBlocks(name, filename) = {
  heading(level: 2, name)
  CodeSpace(
    raw(
      block: true,
      lang: "c++",
      read(filename)
    )
  )
}


