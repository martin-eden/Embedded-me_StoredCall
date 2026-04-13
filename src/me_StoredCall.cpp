// Stored call implementation

/*
  Author: Martin Eden
  Last mod.: 2026-04-13
*/

#include <me_StoredCall.h>

#include <me_BaseTypes.h>
#include <me_BaseInterfaces.h>

using namespace me_StoredCall;

/*
  Invoke
*/
void TStoredCall::Run()
{
  if ((TUint_2) Method == 0) return;

  Method(Instance);
}

// ( Freetown

TStoredCall Freetown::ToStoredCall(
  TCallback Method,
  TAddress Instance
)
{
  return { .Method = Method, .Instance = Instance };
}

// ) Freetown

/*
  2024-06-29
  2024-10-18
  2026-04-13
*/
