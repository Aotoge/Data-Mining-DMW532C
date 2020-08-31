# Lab 0
## Data Mining Basics - Apriori Algorithm

![](https://img.shields.io/badge/language-C%2B%2B-ff69b4)

### Contents
* [Apriori Algorithm](#apri)
* [Apriori Algorithm using Hash Function](#hash)
* [Frequent Set Generation](#freq)
* [Apriori Algorithm on Integrated and Partioned Sets](#int)

___

<a name="apri"></a>
## Apriori Algorithm
Implement Apriori algorithm for association rules. Run the algorithm with two different support and confidence levels defined by you.

* Print closed itemset
* Print closed frequent itemset

Implement the problems using C++/Java. Any of chess, mushroom or retail datasets may be used for the same.
___

<a name="hash"></a>
## Apriori Algorithm using Hash Function
Implement Apriori algorithm for association rules using hash function. Run the algorithm with two different user defined support and confidence level to find frequent item sets from L<sub>2</sub> and C<sub>2</sub>. Any of chess, mushroom or retail dataset can be used.

___

<a name="freq"></a>
## Frequent Set Generation
Consider a set of items from the alphabet: {A, B, C, D, E} and the collection of frequent sets, S = {{A},{B},{C},{E},{A,B},{A,C},{A,E},{C,E},{A,C,E}}.

Find negative and positive collection of frequent sets.
___

<a name="int"></a>
## Apriori Algorithm on Integrated and Partioned Sets
Use partitioning to divide a data set in two partitions. Apply Apriori algorithm and compare the frequent pattern results between integrated and partitioned data sets.
___


NOTE:

Let,
<img src="https://render.githubusercontent.com/render/math?math=Y\subseteq I">
and
<img src="https://render.githubusercontent.com/render/math?math=X\subseteq Y">
If the X is an infrequent itemset, then Y is also an infrequent itemset. On that basis apply the Apriori algorithm.
