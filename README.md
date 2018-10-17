# filler

filler 1v1 game algorithms

## goal

> Filler is an algorithmic game that consists of filling a grid of a known size
in advance with pieces of random size and shapes, without the pieces overlapping each other
more than one box and without them exceeding the grid. If one of
these conditions is not fulfilled, the game stops.
Each piece posed successfully yields a number of points, and has a single
player, the goal of the game could be to get the highest score possible. Cepedant is
with two players the filler takes all its interest. Each player aims to pose
a maximum of coins while trying to prevent his opponent from doing so. At the end of
the party, the one with the most point wins the match ...

This project generate a pleroux.filler that listen on stdin and print the X,y position in stdout

The game board provided with the pdf file execute each player and send the right information on stdout

## Algo learning

- manhattan distance
- Surrounded concurrent by custom algo

The correction goals is to beat the concurrent provided during the peer correction 

## demo game board

```
Plateau 14 30:
012345678901234567890123456789
000 ..............................
001 ..............................
002 ..............................
003 ..............................
004 ..............................
005 ..............................
006 ..............................
007 ..............................
008 ...............O..............
009 ..............................
010 ..............................
011 ..............................
012 ..............................
013 ..............................
Piece 4 7:
...*...
...*...
...*...
..***..
```

## time flow

- about 1 weeks

## ressources

- [PDF in French](https://cdn.intra.42.fr/pdf/pdf/634/filler.fr.pdf)
- [Flowchart in part](https://drive.google.com/file/d/1qx1nmhlSYHkxPzVJuGS9yMbfxsHNfem5/view?usp=sharing)
