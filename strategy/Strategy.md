# Strategy

*"System behaviour partially specified at runtime."*

Enables the exact behaviour of a system to be selected either at run-time (dynamic) or
compile-time (static).

Also known as a policy (esp. in the C++ world).

## Motivation

- Many algorithms can be decomposed into higher- and lowe-level parts.
- Making tea can be decomposed into:
  - The process of making a hot beverage (boil water, pour into cup); and
  - Tea-specific things (put teabag into water).

## Summary

- Define algorithm at high level.
- Define the interface you expect each strategy to follow.
- Provide for either dynamic or static composition of strategy in the overall algorithm.