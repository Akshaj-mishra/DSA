
A nested function is a function defined inside another function. The outer function can call the inner function, and the inner function can access variables from the outer function.

### Example

``` python

def outer():
    x = 10

    def inner():
        print(x)

    inner()

outer()
```

Output: `10`

### Important points

1. Access outer variables: The inner function can read variables from the outer function without passing them as arguments.
    
2. Modify outer variables: Use `nonlocal` to reassign a variable belonging to the enclosing function.
    
3. Global variables: Use `global` to reassign a variable defined at the module level.
    
4. Local scope: Assigning a variable inside the inner function creates a local variable unless `nonlocal` or `global` is used.
    
5. Closures: A nested function that retains access to variables from its enclosing scope is called a closure.
    

## Local vs Nonlocal in Python

Think of it like C++: a local variable belongs to the current function, while `nonlocal` lets an inner function modify a variable belonging to its enclosing function.

### 1. Local variable

``` python
def outer():
    x = 10

    def inner():
        x = 20  # Creates a new local variable
        print("Inner:", x)

    inner()
    print("Outer:", x)

outer()
```

Output:

```
Inner: 20
Outer: 10
```

Why? `x = 20` creates a separate variable local to `inner()`. It doesn't change `outer()`'s `x`.

### 2. Nonlocal variable

``` python
def outer():
    x = 10

    def inner():
        nonlocal x
        x = 20
        print("Inner:", x)

    inner()
    print("Outer:", x)

outer()
```

Output:

```
Inner: 20
Outer: 20
```

Why? `nonlocal x` tells Python to find `x` in the nearest enclosing function scope and reassign that variable.

### Quick comparison

|Feature|Local|Nonlocal|
|---|---|---|
|Declaration|`x = 20`|`nonlocal x` then `x = 20`|
|Changes outer variable?|No|Yes|
|Variable belongs to|Current function|Enclosing function|

### C++ analogy

``` c++
int x = 10;

auto inner = [&x]() {
    x = 20;  // Capture x by reference
};
```

This resembles Python's `nonlocal x` because both allow modifying an existing variable from an outer scope.

Remember: Reading an outer variable needs no special keyword. Use `nonlocal` when you want to reassign it inside a nested function.