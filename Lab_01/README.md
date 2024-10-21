# Warm-up assignments
- `Bazar.cpp` - solution to "bazarek" problem
- `Matryca.cpp` - solution to "matryca" problem

## "Bazarek" assignment
### Original task description
[original task (in polish)](./Lab_01/bazarek.pdf)

### Task: Grandma Bajtula's Market Shopping

**Little Bajtek spends his vacation at Grandma Bajtula's house. Every morning, Grandma goes to the market to buy certain products. The boy quickly noticed an interesting pattern: every day, Grandma spends an odd integer amount on her shopping. Bajtek soon realized that this pattern is a characteristic feature of all grandmas in Bajtek's land.**

Each day, Grandma Bajtula buys at most one of each of the `n` available products at the market. Grandma, being careful, doesn't want to take too much money for shopping. One day, she asked Bajtek for advice on how much money she needs to bring if she wants to buy exactly `k` products from the market that day. Unfortunately, Bajtek doesn't know which products Grandma intends to buy, so the amount of money must be enough to cover any combination of `k` products (ensuring that the total cost is odd). This situation repeated itself several times. So Bajtek decided to approach the problem methodically and write a program that, given the prices of all products available at the market, would answer Grandma’s questions.

### Input

- The first line of input contains a single integer `n` (1 ≤ n ≤ 1,000,000) representing the number of products available at the market.
- The second line contains `n` integers in the range [1, 1,000,000,000], representing the prices of the respective products. These numbers are given in non-decreasing order.
- The third line contains a single integer `m` (1 ≤ m ≤ 1,000,000) representing the number of days Bajtek will still spend with Grandma.
- Each of the next `m` lines contains a single integer `k_i` (1 ≤ k_i ≤ n), representing the number of products Grandma plans to buy on the `i`-th day.

### Output

Your program should output `m` lines. In the `i`-th line (for i = 1, . . . , m), there should be one integer representing the maximum odd total cost for selecting exactly `k_i` products. If it's impossible to select `k_i` products such that their total cost is odd, the `i`-th line should contain `-1`.

## "Matryca" assignment
### Original task description
[original task (in polish)](./Lab_01/matryca.pdf)

### Task: Bajtocki Printing House's Striped Wallpaper

**The Bajtocki Printing House (BZP) received a large order for producing striped wallpapers, which are the hit of the season in interior design. Each wallpaper consists of `n` vertical stripes of the same width but different colors. The BZP is responsible for designing and printing these wallpapers. The client has predetermined the colors of some stripes on the wallpaper, while leaving the colors of other stripes entirely up to BZP.**

At BZP, wallpapers are printed using a matrix that prints a certain number of consecutive stripes on the wallpaper. The matrix defines the color for each stripe it prints, and it may be shorter than the entire wallpaper. If the matrix consists of `k` stripes, it is applied to all possible positions where its stripes align with the wallpaper, printing all the stripes of the matrix at each position. In this way, a single stripe on the wallpaper may be printed multiple times. If a stripe is printed in different colors, its final color will be a blend of those colors.

The workers at BZP, regardless of their sense of aesthetics, primarily want to design the shortest possible matrix that can print the entire wallpaper. They must also ensure that for any stripe specified by the client, the printed color matches the specified color exactly, without any blending. In other words, whenever the matrix covers a stripe with a specified color, the color of the corresponding stripe on the matrix must match the client's specification.

### Input

- The only line of input contains a string composed of uppercase Latin letters and asterisks (`*`), which represents the desired appearance of the wallpaper. Each letter represents a specific stripe color, while the asterisks represent stripes whose color was not specified by the client.
- The length of the string `n` satisfies `1 ≤ n ≤ 1,000,000`.

### Output

- Your program should output a single integer `k`: the minimum length of the matrix that allows the entire wallpaper to be printed as required.

