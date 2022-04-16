# RNA Secondary Structure Prediction Algorithm
### RNA (Ribonucleic acid )
* RNA is a basic biological molecule. It is single stranded.
* RNA molecules fold into complex secondary structures.
* Secondary structure often governs the behaviour of an RNA molecule.
### Various rules govern secondary structure formation:
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
1. Initialize OPT(i,j) = 0 whenever j-4 ≤ i
2. For k = 5,6,...,n-1
3.      For i = 1,2,..,n-k
4.          Set j = i+k
5.          Compute OPT(i,j)
6.      Endfor
7. Endfor
8. Return OPT(1,n)

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
