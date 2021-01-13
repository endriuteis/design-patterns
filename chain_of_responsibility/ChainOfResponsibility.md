# Chain of responsibility

Sequence of handlers processing an event one after another.

A chain of components who all get a chance to process a command or a query,
optionally having a default processing implementation and an ability to terminate the processing chain.

## Motivation

- Unethical behaviour by an employee; who takes the blame? (Employee, Manager, CEO, ..)
- You click a graphical element on a form; who handles that event? (Button, Group box, Window, ..)
- CCG computer game; boost attack and defense values of a creature by other cards.

## Summary

- CoR can be implemented as:
  - A chain of pointers/reference (singly linked list).
  - Centralized list.
- Enlist objects in the chain, possibly controlling their order.
- Objects removal from chain (e.g., disconnect from a signal).




