#!/bin/bash

# Uninstall library
arduino-cli lib uninstall me_StoredCall

# Uninstall dependencies
arduino-cli lib uninstall \
  me_UartSpeeds \
  me_InstallStandardStreams \
  me_BaseTypes
