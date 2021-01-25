# Builder

*"When construction gets a little bit complicated."*

When piecewise object construction is complicated, provide an API for doing it succintly.

## Motivation

- Some objects are simple and can be created in a single constructor call.
- Other objects require a lot of ceremony to create.
- Having a objects with 10 contructor arguments is not productive.
- Instead, opt for piecewise contruction.
- Builder provides an API for contructing an object step-by-step.

## Summary

- A builder is a separate component for building an object.
- Can either give builder a constructor or return it via a static function.
- To make a builder fluent, return this.
- Different facets of an object can be built with different buiders
  working in tandem via a base class.