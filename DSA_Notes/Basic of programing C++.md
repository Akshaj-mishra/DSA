### Functions: Pass by Value & Pass by Reference
### **What is Pass by Reference?**

When a variable is passed by reference, the function receives the **actual variable** (not a copy). Any changes made inside the function will reflect on the original.

You give your friend your actual debit card to withdraw money. Any changes made (like balance deduction) affect your real bank account. That’s pass-by-reference.

#### **Key Characteristics:**

- The function receives the original memory address
- Changes inside the function affect the original
- Useful when you want to update multiple variables or return multiple values
---
### **What is Pass by Value?**

When a variable is passed by value, a **copy** of the variable is made. The function works on that copy, and the original variable remains unchanged.

Imagine passing your Xeroxed mark sheet to a company. If they stamp or mark it, your original remains untouched. That’s pass-by-value.

#### **Key Characteristics:**

- The function receives a separate copy
- Changes inside the function don’t affect the original variable
- Safe, but potentially less efficient for large objects
---
### Example :-
#### Pass by Value

```cpp
#include <iostream>
using namespace std;

void modify(int a) {
    a = a + 10;
}

int main() {
    int x = 5;
    modify(x);
    cout << x << endl; // Output: 5
    return 0;
}
```

#### Pass by Reference

```cpp
#include <iostream>
using namespace std;

void modify(int &a) {
    a = a + 10;
}

int main() {
    int x = 5;
    modify(x);
    cout << x << endl; // Output: 15
    return 0;
}
```

---
---
## **What is C++ STL?**

 STL stands for standard template library which contains a lot of pre-defined templates in terms of containers and classes which makes it very easy for developers or programmers to implement different data structures easily without having to write complete code and worry about space-time complexities.

If you dive a little deeper into STL, you will have to understand everything about templates and how they work, which is one of the most power full tools when it comes to C++ programming language.

However, in this tutorial we will stick to some of the most popular STL containers and algorithms, and its useful functions which is used by programmers very frequently in day to day programming.

#### 1) sort() in C++ STL

   The sort() function in [STL](https://takeuforward.org/c/c-stl-tutorial-most-frequent-used-stl-containers/ "STL") accepts two mandatory parameters: begin and end, and sorts the range within the container in ascending order by default.
   
```cpp
sort(begin, end)
```

- begin: An iterator pointing to the first element of a container.
- end: An iterator pointing to the element just after the last element of the container.

Example :-

```cpp
int main() {
    vector<int> vec = {4,2,1};
    sort(vec.begin(), vec.end());  //Sort the vector
    cout<<vec[0]<<" "<<vec[1]<<" "<<vec[2];
    return 0;
}
```

#### 2) Vector 

**What is a Vector?**

- A **dynamic array** that can automatically resize itself.
- Elements are stored in **contiguous memory locations** (like arrays).
- Allows easy access and traversal using **iterators**.

**Commonly Used Functions**

|Function|Description|Example|
|---|---|---|
|`begin()`|Returns iterator to first element|`v.begin()`|
|`end()`|Returns iterator to position after last element|`v.end()`|
|`push_back(x)`|Adds element `x` at the end|`v.push_back(10);`|
|`pop_back()`|Removes last element|`v.pop_back();`|
|`insert(it, x)`|Inserts `x` at iterator position `it`|`v.insert(v.begin(), 5);`|
|`erase(it)`|Removes element at iterator `it`|`v.erase(v.begin());`|
|`front()`|Returns reference to first element|`v.front();`|
|`back()`|Returns reference to last element|`v.back();`|
|`size()`|Returns number of elements|`v.size();`|
|`empty()`|Checks if vector is empty|`v.empty();`|
|`clear()`|Removes all elements|`v.clear();`|

**Code Example (with notes)**

```cpp

#include<bits/stdc++.h>
using namespace std;
int main() {
    vector<int> v;  // Declaration
    // Inserting elements
    for (int i = 0; i < 10; i++) {
        v.push_back(i);   // v = {0,1,2,...,9}
    }
    // Traversing using iterators
    cout << "Elements: ";
    for (auto it = v.begin(); it != v.end(); it++)
        cout << *it << " ";
    // Accessing elements
    cout << "\nFront: " << v.front();   // First element (0)
    cout << "\nBack: " << v.back();     // Last element (9)
    cout << "\nSize: " << v.size();     // 10
    // Deleting last element
    cout << "\nDeleting: " << v.back();
    v.pop_back();   // Now size becomes 9
    return 0;
}

```

#### 3)  Unordered Map

**What is an Unordered Map?**

- An **associative container** that stores key-value pairs.
- Uses a **hash table** internally.
- **No specific order** of elements (unlike `map` which is ordered).
- Average time complexity: **O(1)** for insert, find, and erase.

**Declaration**

```cpp
unordered_map<key_type, value_type> variable_name;
// Example:
unordered_map<int, int> mp;
```

### Commonly Used Functions

| Function                          | Description                                               | Example                                 |
| --------------------------------- | --------------------------------------------------------- | --------------------------------------- |
| `insert({key, value})`            | Inserts a key-value pair                                  | `mp.insert({1, 10});`                   |
| `begin()`                         | Returns iterator to first element                         | `mp.begin()`                            |
| `end()`                           | Returns iterator after last element                       | `mp.end()`                              |
| `find(key)`                       | Searches for key, returns iterator if found, else `end()` | `mp.find(2)`                            |
| `erase(iterator)` or `erase(key)` | Deletes element(s)                                        | `mp.erase(mp.begin())` or `mp.erase(3)` |
| `clear()`                         | Deletes all elements                                      | `mp.clear()`                            |
| `size()`                          | Returns number of elements                                | `mp.size()`                             |
| `empty()`                         | Checks if map is empty                                    | `mp.empty()`                            |

**Code Example (from your content)**

```cpp
#include<bits/stdc++.h>
using namespace std;
int main() {
    unordered_map<int, int> mp;  // key: int, value: int
    // Insert elements
    for (int i = 1; i <= 5; i++) {
        mp.insert({i, i * 10});
    }
    // Display elements
    cout << "Key\tElement" << endl;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        cout << it->first << "\t" << it->second << endl;
    }
    // Find element with key = 2
    if (mp.find(2) != mp.end())
        cout << "2 is present in map" << endl;
    // Erase first element
    mp.erase(mp.begin());
    // Display after deletion
    cout << "After deleting first element:" << endl;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        cout << it->first << "\t" << it->second << endl;
    }
    cout << "Size: " << mp.size() << endl;
    // Check if empty
    if (!mp.empty())
        cout << "Map is not empty" << endl;
    // Clear all elements
    mp.clear();
    cout << "Size after clear: " << mp.size() << endl;
    return 0;
}
```


**Count Frequency of All Elements in a Vector**

This is one of the most common and practical uses of `unordered_map`.

```cpp

#include<bits/stdc++.h>
using namespace std;
int main() {
    vector<int> arr = {1, 2, 3, 2, 1, 3, 3, 4, 5, 4, 4, 4, 2, 1, 1};
    
    // Step 1: Declare unordered_map to store frequency
    unordered_map<int, int> freq;
    
    // Step 2: Count frequency of each element
    for (int i = 0; i < arr.size(); i++) {
        int element = arr[i];
        freq[element]++;  // Increment count for this element
        // Alternative: freq[arr[i]]++
    }
    
    // Step 3: Display the frequency
    cout << "Element Frequency Count:" << endl;
    cout << "Element\tFrequency" << endl;
    for (auto it = freq.begin(); it != freq.end(); it++) {
        cout << it->first << "\t" << it->second << endl;
    }
    
    // Step 4: Find frequency of a specific element
    int searchKey = 3;
    if (freq.find(searchKey) != freq.end()) {
        cout << "\nFrequency of " << searchKey << " is: " << freq[searchKey] << endl;
    } else {
        cout << "\n" << searchKey << " not found" << endl;
    }
    
    // Step 5: Get total unique elements
    cout << "Total unique elements: " << freq.size() << endl;
    
    return 0;
}
```
**Output:**

```output

Element Frequency Count:
Element Frequency
5       1
4       4
1       4
2       3
3       3
Frequency of 3 is: 3
Total unique elements: 5
```

**Quick Tips**

- **Use `unordered_map`** when order doesn't matter and you need O(1) operations.
- **Use `map`** when you need elements in sorted order (O(log n) operations).
- `mp[key]` automatically creates a key with default value (0 for int) if it doesn't exist.
- `find()` is safer than `[]` when checking existence (doesn't insert anything).
- Perfect for **counting frequencies**, **caching**, and **dictionary-like lookups**.

#### 4)  Unordered Set


