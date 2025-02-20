# Test Case 1: 1 piece, perfect fit
Rod length: 10
Pieces:
5, 10

=== Program Output ===
Cutting list:
2 @ 5 = 20
Remainder: 0
Value: 20
====================
Result: PASS

---

# Test Case 2: multiple pieces, exact fit
Rod length: 12
Pieces:
3, 5
7, 8

=== Program Output ===
Cutting list:
4 @ 3 = 20
Remainder: 0
Value: 20
====================
Result: PASS


---

# Test Case 3: all pieces too big
Rod length: 4
Pieces:
5, 10
6, 12

=== Program Output ===
Cutting list:
Remainder: 4
Value: 0
====================
Result: PASS


---

# Test Case 4: small piece, small remainder
Rod length: 7
Pieces:
2, 3

=== Program Output ===
Cutting list:
3 @ 2 = 9
Remainder: 1
Value: 9
====================
Result: PASS
