# Visitor

*"Typically a tool for structure traversal rather than anything else."*

A pattern where a component (visitor) is allowed to traverse the entire inheritance hierarchy.
Implemented by propagating a single visit() method throughout the entire hierarchy.

## Motivation

- Need to define a new operation on an entire clas hierarchy.
  - E.g. make a document model printable to HTML/Markdown.
- Do not want to keep modifying every class in the hierarchy.
- Need access to the non-common aspects of classes in the hierarchy.
  - Cannot put everything into a single interface.
- Create an external component to handle rendering.
  - But preferavly avoid avoid type checks.

## Summary

-