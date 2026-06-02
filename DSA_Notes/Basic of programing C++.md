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

 What is an Unordered Set?

- A container that stores **unique elements** (no duplicates allowed).
- Elements are stored in **no particular order**.
- Uses a **hash table** internally.
- Time complexity: **O(1)** average case, **O(n)** worst case.

 **Declaration**

```cpp

unordered_set<data_type> variable_name;
// Example:
unordered_set<int> s;
unordered_set<string> names;

```

 Commonly Used Functions

|Function|Description|Example|
|---|---|---|
|`insert(value)`|Inserts an element (ignores duplicates)|`s.insert(5);`|
|`begin()`|Returns iterator to first element|`s.begin()`|
|`end()`|Returns iterator after last element|`s.end()`|
|`find(value)`|Searches for value, returns iterator if found, else `end()`|`s.find(3)`|
|`count(value)`|Returns 1 if present, 0 otherwise|`s.count(7)`|
|`erase(iterator)` or `erase(value)`|Deletes element(s)|`s.erase(s.begin())` or `s.erase(5)`|
|`clear()`|Deletes all elements|`s.clear()`|
|`size()`|Returns number of elements|`s.size()`|
|`empty()`|Checks if set is empty|`s.empty()`|



Code Example (from your content)

```cpp

#include<bits/stdc++.h>
using namespace std;
int main() {
    // Declare an unordered_set of integers
    unordered_set<int> s;
    // Insert elements from 1 to 10
    for (int i = 1; i <= 10; i++) {
        s.insert(i);
    }
    // Display all elements
    cout << "Elements present: ";
    for (auto it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    // Check if element 2 exists using find()
    int n = 2;
    if (s.find(2) != s.end())
        cout << n << " is present" << endl;
    // Erase the first element
    s.erase(s.begin());
    // Display after deletion
    cout << "After deleting first element: ";
    for (auto it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    cout << "Size: " << s.size() << endl;
    // Check if empty
    if (s.empty() == false)
        cout << "Set is not empty" << endl;
    // Clear all elements
    s.clear();
    cout << "Size after clear: " << s.size() << endl;
    return 0;
}

```

#Extra_Example: Remove Duplicates from an Array/Vector

One of the most practical uses of `unordered_set` is removing duplicates.

```cpp

#include<bits/stdc++.h>
using namespace std;
int main() {
    // Original array with duplicates
    vector<int> arr = {5, 2, 8, 2, 5, 1, 9, 8, 8, 3, 1, 4, 2, 5};
    
    cout << "Original array: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
    
    // Step 1: Insert all elements into unordered_set (duplicates automatically removed)
    unordered_set<int> uniqueSet;
    for (int i = 0; i < arr.size(); i++) {
        uniqueSet.insert(arr[i]);
    }
    
    // Step 2: Display unique elements
    cout << "Unique elements: ";
    for (auto it = uniqueSet.begin(); it != uniqueSet.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    
    // Step 3: Get count of unique elements
    cout << "Number of unique elements: " << uniqueSet.size() << endl;
    
    // Step 4: Convert back to vector (if needed)
    vector<int> uniqueArr(uniqueSet.begin(), uniqueSet.end());
    
    cout << "Vector without duplicates: ";
    for (int x : uniqueArr) {
        cout << x << " ";
    }
    cout << endl;
    
    // Step 5: Check if a specific element exists
    int searchValue = 8;
    if (uniqueSet.count(searchValue)) {  // count() returns 1 if exists
        cout << searchValue << " is present in the set" << endl;
    }
    
    return 0;
}
```

**Output:**
```cpp

text

Original array: 5 2 8 2 5 1 9 8 8 3 1 4 2 5
Unique elements: 4 1 2 3 8 5 9
Number of unique elements: 7
Vector without duplicates: 4 1 2 3 8 5 9
8 is present in the set

```

Extra Example 2: Find Missing Elements

```cpp

#include<bits/stdc++.h>
using namespace std;
int main() {
    // Expected numbers from 1 to 10
    vector<int> actual = {1, 2, 4, 5, 7, 8, 10};  // Missing: 3, 6, 9
    
    // Insert actual numbers into set
    unordered_set<int> present(actual.begin(), actual.end());
    
    // Find missing numbers
    cout << "Missing numbers: ";
    for (int i = 1; i <= 10; i++) {
        if (present.find(i) == present.end()) {  // Not found
            cout << i << " ";
        }
    }
    cout << endl;
    
    return 0;
}

```
**Output:**

```cpp

Missing numbers: 3 6 9

```

Quick Tips

|Feature|unordered_set|set|
|---|---|---|
|Order|No specific order|Sorted order|
|Internal|Hash table|Balanced BST|
|Time (avg)|O(1)|O(log n)|
|Use when|Order doesn't matter, need speed|Need sorted elements|

- **Use `count()`** for simple existence check (returns 0 or 1).
- **Use `find()`** when you need the iterator position.
- Duplicate inserts are **silently ignored** (no error).
- Perfect for **duplicate removal**, **membership testing**, and **set operations**.

#### 5)  Set

**What is a Set?**

- A container that stores **unique elements** in a specific order.
- Average case time complexity: **O(1)**
- Worst case: **O(n)**

**Common Functions**

|Function|Description|
|---|---|
|`insert()`|Inserts an element into the set|
|`begin()`|Iterator to first element|
|`end()`|Iterator to position after last element|
|`count()`|Returns `true` if element exists, else `false`|
|`clear()`|Removes all elements|
|`find()`|Searches for an element|
|`erase()`|Deletes an element or range|
|`size()`|Returns number of elements|
|`empty()`|Checks if set is empty|

**Example Code Summary**

```cpp

set<int> s;
for(int i = 1; i <= 10; i++) s.insert(i);
// Print set
for(auto it = s.begin(); it != s.end(); it++)
    cout << *it << " ";
// Search
if(s.find(2) != s.end())
    cout << "2 is present";
// Delete first element
s.erase(s.begin());
// Size & empty check
cout << s.size();
if(!s.empty()) cout << "Not empty";
// Clear all
s.clear();


```

Key Points to Remember

-  All elements are **unique** (no duplicates)
-  Elements are **automatically sorted** (ascending by default)
-  Cannot modify elements directly (must erase & insert)
- Useful for **set operations** like union, intersection, distinct elements

---
---

Here are **very good notes on String Streaming in C++** (using `std::stringstream`), building on the STL set knowledge you just reviewed.

---

### String Streaming in C++ (`<sstream>`)

### What is String Streaming?
A **stringstream** treats a string like a stream (similar to `cin` / `cout`), allowing you to:
- Extract data from a string (parsing)
- Insert data into a string (formatting)
- Convert between strings and other data types

---

### Required Header
```cpp
#include <sstream>
```

---

### Creating a Stringstream

```cpp
stringstream ss;                    // Empty
stringstream ss("Hello 123 3.14"); // With initial data
```

---

### Inserting into Stringstream (`<<`)

```cpp
stringstream ss;
ss << "Number: " << 42 << " " << 3.14;
cout << ss.str();  // Output: Number: 42 3.14
```

---

### Extracting from Stringstream (`>>`)

```cpp
stringstream ss("John 25 180.5");
string name;
int age;
float height;

ss >> name >> age >> height;
// name = "John", age = 25, height = 180.5
```

---

### Converting Between Types

### String → Integer / Float
```cpp
stringstream ss("123");
int num;
ss >> num;  // num = 123
```

### Integer → String
```cpp
stringstream ss;
ss << 456;
string str = ss.str();  // str = "456"
```

---

### Useful Methods

| Method | Description |
|--------|-------------|
| `.str()` | Returns the underlying string |
| `.str("new")` | Sets new string content |
| `.clear()` | Clears error flags (not the content) |
| `ss >> ws` | Skips whitespace |

---

### Parsing Example (Like `split()`)

```cpp
string data = "apple banana cherry grape";
stringstream ss(data);
string word;

while (ss >> word) {
    cout << word << endl;
}
// Output: apple banana cherry grape (each on new line)
```

---

### Parsing CSV / Delimited Data

```cpp
string line = "101,Alice,85.5";
stringstream ss(line);
int id;
string name;
float score;
char comma;

ss >> id >> comma >> name >> comma >> score;
// id=101, name="Alice", score=85.5
```

---

### Practical Example: Summing Numbers from a String

```cpp
string numbers = "10 20 30 40 50";
stringstream ss(numbers);
int num, sum = 0;

while (ss >> num) {
    sum += num;
}
cout << "Sum: " << sum;  // Sum: 150
```

---

### Common Pitfalls

| Issue | Solution |
|-------|----------|
| `>>` stops at whitespace | Use `getline(ss, str, ',')` for custom delimiters |
| Need to reuse same stringstream | Call `.clear()` AND `.str("")` |
| Extracting fails with wrong type | Check `ss.fail()` or use `if(ss >> var)` |

---

### Resetting a Stringstream for Reuse

```cpp
stringstream ss;
ss << "First";
cout << ss.str();  // "First"

// Reset properly
ss.clear();        // Clear error flags
ss.str("");        // Empty the content
ss << "Second";
cout << ss.str();  // "Second"
```

---

### `stringstream` vs Other Methods

| Feature | `stringstream` | `stoi()` / `to_string()` | `sscanf()` |
|---------|---------------|--------------------------|------------|
| Type safety | ✅ | ✅ | ❌ (C-style) |
| Multiple values | ✅ | ❌ (one at a time) | ✅ |
| C++ idiomatic | ✅ | ✅ | ❌ |
| Performance | Moderate | Fast | Fast |

---

### Quick Reference Card

```cpp
#include <sstream>

// Creation
stringstream ss;
stringstream ss("text");

// Output to string
ss << data;
string result = ss.str();

// Input from string
ss >> variable;

// Clear & reuse
ss.clear();
ss.str("");

// Parsing loop
while (ss >> word) { /* use word */ }
```

---

### When to Use Stringstream
- Parsing space-separated data
- Converting between strings and numbers
- Building complex strings with mixed types
- Implementing a `split()`-like functionality
- Reading formatted data from a string

---
---
