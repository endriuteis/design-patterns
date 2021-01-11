# Proxy

An interface for accessing a particular resource.

A class that functionsa an interface to a particular resource. 
That resource might be remote, expensive to construct, or may require logging or some other
added functionality.

## Motivation

- You are calling foo.bar()
- This assumes that foo is in the same process as bar()
- What if, later on, you want to put all Foo-related operations into a separate process.
   - Can you avoid changing your code?
-  Proxy to rescue!
   - Same interface, entirely different behaviour.
- This is called communication proxy
   - Other types: logging, virtual, guarding, ...

## Proxy vs Decorator

- Proxy provides an indentical interface; decorator provides an enhanced interface.
- Decorator typically aggregates (or has a reference to) what it is decorating; proxy doesnt'have to.
- Proxy might not even be working with a materialized object

## Summary

- A proxy has the same interface as the underlying object.
- To create a proxy, simply replicate the existing interface of an object.
- Add relevant functionality to the redefined member functions.
- Different proxies (communication, logging, caching, etc.) have completely different behaviours.


