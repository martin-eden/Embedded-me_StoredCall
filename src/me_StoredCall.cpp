// Stored call implementation

/*
  Author: Martin Eden
  Last mod.: 2024-12-20
*/

#include <me_StoredCall.h>

using namespace me_StoredCall;

/*
  Invoke with external data
*/
void TStoredCall::Run(TUint_2 Data)
{
  if (Handler == 0)
    return;

  Handler(Data, Instance);
}

// ( Freetown

TStoredCall Freetown::ToStoredCall(
  TMethod Handler,
  TUint_2 Instance
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
