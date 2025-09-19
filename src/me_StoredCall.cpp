// Stored call implementation

/*
  Author: Martin Eden
  Last mod.: 2025-09-19
*/

#include <me_StoredCall.h>

#include <me_BaseTypes.h>
#include <me_BaseInterfaces.h>

using namespace me_StoredCall;

/*
  Invoke with external data
*/
void TStoredCall::Run(
  TUint_2 Data
)
{
  if (Handler == 0)
    return;

  Handler(Data, Instance);
}

// ( Freetown

TStoredCall Freetown::ToStoredCall(
  TMethod Handler,
  TAddress Instance
)
{
  TStoredCall Result;

  Result.Handler = Handler;
  Result.Instance = Instance;

  return Result;
}

// ) Freetown

/*
  2024-06-29
  2024-10-18
*/
