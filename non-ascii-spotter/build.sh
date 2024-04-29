#!/bin/bash

export DEBIAN_FRONTEND=noninteractive

# Install depenedencies
apt-get update
apt-get install -y llvm gcc  build-essential

gcc action.c -o action
echo "Build complete"