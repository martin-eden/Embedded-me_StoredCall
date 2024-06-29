# What

(2024-06)

Store address now, call it later. Arduino library.

Because you want sort of `onClick` events for different items in
your collection.

## Sample output

```
[me_StoredCall] We are here.
Added handler.
We'll chill a bit and call it with different arguments.
[TSomeClass.OnRun](3): Last data was 0.
[TSomeClass.OnRun](12): Last data was 3.
[TSomeClass.OnRun](2): Last data was 12.
[me_StoredCall] Done.
```

## Code

* [Example](examples/me_StoredCall/me_StoredCall.ino)
* [Interface](src/me_StoredCall.h)
* [Implementation](src/me_StoredCall.cpp)

## Requirements

  * arduino-cli
  * bash

## Install/Remove

[Install.sh](Install.sh)
[Remove.sh](Remove.sh)

## Compile

Zero-warnings compilation:

```bash
arduino-cli compile --fqbn arduino:avr:uno --quiet --warnings all . --build-property compiler.cpp.extra_flags="-std=c++1z"
```

# See also

* [My other repositories](https://github.com/martin-eden/contents)
