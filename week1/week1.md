# Algorithms

### What is an algorithm?

An algorithm is a procedure, recipe, process to accopmplish a task. It takes value as input and delivers a value as output.

### How to develop an algortihm?

The development of an algorithm has four crucial steps:

1. **Specifiaction**: Be clear what the problem is
2. **Design**: Specify structure of the solution, usually in pseudcode
3. **Development**: Convert pseudocode in chosen language (C, Python, Java etc.)
4. **Testing**:  if all inputs deliver all necessary outputs

#### Example: Linear search in Pseudocode

```Pseudocode
                                    # Linear search last occurence
    p = NIL;                        # Here we are defining our variable p as 0
    for i = 1 to n do               # For the range of 1 to n in our array A
        if A[i]==v then p=i;        # we are checking the values (v) 
    return p;                       # If we find a value which matches our input 
                                    # we set it equal to p and return it
```

```Pseudocode
                                            # Linear search first occurence
    i = 1;                                  # Set i to 1. While i is less
    while i <= n and A[i] != v do i++;      # or equal number of array elements
    if i <= n then return i;                # and there is no match in value
    else return NIL;                        # with the array, keeping adding 1.
                                            # If I is less or equal n, return n
                                            # else return 0.
```

### Prime number filter

### Sorting algotihms

#### Bubble sort

#### Selection sort

#### Insertion sort
