// Store handler and call it later

/*
  Author: Martin Eden
  Last mod.: 2025-08-27
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
    TMethod Handler;
    TUint_2 Instance;

    // Call with external data
    void Run(TUint_2 Data = 0);
  };

  namespace Freetown
  {
    TStoredCall ToStoredCall(
      TMethod Handler,
      TUint_2 Instance
    );
  }
}

/*
  2024-06-29
  2024-10-18
*/
