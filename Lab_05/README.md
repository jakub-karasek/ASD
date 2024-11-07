# Task: KIN
## k-Inversions
ASD Lab 5. Available memory: 64 MB. Deadline: 01.12.2024, 23:59:59

Let 
𝑎
1
,
𝑎
2
,
…
,
𝑎
𝑛
a 
1
​
 ,a 
2
​
 ,…,a 
n
​
  be a permutation of the numbers from 1 to 
𝑛
n. A k-inversion in this permutation is defined as a sequence of indices 
𝑖
1
,
𝑖
2
,
…
,
𝑖
𝑘
i 
1
​
 ,i 
2
​
 ,…,i 
k
​
  such that 
1 ≤ i1 < i2 < . . . < ik ≤ n and ai1 > ai2 > . . . > aik

Your task is to determine the number of k-inversions in the given permutation.

## Input:

The first line of the input contains two integers 
𝑛
n and 
𝑘
k (1 ≤ 
𝑛
n ≤ 20,000, 2 ≤ 
𝑘
k ≤ 10). The second line contains a permutation of the numbers from {1, . . . , n}.

## Output:

Your program should output the remainder of the number of k-inversions in the given permutation when divided by 
1
0
9
10 
9
 .

## Example:

For the input:

```
4 3
4 3 1 2
```

The correct output is:

```
2
```

For the input:

```
6 3
6 5 3 1 4 2
```

The correct output is:

```
10
```