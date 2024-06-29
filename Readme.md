# What

(2024-06)

Store address now, call it later. Arduino library.

Because you want sort of `onClick` events for different items in
your collection.

## Requirements

  * arduino-cli
  * bash


## Install

Run [Install.sh](Install.sh).


## Remove

Run [Remove.sh](Remove.sh).


# Compile

Zero-warnings compilation:

```bash
arduino-cli compile --fqbn arduino:avr:uno --quiet --warnings all . --build-property compiler.cpp.extra_flags="-std=c++1z"
```

# Code

* [Interface](src/me_StoredCall.h)
* [Implementation](src/me_StoredCall.cpp)
* [Example](examples/me_StoredCall/me_StoredCall.ino)


# See also

* [My other repositories](https://github.com/martin-eden/contents)
