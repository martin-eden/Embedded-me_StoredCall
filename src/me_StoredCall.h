// Store handler and call it later

/*
  Author: Martin Eden
  Last mod.: 2026-04-13
*/

#pragma once

#include <me_BaseTypes.h>
#include <me_BaseInterfaces.h>

namespace me_StoredCall
{
  /*
    Delayed method call

    Store handler now, call it later.
  */
  struct TStoredCall
  {
    TCallback Method;
    TAddress Instance;

    void Run();
  };

  namespace Freetown
  {
    TStoredCall ToStoredCall(TCallback, TAddress);
  }
}

/*
  2024-06-29
  2024-10-18
  2026-04-13
*/
