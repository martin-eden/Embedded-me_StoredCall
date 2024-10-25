## What

(2024-06)

Store address now, call it later. Arduino library.

Because you want sort of `onClick` events for different items in
your collection.

## Sample output

```
[me_StoredCall] We are here.
Added handler.
We'll chill a bit and call handler with different arguments.
OnRun ( 06555 ) Last data ( 00000 )
OnRun ( 38349 ) Last data ( 06555 )
OnRun ( 28846 ) Last data ( 38349 )
[me_StoredCall] Done.
```

## Code

* [Example][Example]
* [Interface][Interface]
* [Implementation][Implementation]

## Requirements

  * arduino-cli
  * bash

## Install

Run [Install.sh](Install.sh).


## Remove

Run [Remove.sh](Remove.sh).

## Compile

Zero-warnings compilation:

```bash
arduino-cli compile --fqbn arduino:avr:uno --quiet --warnings all . --build-property compiler.cpp.extra_flags="-std=c++1z"
```

# See also

* [My other embedded C++ libraries][Embedded]
* [My other repositories][Repos]

[Example]: examples/me_StoredCall/me_StoredCall.ino
[Interface]: src/me_StoredCall.h
[Implementation]: src/me_StoredCall.cpp

[Embedded]: https://github.com/martin-eden/Embedded_Crafts/tree/master/Parts
[Repos]: https://github.com/martin-eden/contents
