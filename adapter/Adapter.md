# Adapter

Getting the interface you want from the interface you have.

A contruct which adapts an existing interface X to conform to the required interface Y.

## Motivation

- Electrical devices have different power (interface) requirements.
- We cannot modify our gadgets to support every possible interface.
- Thus, we need a special devide (an adapter) to give us the interface we require from the interface that we have.

## Summary

- Implementing an Adapter is easy.
- Determine the API you have and the API you need.
- Create a component which aggregates (has a reference to, ..) the adaptee.
- Intermediate representations can pile up: use caching and other optimizations.


