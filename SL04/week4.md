# Heap sort

## What is a binary tree?

![](08_04_2021_20.12.png){ width=350px }

```C
A = [2, 7, 5, 2, 6, 9, -, -, 5, 11, 4]

node at index i
left child at index 2*i
right child at index (2*i+1)
parent at floor(i/2)
```

We start at the root of the tree (2), and then display the left (7) and right (5) child of the root. Each node is not allowed to have more than one parent. The only node, which has no parent, is the root. A leaf is an element (here 2, 5, 11, 4) which has no children.

The depth of a binary tree is the level where an element sits. The root is level 0. The height of the binary tree is determined what the longest path of a node to a leaf is. The root is level 1.

## How do you build a heap?

Heaps can be found in 2 variations, max heaps and min heaps.

![](08_04_2021_21.08.png)  

### Complete binary trees

A complete binary tree is a tree where every node has 2 child elements.
The formula for each level is $2^k$ - this means a binary tree with 3 levels has $2^3=8$ elements.

### Nearly complete binary trees

A nearly complete binary tree has all elements need upto the $k-1$ level. The last level must have it's children as far left as possible. 

## Heapify

Heapify is the process used to "clean up" an unsorted binary tree. By default, we sort it to a Max Heap. 

```C
void Heapify(int A[], int i, int s){
    int m = i;
    int l = Left(i);
    int r = Right(i);

    // Checks if left exists and if left elements is larger than parent
    if (l < s && A[l] > A[m]){
        m = l;
    }

    // Checks if right exists and if right elements is larger than parent
    if (r < s && A[r] > A[m]){
        m = r;
    }


    if (i != m){
        exchange(A[i], A[m]);
        Heapify(A, m, s);
    }
}
```

# Quick sort
```C
void QuickSort(int A[], int n, int l, int r){
    if (l<r){
        int m = LomutoPartition(A, n, l, r) || HoarePartition(A, n, l, r);
        QuickSort(A, n, l, m-1); // smallest Elements
        QuickSort(A, n, m+1, r)  // largest Elements
        // Important no Merge needed at the end
    }
}


int LomutoPartition(int A[], int n, int l, int r){
    int x = A[r]; 
    // middle element (pivot) 
    // (we take rightmost element as middle element)
    int i = l-1;
    for(int j=l; j< r-1; j++){ 
        // elements l..r-1 are inserted into 
        // either the smaller or larger part
        i = i+1; 
        // smaller part grows by one
        exchange(A[i], A[j]);
    }
    exchange(A[i+1], A[r]); // putting pivot in right place
    return i+1;
}


int HoarePartition(int A[], int n, int l, int r){
    int x = A[r];
    int i = l-1;
    while (true){
        repeat j=j-1 until A[j] < x; 
        // searches in the right part for a wrong 
        // (too small) element
        repeat i=i+1 until A[i] > x; 
        // searches int he left part for a wrong 
        // (too large) element
        if (i < j){
            exchange(A[i], A[j]); // Swap of "wrong" elements
        } else {
            return i;
        }
    }

}
```

The basic idea of Quicksort is chosing an element 'pivot', this element pivot allows us to sort the array based on the value of this element. What we then do, is set our first element in the array to the variable $i$ and the last element to $j$. We then keep moving i and j, i until an element is found where $i > pivot$ and same for $j \leq pivot$. We then exchange the elements $j$ and $i$ with each other as long as $j$ and $i$ dont cross. Once they cross, we know the correct place for our pivot element. We can then guarantee, that the right side of pivot is all elements greater than pivot, but is unsorted. The left side is smaller than pivot, and also unsorted. We then "create" 2 arrays and sort them individually.

## Lomuto partitioning

## Hoare partitioning