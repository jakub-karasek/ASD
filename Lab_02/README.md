# Cellular sorting (Sortowanie komórkowe)
- `sor.cpp` - solution to cellular sorting (sortowanie komórkowe) problem

## Original task description
[original task (in polish)](./sor.pdf)

## Task: Cellular Sorting

Cellular sorting is a very interesting algorithm with relatively high time complexity for a sorting algorithm. This algorithm works step by step, meaning it performs a certain step (a sequence of operations) on a given sequence until the sequence becomes sorted in non-decreasing order.

The sorting step works as follows: we analyze the sequence from left to right, and on the side, we build the result sequence for that step. Initially, we place the first element of the current sequence into the result sequence, and then each subsequent element is placed either at the beginning of the auxiliary sequence if the previous element in the original sequence was greater than it, or at the end if the previous element was smaller.

For example, in one step of the algorithm, starting with the sequence: `5, 6, 2, 1, 4, 3`, the auxiliary sequences are constructed as follows:

- `5`
- `5, 6`
- `2, 5, 6`
- `1, 2, 5, 6`
- `1, 2, 5, 6, 4`
- `3, 1, 2, 5, 6, 4`

The last sequence is the result of this step of the algorithm.

Your task is to "unsort" a given sequence, which means determining how many different sequences transform into the given sequence in a single step of the cellular sorting algorithm.

## Input

- The first line of input contains a single integer `n` (`1 ≤ n ≤ 1000`).
- The second line contains a sequence of `n` pairwise distinct integers from the set `{1, ..., n}`, representing the sequence that needs to be "unsorted."

## Output

- You should output the remainder of the division by `10^9` of the number of different sequences that transform into the given sequence in a single step of cellular sorting.
