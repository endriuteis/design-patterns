# Command

"You shall not pass!"

An object which represents an instruction to performa a particular action.
Contains all the infromation necessary for the action to be taken.

## Motivation

- Ordinary C++ statements are perishable:
   - Cannot undo a field/property assignment.
   - Cannot directly serialize a sequence of actions (calls).
- Want an object that represents an operation:
   - X should change its field Y to the value Z.
   - X should do W().
- Uses: GUI commands, multi-level undo/redo, macro recording and more"

## Summary

- Encapsulate all the details of an operation in a separate object
- Define instuction for applying the command (either in the command itself, or elsewhere)
- Optionally define instructions for undoing the command
- Can create composite commands (a.k.a. macros)



