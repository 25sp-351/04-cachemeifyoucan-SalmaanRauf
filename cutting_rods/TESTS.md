# Test Case 1: 1 piece, perfect fit - LRU
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

# Test Case 2: multiple pieces, exact fit - LRU
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

# Test Case 3: all pieces too big - LRU
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

# Test Case 4: small piece, small remainder - LRU
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

---

# Test Case 5: exact fit with multiple piece types - LRU
Rod length: 8
Pieces:
5, 10
3, 5

=== Program Output ===
Cutting list:
1 @ 5 = 10
1 @ 3 = 5
Remainder: 0
Value: 15
====================
Result: PASS

---

# Test Case 6: large rod, single piece type - LRU
Rod length: 100
Pieces:
5, 10

=== Program Output ===
Cutting list:
20 @ 5 = 200
Remainder: 0
Value: 200
====================
Result: PASS

---

# Test Case 7: large rod with remainder - LRU
Rod length: 91
Pieces:
5, 10

=== Program Output ===
Cutting list:
18 @ 5 = 180
Remainder: 1
Value: 180
====================
Result: PASS

---

# Test Case 8: medium rod, multiple piece types - LRU
Rod length: 73
Pieces:
5, 10
3, 5

=== Program Output ===
Cutting list:
14 @ 5 = 140
1 @ 3 = 5
Remainder: 0
Value: 145
====================
Result: PASS

---

# Test Case 9: small rod with remainder - LRU
Rod length: 29
Pieces:
5, 10
3, 5

=== Program Output ===
Cutting list:
5 @ 5 = 50
1 @ 3 = 5
Remainder: 1
Value: 55
====================
Result: PASS


