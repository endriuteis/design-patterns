# Flyweight

Space optimization!

A space optimization technique that lets us use less memory by storing externally the data associated with similar objects.

## Motivation

- Avoid redundancy when storing data.
-  E.g., MMORPG
   -  Plenty of users with identical first/last names.
   -  No sense in storing same names over and over again.
   - Store a list of names and pointers to them.
- E.g., bold or italic text in the console
   - Don't want each character to have a formatting character.
   - Operate on ranges (e.g, line number, start/end positions).

## Summary

- Store common data externally
   - E.g., static map
- Define the idea of ranges on homogeneous collections
   - Sore data related to those ranges


