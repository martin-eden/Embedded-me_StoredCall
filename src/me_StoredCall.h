// Store handler and call it later

/*
  Author: Martin Eden
  Version: 1
  Last mod.: 2024-09-12
*/

#pragma once

#include <me_BaseTypes.h>

namespace me_StoredCall
{
  /*
    Delayed method call

    Store handler now, call it later.
  */
  struct TStoredCall
  {
    TMethod Handler;
    TUint_2 Upvalues;

    // Zeroing init
    TStoredCall(): Handler(0), Upvalues(0) {};
    // Store handler and upvalues
    void Set(TMethod Handler, TUint_2 Upvalues);
    // Call with external data
    void Run(TUint_2 Data = 0);
  };
}

/*
  2024-06-29
*/
