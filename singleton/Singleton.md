# Singleton

A component that is instantiated only once.

## Motivation

- For some components it only makes sense to have one in the system:
   - Object that reads a database repository.
   - Object factory.
- E.g., the constructor call is expensive:
   - We only do it once.
   - We provide everyone with the same instance.
- Want prevent anyone creating additional copies
- Need to take care of lazy instantiation and thread safety

## Summary

- Making a safe singleton is easy:
   - Hide or delete the type's constructor, copy constructor and copy assignment operators.
   - Create a static method that returns a reference to a static member
   - Guaranteed to be thread-safe since C++11
- Types with 'hard' dependencies on singletons are difficult to test
 - cannot decouple the singleton and supply a fake object.
- Instead of directly using a singleton, consider depending on an abstraction (e.g. an interface).
- Consider defining singleton lifetime in DI container.


