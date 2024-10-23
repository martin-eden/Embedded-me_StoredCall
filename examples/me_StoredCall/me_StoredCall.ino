// [me_StoredCall] test/demo

/*
  Author: Martin Eden
  Last mod.: 2024-10-23
*/

#include <me_StoredCall.h>

#include <me_BaseTypes.h>
#include <me_UartSpeeds.h>
#include <me_Console.h>

void setup()
{
  Serial.begin(me_UartSpeeds::Arduino_Normal_Bps);

  Console.Print("[me_StoredCall] We are here.");
  Test();
  Console.Print("[me_StoredCall] Done.");
}

void loop()
{
}

// --

/*
  Sample class for stored call demonstration

  I want internal state and handler with argument printing.
*/
class TSomeClass
{
  TUint_2 LastData = 0;

  public:
    void OnRun(TUint_2 Data);
};

void TSomeClass::OnRun(TUint_2 Data)
{
  Console.Write("OnRun (");
  Console.Print(Data);
  Console.Write(")");
  Console.Write(" ");
  Console.Write("Last data (");
  Console.Print(LastData);
  Console.Write(")");
  Console.EndLine();

  LastData = Data;
}

/*
  Ugly wrapper for class method
*/
void OnRun_wrap(
  TUint_2 Data,
  TUint_2 Instance
)
{
  TSomeClass * SomeClass = (TSomeClass *) Instance;
  SomeClass->OnRun(Data);
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

  StoredCall = ToStoredCall(OnRun_wrap, (TUint_2) &SomeClass);
  Console.Print("Added handler.");
}

// --

/*
  Store call address and call it later
*/
void Test()
{
  TUint_2 MaxRandom = 0xFFFF;

  AddHandler();

  Console.Print("We'll chill a bit and call handler with different arguments.");

  randomSeed(analogRead(A0));

  delay(1500);

  StoredCall.Run(random(MaxRandom));

  delay(1000);

  StoredCall.Run(random(MaxRandom));

  delay(660);

  StoredCall.Run(random(MaxRandom));
}

/*
  2024-06-29
  2024-10-23
*/
