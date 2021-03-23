# Divide and conquer

Divide and conquer has 3 central steps

- Divide into subproblems
- Concquer subproblems with recursive solution
- Combine solution of subproblems into solution for the original problem

## Merge sort

- Divide: divide the sequence into two $n/2$-element sequences
- Conquer: sort the two sequences recursively using merge sort
- Combine: merge the two sorted sequences to produce the solution

![](d3effe671f3b0094cb6cd137087b75c687412e14c4f99a57c06de3c90a7348e0.png){ width=350px }


```
Algorithm MergeSort(l, h)
{
    if(l<h)
    {
        mid = (l+h)/2;
        MergeSort(l, mid)
        MergeSort(mid + 1, h)
        Merge(l, mid, h)
    }
}
```

Time complexity for Merge Sort is $\Theta (n\log{}n)$. The logic behind this is determined from the recursion calls. With 8 elements split into "groups" of 2 elements each, we have 3 levels, where a merge happens $(2^3 = 8)$.

# Reccurences

The running times of algorithms with recursive calls can be described using recurrences. There exist 4 basic ways how we can get to the reuccurence formula:

- Repeated (backward) substitution: Expand the recurrence by substitution and then notice the pattern
- Substitution method: Guess a bound and then use induction to prove that the guess is correct
- Recursion trees: Convert a recurrence in a tree whose nodes represent the costs
- Master method: Templates for different classes of recurrences

## Repeated substitution

## Substitution method

## Recursion trees

## Master method

### Case 1

### Case 2

### Case 3