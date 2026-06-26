# String From Matrix - Programming Exercise
A function that builds a string with the entries of a matrix appended in clock-wise order.

- Four boundary variables (top, bottom, left, right) for spiral traversal.
- Guards before inward movements prevent duplicates on non-square matrices. 
- sprintf is safe to use in this occasion given the guaranteed buffer size.
