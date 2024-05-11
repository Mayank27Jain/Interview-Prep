Basics for C++
===

_Picked from Lippman 5th edition_

---

Arrays
---

- Arrays have a fixed size
- Array declarator has the form `a[d]` for type `a` and dimension `d`. The dimension must be known at compile time, hence a `constexpr`.
- Values inside the array are default initialized:
    1. If outside a function, set to '0'
    2. Inside a function, uninitialized
- Cannot use auto to deduce type of the array
- No arrays of references
- Can do list initialization, which also allows skipping the dimension `d`.
- Character arrays can be initialized thorough string literals. Need to take into account the space for a null.
- Cannot copy initialize or assign arrays.
- To define a pointer or reference to an array, you need to use brackets: `int (*PArray)[10] = &arr`.
- Read decarations inside to out.
- Can use a ranged for loop on arrays.
- Compiler does not do bound checking on `[]` operand value.
- Arrays usually devolve to pointers.
- The name of the array `arr` becomes synonymous to `&arr[0]`.
- This means when you use `auto p = arr;` where `int[10] arr`, the deduced type is `int *`.
- `decltype(arr)` returns `int[10]` faithfully.
- Pointers can act as iterators on arrays.
- You can use `begin` and `end` on arrays to get 'iterators' just like vectors.
- Pointers hence support dereference, increment, comparisons etc-.
- `int *ap = ap2+4` does not add 4 to the value, but adds 4*`sizeof(*ap)`, essentially it is like `&ap[4]`.
- Difference of pointers follows the same logic.
- Adding 0 to null pointers or subtracting two nul pointers is okay.
- `*ia + 4` does the dereference first.
- The builtin subscript operator on arrays allows for `ia[-2]` kind of expressions.
- C style strings are a convention of using character arrays that are null terminated.
- Doing comparisons on C-style strings ends up comparing the pointers.
- Try using `strcmp(s1, s2) < 0` or something.
- While using `strcpy`, make sure there is enough space first.
- We can use `.c_str` on string to get a C-style string, but it has type `const char *`.
- Arrays of arrays are multi-dimensional arrays in C++.
- `int ia[3][4]` is array of size 3, each element is array of size 4, each element is int.
- We can define references to array, so we can write a statement like `int (&row)[4] = ia[1]` to get an alias for the second row.
- To use a ranged for loop, use code like:

```C++
    for (auto &row : ia) {
        for (auto col : row) {
            col = cnt;
            ++cnt;
        }
    }
```
- We used a reference since otherwise the `auto` would make a pointer out of it.
- Try using `begin` and `end` instead.
- An array typedef looks like `typdef int intarray[4]`.


#### Ranged for loop

- Anything can go into after the colon `:`, that defines `begin` and `end`.
- This allows for braced initializer list, arrays, and vectors etc-.

Functions
---