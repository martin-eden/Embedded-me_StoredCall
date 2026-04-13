// [me_StoredCall] test/demo

/*
  Author: Martin Eden
  Last mod.: 2026-04-13
*/

#include <me_StoredCall.h>

#include <me_BaseTypes.h>
#include <me_Console.h>
#include <me_Delays.h>

// --

/*
  Sample class for stored call demonstration
*/
class TSomeClass
{
  public:
    void OnRun();
};

void TSomeClass::OnRun()
{
  Console.Print("OnRun()");
}

/*
  Class method caller
*/
void OnRun_wrap(
  TAddress Instance
)
{
  TSomeClass * SomeClass = (TSomeClass *) Instance;

  SomeClass->OnRun();
}

// --

// Class instance need to be alive at time of wiring and invocation
TSomeClass SomeClass;

// We store addresses there
me_StoredCall::TStoredCall StoredCall;

/*
  Add handler
*/
void AddHandler()
{
  using
    me_StoredCall::Freetown::ToStoredCall;

  StoredCall = ToStoredCall(OnRun_wrap, (TAddress) &SomeClass);

  Console.Print("Added handler.");
}

// --

/*
  Store call address and call it later
*/
void Test()
{
  AddHandler();

  Console.Print("We'll call handler several times.");

  me_Delays::Delay_Ms(1500);
  StoredCall.Run();
  me_Delays::Delay_Ms(1000);
  StoredCall.Run();
  me_Delays::Delay_Ms(660);
  StoredCall.Run();
  me_Delays::Delay_Ms(420);
}

// --

void setup()
{
  Console.Init();

  Console.Print("( [me_StoredCall] demo");
  Console.Indent();
  Test();
  Console.Unindent();
  Console.Print(") Done");
}

void loop()
{
}

/*
  2024-06-29
  2024-10-23
  2025-09-19
  2026-04-13
*/
