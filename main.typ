#import "@preview/grayness:0.4.0": image-transparency
#import "conf.typ": *

#set page(
  header: text(size: 12pt, {
    emph(VAR_TEAM_NAME)
    h(1fr)
    context(counter(page).display("1"))
    line(length: 100%)
  }),
  margin: (x: 1cm, top: 2cm, bottom: 1cm),
  columns: 2,
  background: image-transparency(read("src/misc/icon.png", encoding: none), alpha: 20%, width: 75%),
)
#set columns(gutter: 5pt)


//////////////////////////////////////////////////////////////////////////
//                                CONTENT                               //
//////////////////////////////////////////////////////////////////////////

#set heading(numbering: "1.1")
#set heading(supplement: none)
#block(height: 520pt, columns(2, gutter: 8pt, outline()))

#show heading: it => {
  block(
    above: 1.2em,
    below: 0.6em,
    {
      if it.numbering != none {
        counter(heading).display(it.numbering)
        h(0.5em)
      }
      it.body
      if it.supplement != none {
        h(0.5em)
        it.supplement
      }
    }
  )
}

= Setup
== Remap Escape
#include "src/setup/escape.typ"
== vimrc
#include "src/setup/vimrc.typ"
#CodeBlocks("default code", "src/setup/tpl.cpp")
== Makefile
#include "src/setup/makefile.typ"

= Graph
// tested at https://judge.yosupo.jp/submission/313269
#CodeBlocks("Block Cut Tree", "src/graph/block_cut_tree.cpp")
// tested at https://codeforces.com/group/16AkdQqf1V/contest/631725/problem/1A
#CodeBlocks("Dinic", "src/graph/dinic.cpp")
// tested at https://codeforces.com/group/79niCea2aI/contest/548168/problem/R
#CodeBlocks("Dominator Tree", "src/graph/dominator_tree.cpp")
// tested at https://ntuj.csie.org/contests/4/problems/3426
#CodeBlocks("Euler Tour", "src/graph/euler_tour.cpp")
// tested at https://codeforces.com/group/79niCea2aI/contest/552133/problem/O
#CodeBlocks("Gomory Hu", "src/graph/gomory_hu.cpp")
// tested at https://codeforces.com/group/79niCea2aI/contest/548168/problem/S
#CodeBlocks("Incremental SCC", "src/graph/incremental_scc.cpp")
// tested at https://ntuj.csie.org/contests/1/problems/3676
#CodeBlocks("KM", "src/graph/km.cpp")
// tested at https://ntuj.csie.org/contests/4/problems/3423
#CodeBlocks("Max Clique", "src/graph/max_clique.cpp")
// tested at https://codeforces.com/group/16AkdQqf1V/contest/628697/problem/T
#CodeBlocks("Minimum Cost Maximum Flow", "src/graph/mcmf.cpp")
// tested at https://judge.yosupo.jp/submission/327539
#CodeBlocks("Minimum Cost Maximum Flow", "src/graph/general_matching.cpp")

= Data Structure
// reference : 8BCube
// tested at https://judge.yosupo.jp/submission/395549
#CodeBlocks("Cartesian Tree", "src/data_structure/cartesian.cpp")
// tested at https://judge.yosupo.jp/submission/238643
#CodeBlocks("Dynamic Convex Hull", "src/data_structure/dynamic_convex_hull.cpp")
// tested at https://judge.yosupo.jp/submission/239483
#CodeBlocks("Link Cut Tree", "src/data_structure/lct.cpp")
// tested at https://judge.yosupo.jp/submission/318108
#CodeBlocks("Li Chao", "src/data_structure/li_chao.cpp")
// tested at https://judge.yosupo.jp/submission/239343
#CodeBlocks("Splay", "src/data_structure/splay.cpp")
// tested at https://judge.yosupo.jp/submission/238822
#CodeBlocks("Treap", "src/data_structure/treap.cpp")
// tested at https://judge.yosupo.jp/submission/394838
#CodeBlocks("ETT", "src/data_structure/ett.cpp")
// not tested yet
#CodeBlocks("Quadrangle", "src/data_structure/quadrangle.cpp")
// not tested yet
#CodeBlocks("SMAWK", "src/data_structure/smawk.cpp")

= Geometry
// not tested yet
#CodeBlocks("Point", "src/geometry/point.cpp")
// tested at https://judge.yosupo.jp/submission/318115
#CodeBlocks("Convex Hull", "src/geometry/convex_hull.cpp")
// tested at https://codeforces.com/gym/106059/problem/A
#CodeBlocks("Tangent of Convex Hull", "src/geometry/tangent.cpp")
// not tested yet
#CodeBlocks("Point In Convex", "src/geometry/point_in_convex.cpp")
// tested at https://codeforces.com/group/79niCea2aI/contest/542496/problem/M
#CodeBlocks("Minkowski Sum", "src/geometry/minkowski.cpp")
// tested at https://codeforces.com/gym/613669/problem/F
#CodeBlocks("Half Plane Intersection", "src/geometry/half_plane_intersect.cpp")
// tested at https://codeforces.com/group/16AkdQqf1V/contest/632330/problem/C
#CodeBlocks("Min Enclosing Circle", "src/geometry/min_enclosing_circle.cpp")
// not tested yet
#CodeBlocks("Tangent Of Two Circles", "src/geometry/tangent_of_two_circles.cpp")
// not tested yet
#CodeBlocks("Circle Cover", "src/geometry/circle_cover.cpp")
// not tested yet
#CodeBlocks("Simulated Annealing", "src/geometry/simulated_annealing.cpp")


= String
// tested at https://cses.fi/problemset/task/2107
#CodeBlocks("Z Algorithm", "src/string/z_alg.cpp")
// tested at https://cses.fi/problemset/task/2107
#CodeBlocks("KMP", "src/string/kmp.cpp")
// tested at https://cses.fi/problemset/task/2103
#CodeBlocks("Aho Corasick", "src/string/aho_corasick.cpp")
// tested at https://cses.fi/problemset/task/3138
#CodeBlocks("Manacher", "src/string/manacher.cpp")
// tested at https://judge.yosupo.jp/problem/longest_common_substring
#CodeBlocks("Suffix Array", "src/string/suffix_array.cpp")
// not tested yet
#CodeBlocks("SAM", "src/string/SAM.cpp")
// not tested yet
#CodeBlocks("eertree", "src/string/eertree.cpp")
// tested at https://cses.fi/problemset/task/1110/
#CodeBlocks("minimal rotation", "src/string/minimal_rotation.cpp")

= Math
// not tested yet
#CodeBlocks("Euclid", "src/math/euclid.cpp")
// tested at https://cses.fi/problemset/task/2111
#CodeBlocks("FFT", "src/math/fft.cpp")
// tested at https://judge.yosupo.jp/problem/bitwise_and_convolution
// tested at https://judge.yosupo.jp/problem/bitwise_xor_convolution
#CodeBlocks("FWT", "src/math/fwt.cpp")
// tested at https://ntuj.csie.org/contests/4/problems/3429
#CodeBlocks("Pollard Rho", "src/math/pollard_rho.cpp")
// tested at https://judge.yosupo.jp/problem/sum_of_floor_of_linear
#CodeBlocks("Floor Sum", "src/math/floor_sum.cpp")

= Polynomial
// tested at https://judge.yosupo.jp/problem/convolution_mod
#CodeBlocks("NTT", "src/polynomial/ntt.cpp")
// tested at https://judge.yosupo.jp/problem/convolution_mod_1000000007
#CodeBlocks("Chinese Remainder Theorem", "src/polynomial/crt.cpp")
// tested at https://judge.yosupo.jp/problem/convolution_mod
#CodeBlocks("FPS base", "src/polynomial/fps-base.cpp")
// tested at https://judge.yosupo.jp/problem/inv_of_formal_power_series
// tested at https://judge.yosupo.jp/problem/division_of_polynomials
#CodeBlocks("FPS div", "src/polynomial/fps-div.cpp")
// tested at https://judge.yosupo.jp/problem/log_of_formal_power_series
// tested at https://judge.yosupo.jp/problem/exp_of_formal_power_series
#CodeBlocks("FPS exp", "src/polynomial/fps-exp.cpp")
// tested at https://judge.yosupo.jp/problem/pow_of_formal_power_series
#CodeBlocks("FPS pow", "src/polynomial/fps-pow.cpp")

= Ideograph Advantage
// tested at 2025 Taichung Regional
#CodeBlocks("3d Donut", "src/misc/donut.c")

#pagebreak()
= Notes
#include "src/notes/notes.typ"
