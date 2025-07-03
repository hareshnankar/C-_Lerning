
/*when we go for switch and when we go for if in c*/
/*where semaphore is use other than critical section*/
/* 1.Difference between macro (#define) and const

Aspect              Macro (#define)                  Const (const)
---------------------------------------------------------------------------
Compilation        Replaced at preprocessing stage   Exists in memory, checked at compilation
Type Safety        No type checking, risk of errors  Type checking enforced, prevents errors
Debugging          Not available in debugging        Available in debugging symbols
Memory Usage       Not stored in memory              Uses memory as a constant variable
Scope              Global across the file            Obeys scope rules of functions and blocks

examples:

1.Compilation

#define PI 3.14159
const double pi = 3.14159;
double area(double radius) 
{
    return PI * radius * radius;  // "PI" is replaced with 3.14159 before compilation //Macro Example (#define): Preprocessed before compilation
    return pi * radius * radius;  // "pi" exists in memory and is type-checked        //Const Example (const): Compiled and stored in memory
}

2.Type Safety

#define VALUE "Hello"
const char* value = "Hello";
int x = VALUE;  // No error, VALUE is blindly replaced by "Hello" //Macro (No Type Checking)
int x = value;  // Error: Cannot assign `const char*` to `int`    //Const (Type Checked)

3.Debugging

const int square(int x) { return x * x; }
#define SQUARE(x) (x * x)
int result = SQUARE(5);  // Debugger shows `result = 5 * 5`
int result = square(5);  // Debugger tracks `square()`

4. Memory Usage

#define LIMIT 1000
const int limit = 1000;
int arr[LIMIT];  // LIMIT is replaced with 1000 during preprocessing //(No Memory Allocation)
int arr[limit];  // 'limit' is stored and exists at runtime


5. Scope
#define SIZE 10 //(Global, No Scope Restriction)
void func() {
    int arr[SIZE];  // SIZE is valid globally in the file
}
void func() {
    const int size = 10;  // 'size' exists only in 'func'
    int arr[size];
}
*/

/* 2.Difference between inline function and macro function
-------------------------------------------------------------
1. Definition:
   - Inline functions are defined using the inline keyword.
   - Macro functions are defined using the #define preprocessor directive.

2. Compilation vs. Preprocessing:
   - Inline functions are handled by the compiler.
   - Macro functions are expanded by the preprocessor before compilation.

3. Type Checking:
   - Inline functions support type checking.
   - Macro functions do not perform type checking, which can lead to unexpected behavior.

4. Debugging:
   - Inline functions are easier to debug since they behave like normal functions.
   - Macro functions are harder to debug because they are replaced before compilation.

5. Argument Evaluation:
   - Inline function arguments are evaluated only once.
   - Macro function arguments are evaluated multiple times, which can cause unintended side effects.
   #include <stdio.h>

// Inline function
inline int square_inline(int x) {
    return x * x;
}

// Macro function
#define SQUARE_MACRO(x) (x * x)

int main() {
    int a = 5;

    // Inline function usage:
    // - Argument 'a++' is evaluated ONCE before function execution.
    int result_inline = square_inline(a++);
    printf("Inline function result: %d\n", result_inline);
    printf("Value of a after inline function: %d\n", a); // a is incremented only once

    a = 5; // Reset value

    // Macro function usage:
    // - Argument 'a++' is replaced directly in the macro expression.
    // - Since 'a++' is used TWICE in 'x * x', it increments TWICE.
    int result_macro = SQUARE_MACRO(a++);
    printf("Macro function result: %d\n", result_macro);
    printf("Value of a after macro function: %d\n", a); // a is incremented twice!

    return 0;
}

6. Scope:
   - Inline functions follow scope rules and can access class members.
   - Macro functions do not follow scope rules and cannot access class members.

------------------------------------------------------------- */

/* 3.Difference between volatile and const
-------------------------------------------------------------
/**
 * 1.volatile:
 * 
 * 1.Prevents the compiler from optimizing the variable, 
 * ensuring that every read or write operation directly accesses memory.
 * 2.Used in scenarios where a variable's value may change unexpectedly,
 * such as hardware registers or shared memory in multi-threaded applications.
 * 
 * 
 * 2.const:
 * 
 * 1.Marks a variable as read-only, meaning its value cannot be modified after initialization.
 * 2.Helps prevent unintended changes and improves code clarity by ensuring that 
 * a constant value remains unchanged throughout the program's execution.
 * 
 *  * Key Differences:
 * - volatile affects optimization, while const prevents modification.
 * - A volatile variable can change, whereas a const variable cannot be changed after initialization.
 * - They can be combined, like const volatile int x;, which means the variable 
 *   cannot be modified in code but can change externally (e.g., by hardware).
 *
------------------------------------------------------------- */

/* 4.Difference between typedef and #define
-------------------------------------------------------------
 * 6. Function Pointers:
 *    - typedef simplifies function pointer definitions, making them more readable.
 *    - #define cannot be used for function pointers effectively.
 * 
 * Syntax for typedef function pointer:
 * typedef return_type (*alias_name)(parameter_list);
 *
 * 7. Complex Types:
 *    - typedef is useful for renaming structures, enums, and unions.
 *    - #define only performs textual substitution, making complex type definitions harder to manage.
 *
 * 8. Code Maintainability:
 *    - typedef improves code readability and maintainability by providing clear type aliases.
 *    - #define can lead to debugging issues if used for type definitions.
 *
 * 9. Debugging and Error Handling:
 *    - typedef provides better error messages when types are incorrect.
 *    - #define can cause cryptic errors due to unexpected text replacement.
 *
 * 10. Usage in Header Files:
 *    - typedef is commonly used in headers to define reusable types.
 *    - #define is often used for defining constants and macro functions in headers.
 *
------------------------------------------------------------- */

/* 5.Difference between struct and union
 * 1. Memory Allocation:
 *    - struct: Each member gets separate memory space.
 *    - union: All members share the same memory space, and only one member holds a valid value at a time.
 *
 * 2. Size:
 *    - struct: The size is the sum of all members' sizes.
 *    - union: The size is equal to the size of its largest member.
 *
 * 3. Data Access:
 *    - struct: All members can store values independently.
 *    - union: Only one member can hold a value at any given time.
 *
 * 4. Use Cases:
 *    - struct: Used when multiple values need to be stored together.
 *    - union: Used for memory optimization when only one member is needed at a time.
 *
 */

/* 6.Difference between static and global variables
 * 1. Scope:
 *    - static: Restricted to the file or function where it is defined.
 *    - global: Accessible throughout the entire program across all files.
 *
 * 2. Lifetime:
 *    - static: Exists throughout the program's execution but maintains function-local scope.
 *    - global: Exists throughout the program's execution with global scope.
 *
 * 3. Visibility:
 *    - static: Cannot be accessed from other source files.
 *    - global: Can be accessed from any file using extern declaration.
 *
 * 4. Use Cases:
 *    - static: Used when variables should retain their values but be limited in visibility.
 *    - global: Used when data needs to be shared across multiple files.
 *
 * 5. Example Usage:
 */

/* 7.Difference between stack and heap memory allocation
-------------------------------------------------------------
- Stack: Automatic memory allocation, faster but limited size.
- Heap: Dynamic allocation using malloc(), must free memory manually.
------------------------------------------------------------- */

/* 8.Difference between null pointer, wild pointer, and dangling pointer
-------------------------------------------------------------
- Null pointer: Points to nothing, initialized to NULL.
- Wild pointer: Uninitialized pointer with unpredictable behavior.
- Dangling pointer: Points to freed memory.
------------------------------------------------------------- */

/* 9.Difference between header file inclusion (#include "" vs #include <>)
-------------------------------------------------------------
- #include "" : Used for user-defined headers (searches locally first).
- #include <> : Used for standard library headers (searches system paths).
------------------------------------------------------------- */

/* 10.Difference between malloc() and calloc()
 * 1. Memory Allocation:
 *    - malloc(): Allocates a specified number of bytes of memory.
 *    - calloc(): Allocates memory for an array and initializes all elements to zero.
 *
 * 2. Initialization:
 *    - malloc(): Does **not** initialize allocated memory.
 *    - calloc(): Initializes memory to zero.
 *
 * 3. Parameters:
 *    - malloc(): Takes a single argument, the total number of bytes to allocate.
 *    - calloc(): Takes two arguments, the number of elements and size of each element.
 *
 * 4. Performance:
 *    - malloc(): Faster since it does not initialize memory.
 *    - calloc(): Slightly slower because it initializes memory.
 *
 * 5. Use Cases:
 *    - malloc(): When memory initialization is **not required**.
 *    - calloc(): When memory **must be zero-initialized** for safety.
 * 
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Using malloc
    int *ptr1 = (int *)malloc(5 * sizeof(int));
    if (ptr1 == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Using calloc
    int *ptr2 = (int *)calloc(5, sizeof(int));
    if (ptr2 == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Checking initialized values
    printf("malloc allocated memory (uninitialized): %d\n", ptr1[0]); // Undefined value
    printf("calloc allocated memory (initialized to zero): %d\n", ptr2[0]); // Always zero

    // Free allocated memory
    free(ptr1);
    free(ptr2);

    return 0;
}

*/

/*11 strucure concept when we use . when we used -> in structure
Key Difference:
Use . when you have a structure variable.
Use -> when you have a pointer to a structure.

we can use . insted of -> 
yes,
ptr->name is shorter and more readable.
(*ptr).name is explicitly dereferencing

*/

/* 12 Difference between  Structure Padding and Structure Packing
 *
 * 1. Goal:
 *    - Structure Padding: Memory alignment
 *    - Structure Packing: Memory optimization
 *
 * 2. Effect:
 *    - Structure Padding: Increases size for better CPU access
 *    - Structure Packing: Reduces size at cost of speed
 *
 * 3. Usage:
 *    - Structure Padding: Default behavior in most compilers
 *    - Structure Packing: Requires manual activation
 *
 * 4. Performance:
 *    - Structure Padding: Faster access due to alignment
 *    - Structure Packing: May be slower due to misalignment
 */

/* 13 Diffrenace between __attribute__((packed)) and #pragma pack(n)
 * 1. Purpose:
 *    - __attribute__((packed)): Forces all members to be tightly packed without padding.
 *    - #pragma pack(n): Sets structure alignment boundary to 'n' bytes, reducing or modifying padding.
 *
 * 2. Scope:
 *    - __attribute__((packed)): Applies **only to the specific structure**.
 *    - #pragma pack(n): Applies to **all structures defined after the directive**.
 *
 * 3. Usage:
 *    - __attribute__((packed)): Used **inline** within a structure declaration.
 *    - #pragma pack(n): Used **before defining structures** and remains active until reset.
 *
 * 4. Compatibility:
 *    - __attribute__((packed)): **GCC/Clang** supported.
 *    - #pragma pack(n): **Supported in MSVC, GCC, Clang** (but behavior may differ).
 *
 * 5. Example Usage:
 

#include <stdio.h>

// Using #pragma pack(1)

#pragma pack(1)   // Set alignment to 1 byte
struct Packed1 {
    char a;
    int b;
};
#pragma pack()    // Reset to default alignment

// Using __attribute__((packed))
struct Packed2 {
    char a;
    int b;
} __attribute__((packed));

int main() {
    printf("Size of Packed1: %lu\n", sizeof(struct Packed1)); // Affected by #pragma pack(1)
    printf("Size of Packed2: %lu\n", sizeof(struct Packed2)); // Affected by __attribute__((packed))

    return 0;
}
*/

/* 14 Interview Questions and Answers: Variable Storage in C & Embedded Systems
 *
 * 1. Where are global variables stored in memory?
 *    - Global variables are stored in the **Data Segment**.
 *      - Initialized global variables → Stored in **RAM (initialized data section)**.
 *      - Uninitialized global variables → Stored in **BSS (Block Started by Symbol) section**.
 *    Example:
 *      int x = 10; // Stored in initialized data section (RAM)
 *      int y;      // Stored in BSS (initialized to zero)
 *
 * 2. Where are local variables stored in memory?
 *    - Local variables are stored in the **Stack**.
 *    - Memory is **automatically allocated and deallocated** as functions execute.
 *    Example:
 *      void example() {
 *          int a = 5; // Stored in stack
 *      }
 *
 * 3. Where are static variables stored in memory?
 *    - **Static variables** are stored in the **Data Segment**.
 *    - They retain their values between function calls.
 *    Example:
 *      void example() {
 *          static int counter = 0; // Stored in data segment (RAM)
 *          counter++;
 *      }
 *
 * 4. Where are const variables stored in embedded systems?
 *    - In **embedded systems**, const variables are stored in **Flash (ROM)**.
 *    Example:
 *      const int max_value = 100; // Stored in Flash (ROM)
 *
 * 5. Where are volatile variables stored?
 *    - **Global/static volatile variables** are stored in **RAM**.
 *    - **Memory-mapped registers (MMIO)** use volatile to prevent optimization.
 *    Example:
 *      volatile int sensor_value; // Stored in RAM
 *      #define GPIO_PORT (*(volatile unsigned int*)0x40021000) // MMIO register
 *      GPIO_PORT = 1; // Direct hardware access
 *
 * 6. Where does dynamically allocated memory go (malloc, calloc, realloc)?
 *    - Dynamic memory is stored in the **Heap**.
 *    - The programmer must manually deallocate memory using `free()`.
 *    Example:
 *      int *ptr = (int *)malloc(sizeof(int)); // Stored in Heap
 *      free(ptr); // Deallocate memory
 *
 * 7. What happens if a variable is declared inside a register?
 *    - **Registers** are high-speed memory inside the CPU.
 *    - If `register` is used, the compiler **may** store the variable in a CPU register.
 *    Example:
 *      register int fastVar = 10; // Stored in CPU registers (if possible)
 *
 */

 /* 15.Interview Trick Questions and Answers: Combination of Keywords in C
 *
 * Tricks to Remember Keyword Combinations in C
 *
 * 1`static const`            →  valid  Variable **persists** but **cannot change** (stored in Flash in embedded systems).
 * 2`static volatile`         →  valid **Persisting variable that updates dynamically (ISR flag)**.
 * 3`extern const`            →  valid **Read-only global variable available across files (stored in Flash)**.
 * 4`extern volatile`         →  valid **Global memory**, shared across files, always read fresh from RAM."
 * 5`volatile const`(imp)     → **Read-only**, but **hardware can modify** (used in MMIO registers).
 * 6 static const volatile or static volatile const is also valid 
 * 6.- 🚨 `static register` is **invalid** → `register` means fast access, `static` means fixed location (conflict!).
 *

 */

/* Reset Sequence of Microcontroller

1. Processor resets → PC (Program Counter) = 0x00000000 (starting address of Flash memory).
2. Stack Pointer (SP) is initialized → SP = value @ 0x00000000 (0x200008000) (Stack initialization).
3. Program Counter (PC) fetches the reset vector → Reads 0x00000004 (address of Reset Handler).
4. Control jumps to Reset Handler → SP = value @ 0x00000004 (0x200001000).
5. Reset Handler (Startup Code) initializes:
   {
     - Copy initialized **Data Section** from Flash to RAM.
     - Zero out **BSS Section** (Uninitialized global/static variables).
     - Set up **Standard Library and System Peripherals**.
     - Configure the **Heap & Stack**.
     - **Interrupts remain disabled during initialization.**
     - Enable **Interrupt Vector Table** if applicable.
     - **Enable interrupts before calling `main()`**.
     - Call **main()** function → Execution begins.
   }
6. Microcontroller enters **main execution phase**.

Additional Steps:
- If a **Watchdog Reset (WDT)** occurs, the system may follow an alternate reset flow.
- Some **Bootloaders** may execute before `main()`, handling firmware updates or diagnostics.

*/

/* Operator Precedence & Associativity in C
 *
 * --------------------------------------------------------------
 * | Precedence | Operators               | Associativity       |
 * --------------------------------------------------------------
 * | **Highest** | `()` (Parentheses)      | Left to Right      |
 * |             | `[]` (Array Index)       | Left to Right     |
 * |             | `.` (Structure Member)   | Left to Right     |
 * |             | `->` (Pointer to Member) | Left to Right     |
 * --------------------------------------------------------------
 * | 2nd         | `++` (Post-increment)    | Left to Right     |
 * |             | `--` (Post-decrement)    | Left to Right     |
 * --------------------------------------------------------------
 * | 3rd         | `++` (Pre-increment)     | Right to Left     |
 * |             | `--` (Pre-decrement)     | Right to Left     |
 * |             | `!` (Logical NOT)        | Right to Left     |
 * |             | `~` (Bitwise NOT)        | Right to Left     |
 * |             | `*` (Pointer Dereference)| Right to Left     |
 * |             | `&` (Address-of)         | Right to Left     |
 * |             | `sizeof`                 | Right to Left     |
 * --------------------------------------------------------------
 * | 4th         | `*` (Multiplication)     | Left to Right     |
 * |             | `/` (Division)           | Left to Right     |
 * |             | `%` (Modulo)             | Left to Right     |
 * --------------------------------------------------------------
 * | 5th         | `+` (Addition)           | Left to Right     |
 * |             | `-` (Subtraction)        | Left to Right     |
 * --------------------------------------------------------------
 * | 6th         | `<<` (Left Shift)        | Left to Right     |
 * |             | `>>` (Right Shift)       | Left to Right     |
 * --------------------------------------------------------------
 * | 7th        | `<` `<=` `>` `>=`         | Left to Right     |
 * --------------------------------------------------------------
 * | 8th        | `==` `!=`                | Left to Right     |
 * --------------------------------------------------------------
 * | 9th        | `&` (Bitwise AND)        | Left to Right     |
 * --------------------------------------------------------------
 * | 10th       | `^` (Bitwise XOR)        | Left to Right     |
 * --------------------------------------------------------------
 * | 11th       | `|` (Bitwise OR)         | Left to Right     |
 * --------------------------------------------------------------
 * | 12th       | `&&` (Logical AND)       | Left to Right     |
 * --------------------------------------------------------------
 * | 13th       | `||` (Logical OR)        | Left to Right     |
 * --------------------------------------------------------------
 * | 14th       |`?:` (Ternary Conditional)| Right to Left   |
 * --------------------------------------------------------------
 * | 15th       | `=` `+=` `-=` `*=` `/=` `%=` `&=` `|=` `^=` `<<=` `>>=` | Right to Left |
 * --------------------------------------------------------------
 * | 16th       | `,` (Comma)             | Left to Right     |
 * --------------------------------------------------------------
 * | **Lowest**  |                         |                  |
 * --------------------------------------------------------------
 *
 * Notes:
 * - **Higher precedence operators execute first**.
 * - **Associativity determines order when operators have the same precedence**.
 * - **Right to Left associativity** means the **rightmost operator executes first**.
 * - **Left to Right associativity** means the **leftmost operator executes first**.
 */

/* Tricky Pointer Questions with Associativity & Precedence in C
 *
 * 1. What happens when dereferencing a pointer before incrementing?
 *    - `*p++` is **different** from `(*p)++`.
 *    - `*p++` → Dereference first, then increment pointer (Postfix `++` has higher precedence).
 *    - `(*p)++` → Dereference first, then increment value at the address.
 *    
 *    Example:
 *    int arr[] = {10, 20, 30};
 *    int *p = arr;
 *    printf("%d\n", *p++); // ✅ Prints 10, then `p` moves to next element.
 *    printf("%d\n", (*p)++); // ✅ Prints 20, then value at `p` becomes 21.
 *
 * 2. What is the difference between `*ptr++` and `*(ptr++)`?
 *    - Both move `ptr` to the next address.
 *    - `*ptr++` → Dereference first, then increment pointer.
 *    - `*(ptr++)` → Same behavior (Postfix `++` has higher precedence than `*`).
 *
 * 3. What happens if parentheses are missing in pointer arithmetic?
 *    - `*p + 1` and `*(p + 1)` have different meanings.
 *    - `*p + 1` → Adds `1` to the **dereferenced value**.
 *    - `*(p + 1)` → Moves to next element and **dereferences**.
 *
 *    Example:
 *    int arr[] = {5, 15, 25};
 *    int *p = arr;
 *    printf("%d\n", *p + 1);  // ✅ Prints `6` (adds `1` to `5`).
 *    printf("%d\n", *(p + 1)); // ✅ Prints `15` (moves to next element).
 *
 * 4. What happens with multiple dereferencing?
 *    - `**ptr` → Double dereference.
 *    - `*ptr[0]` → Access first element of array pointer.
 *    - `(*ptr)[0]` → Same meaning as `*ptr[0]`.
 *
 *    Example:
 *    int matrix[2][2] = { {1, 2}, {3, 4} };
 *    int (*ptr)[2] = matrix;
 *    printf("%d\n", *ptr[0]);  // ✅ Prints `1` (First row, first element).
 *    printf("%d\n", (*ptr)[0]); // ✅ Same as above.
 *
 * 5. What is the behavior of `const int *ptr` vs `int *const ptr`?
 *    - `const int *ptr` → **Pointer to constant data**, data can't change but pointer can.
 *    - `int *const ptr` → **Constant pointer**, data can change but pointer address can't.
 *
 *    Example:
 *    const int a = 50;
 *    const int *ptr1 = &a; // ✅ Allowed
 *    //*ptr1 = 60; ❌ Error (data can't be changed)
 *
 *    int b = 70;
 *    int *const ptr2 = &b;
 *    *ptr2 = 80; // ✅ Allowed (data can change)
 *    // ptr2 = &a; ❌ Error (pointer itself is constant)
 *
 * 6. What happens when function pointers are used incorrectly?
 *    - `void (*func)()` → Function pointer declaration.
 *    - `(*func)()` and `func()` behave **exactly the same**.
 *
 *    Example:
 *    void display() { printf("Hello, World!\n"); }
 *    void (*funcPtr)() = display;
 *    funcPtr(); // ✅ Calls function.
 *    (*funcPtr)(); // ✅ Same as above.
 */

/* Access Specifiers in C++ & Friend Function Rules
 *
 * 1. Public (`public`)
 *    - Members are **accessible everywhere** (inside and outside the class).
 *    - Used when unrestricted access is needed.
 *    Example:
 *    class Example {
 *    public:
 *        int x;
 *        void show() { printf("Public Method\n"); }
 *    };
 *
 * 2. Private (`private`)
 *    - Members are **only accessible within the class**.
 *    - Not accessible from derived classes or outside.
 *    Example:
 *    class Example {
 *    private:
 *        int y;  // Cannot be accessed outside the class
 *        void secret() { printf("Private Method\n"); }
 *    };
 *
 * 3. Protected (`protected`)
 *    - Members are **accessible within the class and derived classes**.
 *    - Not accessible outside except through inheritance.
 *    Example:
 *    class Example {
 *    protected:
 *        int z; // Accessible only in derived classes
 *        void special() { printf("Protected Method\n"); }
 *    };
 *
 * Summary Table:
 * -----------------------------------------------------------------
 * | Access Specifier | Accessible in Class | Accessible in Derived | Accessible Outside |
 * |-----------------|--------------------|----------------------|------------------|
 * | Public         | ✅ Yes             | ✅ Yes               | ✅ Yes           |
 * | Protected      | ✅ Yes             | ✅ Yes               | ❌ No            |
 * | Private        | ✅ Yes             | ❌ No                | ❌ No            |
 * -----------------------------------------------------------------
 *
 * 4. Friend Functions (`friend`)
 *    - A **friend function** can access **private and protected** members of a class.
 *    - Does not belong to the class but has special permission.
 *    - Declared inside the class with `friend` keyword.
 *    Example:
 *    class Example {
 *    private:
 *        int secretNumber;
 *    public:
 *        Example() { secretNumber = 42; }
 *        friend void showSecret(Example obj);  // Declaring a friend function
 *    };
 *
 *    // Friend function definition
 *    void showSecret(Example obj) {
 *        printf("Secret Number: %d\n", obj.secretNumber);  // ✅ Allowed due to friend access
 *    }
 *
 * 5. Friend Function Rules:
 *    ✅ A friend function **can access private & protected members** of a class.
 *    ✅ **Friend functions are not members of the class** but have privileged access.
 *    ✅ They must be **declared inside the class** with the `friend` keyword.
 *    ✅ A friend function can be **a normal function or a friend of multiple classes**.
 *    ✅ **Friendship is not inherited** (Derived classes do not inherit friend functions).
 *
 * 6. Friend Class:
 *    - A **friend class** allows all its functions to access private & protected members of another class.
 *    Example:
 *    class Example {
 *    private:
 *        int secretCode;
 *    public:
 *        Example() { secretCode = 1234; }
 *        friend class Hacker;  // Declaring friend class
 *    };
 *
 *    class Hacker {
 *    public:
 *        void reveal(Example obj) {
 *            printf("Hacked Code: %d\n", obj.secretCode);  // ✅ Access allowed due to friend class
 *        }
 *    };
 */

/* C++ Inheritance: Public, Protected, and Private
 *
 * 1. Public Inheritance (`class Derived : public Base`)
 *    - Public members of `Base` → Remain **public** in `Derived`.
 *    - Protected members of `Base` → Remain **protected** in `Derived`.
 *    - Private members of `Base` → **Not accessible** in `Derived`.
 *    
 *    Example:
 *    class Derived : public Base {
 *        void show() {
 *            x = 10;  // ✅ Allowed (public in Base → public in Derived)
 *            y = 20;  // ✅ Allowed (protected in Base → protected in Derived)
 *            // z = 30; ❌ Not Allowed (private in Base → Not accessible)
 *        }
 *    };
 *
 * 2. Protected Inheritance (`class Derived : protected Base`)
 *    - Public members of `Base` → Become **protected** in `Derived`.
 *    - Protected members of `Base` → Remain **protected** in `Derived`.
 *    - Private members of `Base` → **Not accessible** in `Derived`.
 *    
 *    Example:
 *    class Derived : protected Base {
 *        void show() {
 *            x = 10;  // ✅ Allowed (public in Base → protected in Derived)
 *            y = 20;  // ✅ Allowed (protected in Base → protected in Derived)
 *            // z = 30; ❌ Not Allowed (private in Base → Not accessible)
 *        }
 *    };
 *
 * 3. Private Inheritance (`class Derived : private Base`)
 *    - Public members of `Base` → Become **private** in `Derived`.
 *    - Protected members of `Base` → Become **private** in `Derived`.
 *    - Private members of `Base` → **Not accessible** in `Derived`.
 *    
 *    Example:
 *    class Derived : private Base {
 *        void show() {
 *            x = 10;  // ✅ Allowed (public in Base → private in Derived)
 *            y = 20;  // ✅ Allowed (protected in Base → private in Derived)
 *            // z = 30; ❌ Not Allowed (private in Base → Not accessible)
 *        }
 *    };
 *
 * Summary Table:
 * ------------------------------------------------------------------------------------
 * | Base Members     | Public Inheritance  | Protected Inheritance | Private Inheritance |
 * |------------------|-------------------  |--------------------   |------------------   |
 * | Public (`x`)     | **Public**          | **Protected**         | **Private**         |
 * | Protected (`y`)  | **Protected**       | **Protected**         | **Private**         |
 * | Private (`z`)    | **Not Accessible**  | **Not Accessible**    | **Not Accessible**  |
 * ---------------------------------------------------------------------------------------
 *
 */
