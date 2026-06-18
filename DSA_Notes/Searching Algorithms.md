
## 1) Linear Search Notes

### Definition
**Linear Search** (also called **Sequential Search**) is a simple algorithm that finds a target value within a list by checking each element sequentially from beginning to end until a match is found or the list ends.
### Key Characteristics

| Property | Description |
|----------|-------------|
| **Type** | Searching algorithm |
| **Data Structure** | Array, List, or any sequential collection |
| **Precondition** | No sorting required - works on unsorted data |
| **Stability** | Finds first occurrence (can be modified for all occurrences) |

### Algorithm Steps

1. Start from the **first element** of the array
2. Compare the current element with the **target value**
3. If **match found** → return the index (or element)
4. If **no match** → move to the next element
5. Repeat steps 2-4 until:
   - Target is found, OR
   - End of array is reached
6. If end reached with no match → return **-1** or "not found"
### Pseudocode

```
function linearSearch(array, target):
    for i from 0 to length(array) - 1:
        if array[i] == target:
            return i       
    return -1               
```


### Implementation Examples

### C++
```cpp
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}
```

### Time & Space Complexity

| Complexity | Best Case | Average Case | Worst Case |
| ---------- | --------- | ------------ | ---------- |
| **Time**   | O(1)      | O(n)         | O(n)       |
| **Space**  | O(1)      | O(1)         | O(1)       |

#### Explanation:
- **Best Case (O(1))**: Target is the first element
- **Worst Case (O(n))**: Target is the last element or not present
- **Average Case (O(n))**: Target is somewhere in the middle
- **Space Complexity**: Constant - no extra memory needed


## Binary Search Notes

### Definition
**Binary Search** is an efficient searching algorithm that finds a target value within a **sorted** array by repeatedly dividing the search interval in half. It compares the target with the middle element and eliminates half of the remaining elements in each step.
## Key Characteristics

| Property | Description |
|----------|-------------|
| **Type** | Divide and Conquer algorithm |
| **Data Structure** | Array (requires random access) |
| **Precondition** | **Array MUST be sorted** (ascending or descending) |
| **Stability** | Returns any occurrence (can be modified for first/last) |

## Algorithm Steps

1. Find the **middle element** of the array
2. Compare the middle element with the **target**
3. If **match found** → return the index
4. If **target < middle** → search in the **left half**
5. If **target > middle** → search in the **right half**
6. Repeat steps 1-5 on the reduced subarray
7. If search space is exhausted → return **-1** (not found)
## Visual Example

**Array**: [2, 5, 8, 12, 16, 23, 38, 56, 72, 91]  
**Target**: 23  
**Sorted**:  Ascending

```
Step 1: [2, 5, 8, 12, 16, 23, 38, 56, 72, 91]
         ↑              ↑                    ↑
         Low          Mid(16)              High
         23 > 16 → Search RIGHT half

Step 2: [23, 38, 56, 72, 91]
          ↑    ↑        ↑
         Low  Mid(56) High
         23 < 56 → Search LEFT half

Step 3: [23, 38]
          ↑   ↑
         Low Mid(38)
         23 < 38 → Search LEFT half

Step 4: [23]
          ↑
        Low/Mid/High
         23 == 23 → FOUND at index 5 
```

## Implementation Examples

### C++
```cpp
int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}
```

## Time & Space Complexity

| Complexity | Best Case | Average Case | Worst Case |
|------------|-----------|--------------|------------|
| **Time (Iterative)** | O(1) | O(log n) | O(log n) |
| **Time (Recursive)** | O(1) | O(log n) | O(log n) |
| **Space (Iterative)** | O(1) | O(1) | O(1) |
| **Space (Recursive)** | O(log n) | O(log n) | O(log n) |

### Explanation:
- **Best Case (O(1))**: Target is the middle element
- **Worst/Average (O(log n))**: Each step eliminates half the elements
- **Space Iterative**: Constant memory
- **Space Recursive**: O(log n) due to call stack

## Mathematical Analysis

**Number of comparisons**: log₂(n) + 1

Example:
- n = 1,000,000 → ~20 comparisons
- n = 1,000,000,000 → ~30 comparisons

**Why O(log n)?**
```
n → n/2 → n/4 → n/8 → ... → 1
After k steps: n/2^k = 1
k = log₂(n)
```

---

## Advantages

 **Very fast** - O(log n) time complexity  
 **Efficient** - Even for very large datasets  
 **Minimal comparisons** - Great for expensive comparisons  
 **Space efficient** - Iterative version uses O(1)  
 **Predictable** - Consistent performance  
 **Cache-friendly** - Sequential memory access  

---

## Disadvantages

 **Requires sorted array** - Must sort first (O(n log n) overhead)  
 **Poor for small arrays** - Simple linear search may be faster  
 **Insertion/Deletion** - Costly in arrays (O(n) shift)  
 **Not for linked lists** - No random access  
 **Not for unsorted data** - Cannot be used directly  

---

## When to Use Binary Search

-  Array is **already sorted** or sorting once is acceptable
-  **Large dataset** (n > 100)
-  Multiple search operations on the **same dataset**
-  Random access data structures (**arrays**)
-  When **performance** is critical
-  Static data (no frequent insertions/deletions)

---

## Common Variations

### 1. First Occurrence (Lower Bound)
```python
def first_occurrence(arr, target):
    low, high = 0, len(arr) - 1
    result = -1
    
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == target:
            result = mid
            high = mid - 1  # Search left for earlier occurrence
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1
    
    return result
```

### 2. Last Occurrence (Upper Bound)
```python
def last_occurrence(arr, target):
    low, high = 0, len(arr) - 1
    result = -1
    
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == target:
            result = mid
            low = mid + 1  # Search right for later occurrence
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1
    
    return result
```

### 3. Count Occurrences
```python
def count_occurrences(arr, target):
    first = first_occurrence(arr, target)
    if first == -1:
        return 0
    last = last_occurrence(arr, target)
    return last - first + 1
```

### 4. Search in Rotated Sorted Array
```python
def search_rotated(arr, target):
    low, high = 0, len(arr) - 1
    
    while low <= high:
        mid = (low + high) // 2
        
        if arr[mid] == target:
            return mid
        
        # Check if left half is sorted
        if arr[low] <= arr[mid]:
            if arr[low] <= target < arr[mid]:
                high = mid - 1
            else:
                low = mid + 1
        # Right half must be sorted
        else:
            if arr[mid] < target <= arr[high]:
                low = mid + 1
            else:
                high = mid - 1
    
    return -1
```

### 5. Binary Search on Answer (Minimize/Maximize)
Used for optimization problems:
```python
def can_place_flowers(flowers, n, distance):
    # Check if possible
    pass

def min_distance(flowers, n):
    low, high = 0, max(flowers) - min(flowers)
    result = -1
    
    while low <= high:
        mid = (low + high) // 2
        if can_place_flowers(flowers, n, mid):
            result = mid
            low = mid + 1
        else:
            high = mid - 1
    
    return result
```

## Comparison with Linear Search

| Aspect                | Binary Search         | Linear Search  |
| --------------------- | --------------------- | -------------- |
| **Time**              | O(log n)              | O(n)           |
| **Sorted Required**   | Yes                   |  No            |
| **Best Case**         | O(1) - Middle         | O(1) - First   |
| **Worst Case**        | O(log n)              | O(n)           |
| **Data Structure**    | Array (random access) | Any sequential |
| **Space**             | O(1) or O(log n)      | O(1)           |
| **Small n (< 50)**    | May be slower         | Usually faster |
| **Multiple Searches** | Excellent             | Poor           |

## Common Pitfalls

⚠️ **Integer Overflow**
```python
# Wrong - might overflow in other languages
mid = (low + high) // 2

# Better
mid = low + (high - low) // 2
```

 **Off-by-One Errors**
- While condition: `low <= high` (not `<`)
- Update: `low = mid + 1`, `high = mid - 1`

 **Unsorted Array**
- Always sort first or use a different search

**Duplicate Elements**
- Standard binary search returns any occurrence
- Use first/last occurrence variants for specific behavior
## Advanced Variations

### Binary Search in 2D Matrix
```python
def search_matrix(matrix, target):
    if not matrix or not matrix[0]:
        return False
    
    rows, cols = len(matrix), len(matrix[0])
    low, high = 0, rows * cols - 1
    
    while low <= high:
        mid = (low + high) // 2
        row = mid // cols
        col = mid % cols
        
        if matrix[row][col] == target:
            return True
        elif matrix[row][col] < target:
            low = mid + 1
        else:
            high = mid - 1
    
    return False
```

### Binary Search in Infinite Array
```python
def search_infinite(arr, target):
    # First find bounds
    low, high = 0, 1
    while arr[high] < target:
        low = high
        high = high * 2
    
    # Normal binary search
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            low = mid + 1
        else:
            high = mid - 1
    
    return -1
```

---

## Quick Revision Points

| Point | Detail |
|-------|--------|
| **Best Case** | O(1) - Target at middle |
| **Worst Case** | O(log n) |
| **Space** | O(1) (iterative) / O(log n) (recursive) |
| **Input** | **Sorted** array/list |
| **Output** | Index of target or -1 |
| **Method** | Divide and conquer |
| **Middle Index** | `low + (high - low) // 2` |
| **Loop Condition** | `low <= high` |

