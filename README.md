# TopRepeatingSubstrings

#Problem 1
 
1) Given an arbitrary binary input file calculate the top N scoring repeated binary substrings T(1..N) of length greater than or equal to L where score S is defined as the number of occurrences O multiplied by length L of the substring.  No result in T should be a substring of any other string in T.
2) Output a text file containing  lines with 3 integers, <X, L, O>  for each repeated substring in T where X is the offset of the first occurrence in the input file.
3) Explain the computational complexity of your algorithm.
4) Provide stats for performance for files from the Canturbury and Silesia corpus datasets.

Top-level Algorithm Description:
1. Construct Suffix Array
2. Construct Longest Common Prefix Array
3. Construct left array
4. Construct right array
5. Update Scores of top N repeated substring

For simplicity, I have assumed N to be small enough such that we do not need to count substrings with a single occurrence.
 
#Problem 2
 
1) Modify the algorithm in Problem 1 to output N high scoring repeated substrings, but faster.  A control parameter P in range 0.0 to 1.0 will be used to trade speed for accuracy.  Higher values of P should favor more accurate results.  Lower values faster results at the expense of accuracy.  When P = 1.0 the algorithm should give the same results as the original. 
2) Provide stats for performance for files from the Canturbury and Silesia corpus datasets for varying values of P.

Trade-off: Break the string into small pieces depending on the value of P as follows.
small_size = ceil(exp(0.5 * (p + 1.0000) * log(n)))
Process each small part independently
 
#Problem 3
 
1) Provide stats for performance when testing against the enwiki8 and enwiki9 datasets available here. 
2) If your program does not scale explain why not and suggest ways in which it could be improved.
3) Implement improvements that allow the algorithm to support these datasets.

Super-linear algorithms do not scale for the given datasets, especially enwiki9.

Improvements : 
Parallel Threads for each small string.
Use linear algorithm for suffix array construction - SA-IS algorithm - implementation by Yuta Mori.
Do cache-savvy optimizations
