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

- Build a Façade to provide a simplified API over a set of classes.
- May wish to expose internals through the façade.
- May allow users to 'escalate' to use more complex APIs if they need to.


