# RNA Secondary Structure Prediction Algorithm
### RNA (Ribonucleic acid )
* RNA is a basic biological molecule. It is single stranded.
* RNA molecules fold into complex secondary structures.
* Secondary structure often governs the behaviour of an RNA molecule.
### Rules governing secondary structure formation:
* Pairs of bases match up; each base matches with 1 other base.
* Adenine always matches with Uracil.
* Cytosine always matches with Guanine.
* There are no kinks in the folded molecule.
* Structures are knot-free.
### Problem Statement
>  Given an RNA molecule, predict its secondary structure

<b>Formulation: </b>
* An RNA molecule is a string B = b1 b2 .... bn with each bi ∈ {A,U,C,G}
* An secondary structure on B is a set of pairs S = {(i,j)}, where 1≤i , j≤n and satisfies the following rules.
> * (No sharp turns) The ends of each pair are separated by at least 4 intervening bases i.e if (i,j) ∈ S, then i<j-4.
> * The elements in each pair in S consist of either {A,U} or {C,G} (in either order).
> * S is a matching: no base appears in more than one pair.
> * (No knots) If (i,j) and (k,l) are two pairs in S, then we cannot have i < k < j < l .

### Recurrence Relation
* OPT(i,j) = max(OPT(i,j-1), max(1+OPT(i,t-1)+OPT(t+1,j-1))) where 1≤i≤n-5 and 6≤j≤n; we aim to find OPT(1,n)
* OPT(i,j) = 0 when j-i≤4

### Algorithm
```cpp
1.  Initialize OPT(i,j) = 0 whenever j-4 ≤ i
2.  For k = 5,6,...,n-1
3.      For i = 1,2,..,n-k
4.          Set j = i+k
5.          Compute OPT(i,j)
6.      Endfor
7.  Endfor
8.  Return OPT(1,n)
```
### Compilation
```sh
make clean && make
./output
```

### Testcases
[RNA Molecules](http://ndbserver.rutgers.edu/service/ndb/atlas/gallery/rna?polType=all&rnaFunc=all&protFunc=all&strGalType=rna&expMeth=all&seqType=all&galType=table&start=0&limit=50)

```py
#test case 1
input: GGCGAAGAACCGGGGAGCC
Predicted pairings: 4
0-18 (G-C)
1-17 (G-C)
2-11 (C-G)
3-9 (G-C)

#test case 2
input: GGGUGUAGAAAAGUAAGGGAAACUCAAACCCCUUUCUACACCC
Predicted pairings: 15
0-42 (G-C)
1-41 (G-C)
2-40 (G-C)
3-39 (U-A)
4-38 (G-C)
5-37 (U-A)
6-36 (A-U)
7-35 (G-C)
8-34 (A-U)
9-33 (A-U)
10-32 (A-U)
12-28 (G-C)
13-25 (U-A)
14-23 (A-U)
16-22 (G-C)

#test case 3
input: UCGUGCGA
Predicted pairings: 2
0-7 (U-A)
1-6 (C-G)

#test case 4
input: GGACUCGACUCC
Predicted pairings: 3
0-11 (G-C)
1-10 (G-C)
2-9 (A-U)

#test case 5
input: UGCUCCUAGUACGAGAGGACCGGAGUG
Predicted pairings: 7
2-24 (C-G)
3-23 (U-A)
4-22 (C-G)
5-21 (C-G)
8-19 (G-C)
9-18 (U-A)
11-16 (C-G)
```

# Project Team

- [Ankita Behera](https://github.com/rxndom266/)
- [Durba Satpathi](https://github.com/durba-s)
- [Prakhar Agarwal](https://github.com/PrAkHaR-BitsPilani)

```cpp
/**
 * Ankita Behera 2019A7PS0075H
 * Durba Satpathi 2019A7PS0972H
 * Prakhar Agarwal 2019A7PS0174H
 **/
```
