
accounts_t				accounts( amounts, amounts + amounts_size );

1. **`accounts_t`**: This is a type alias for a vector of account types (`std::vector<Account::t>`).

2. **`accounts`**: This is the name of a vector that will store account information.

3. **`(amounts, amounts + amounts_size)`**: This part initializes the `accounts` vector with elements from the `amounts` array.

   - `amounts` is the starting point (iterator) of the array.
   - `amounts + amounts_size` is the ending point (iterator) of the array. It effectively represents "go from the beginning to the end of the `amounts` array."

So, in simpler terms, the line is creating a vector called `accounts` and filling it with the values from the `amounts` array. It's a way of converting an array into a vector in C++.

------------------------------------------------------------------

The line `typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t;` is creating a type alias in C++. It defines a new type name `acc_int_t` that represents a `std::pair` where the first element of the pair is an iterator for the `accounts_t` type (a vector of `Account` objects), and the second element is an iterator for the `ints_t` type (a vector of integers).

Breaking it down:

- `accounts_t::iterator`: This is an iterator type for the `accounts_t` type, which is a `std::vector` of `Account` objects.

- `ints_t::iterator`: This is an iterator type for the `ints_t` type, which is a `std::vector` of integers.

- `std::pair<accounts_t::iterator, ints_t::iterator>`: This is a `std::pair` where the first element is an iterator for the `accounts_t` type, and the second element is an iterator for the `ints_t` type.

- `typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t;`: This line creates a type alias named `acc_int_t` for the `std::pair` of iterators. This makes it more convenient to declare variables of this type, reducing the complexity of the code.

With this type alias, you can declare variables like `acc_int_t it(acc_begin, dep_begin);` instead of writing out the complete `std::pair` declaration each time. It enhances code readability and maintainability.

-------------------------------------------------------------------

	size_t const			amounts_size( sizeof(amounts) / sizeof(int) );

This line calculates the number of elements in the array amounts and stores it in the variable amounts_size. Let's break it down:

sizeof(amounts): Returns the total size in bytes occupied by the array amounts. It's the size of the entire array in memory.

sizeof(int): Returns the size in bytes of an individual element of the array. In this case, it's the size of an integer.

sizeof(amounts) / sizeof(int): This division calculates how many elements of type int are present in the array amounts.

size_t const amounts_size(...): Declares a constant variable named amounts_size of type size_t (an unsigned integer type commonly used for sizes).

So, the entire line is determining the number of elements in the array amounts and storing that count in the variable amounts_size. It's a common technique used to calculate the size of an array in terms of the number of elements, and it's often written as a safeguard against changes in the size of the array.


➜  ex02 git:(main) ✗ ./DreamJob > hallo     
➜  ex02 git:(main) ✗ diff hallo whatever.log

//google declaring static fields in c++
//non-member attributes