// Stored call implementation

/*
  Author: Martin Eden
  Last mod.: 2024-06-29
*/

#include "me_StoredCall.h"

using namespace me_StoredCall;

/*
  Store handler and upvalues
*/
void TStoredCall::Set(TMethod Handler, TUint_2 Upvalues)
{
  this->Handler = Handler;
  this->Upvalues = Upvalues;
}

/*
  Invoke with external data
*/
void TStoredCall::Run(TUint_2 Data)
{
  if (Handler == 0)
    return;

  Handler(Data, Upvalues);
}

/*
  2024-06-29
*/
