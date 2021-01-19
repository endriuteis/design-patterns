# Iterator

*"Facilitates communication between components."*

A component that facilitates communication between components without them necessarily being aware of each other or having direct (reference) access to each other.

## Motivation

- Components may go in and out of a system at any time
  - Chat room participants
  - Players in an MMORPG
- It makes no sense for them to have direct references to one another
  - Those references may go dead
- Solution: have then all refer to some central component that facilitates communication

## Summary

- Create the mediator and have each of the object refer to the mediator
  - E.g. in a field
- Mediator engages in bidirectional communication with its connected components
- Mediator has function the components can call
- Components have functions the mediator can call
- Event processing (e.g. Rx) libraries make communication easier to implement