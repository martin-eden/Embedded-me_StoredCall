// [me_StoredCall] test/demo

/*
  Author: Martin Eden
  Last mod.: 2024-09-12
*/

#include <me_StoredCall.h>

#include <me_UartSpeeds.h>
#include <me_InstallStandardStreams.h>
#include <me_BaseTypes.h>

void setup()
{
  Serial.begin(me_UartSpeeds::Arduino_Normal_Bps);

  InstallStandardStreams();

  printf("[me_StoredCall] We are here.\n");
  Test();
  printf("[me_StoredCall] Done.\n");
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
  printf("[TSomeClass.OnRun](%u)", Data);

  printf(": Last data was %u.", LastData);

  printf("\n");

  LastData = Data;
}

/*
  Ugly wrapper for class method
*/
void OnRun_wrap(
  TUint_2 Data,
  TUint_2 Upvalues
)
{
  TSomeClass * SomeClass = (TSomeClass *) Upvalues;
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
  StoredCall.Set(OnRun_wrap, (TUint_2) &SomeClass);
}

// --

/*
  Store call address and call it later
*/
void Test()
{
  AddHandler();
  printf("Added handler.\n");

  printf("We'll chill a bit and call it with different arguments.\n");

  randomSeed(analogRead(A0));

  delay(1500);

  StoredCall.Run(random(20));

  delay(1000);

  StoredCall.Run(random(20));

  delay(660);

  StoredCall.Run(random(20));
}

/*
  2024-06-29
*/
