A few things I learned while writing this example:

- **Casting between struct types is illegal in C.** The compiler needs to
  know the layout of a type to generate correct code, and two structs are
  distinct types even if their fields look identical.
- **The compiler cares about pointer types; the CPU does not.** At the
  assembly level, values are just numbers. Type information exists only to
  let the compiler pick the right instructions.
- The assembly code for converting int to float looks like this:
    movl    $40, -8(%rbp)
    cvtsi2ssl -8(%rbp), %xmm0
- The compiler knows how to convert it (fun fact: sometimes CPU does not even need to convert anything.)
- But what should it do for structs? They are opaque. You can search for scalar and opaque data types.
