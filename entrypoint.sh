#!/bin/sh -l

echo "Action selected: $1"
time=$(date)
echo "::set-output name=time::$time"

sh Build/build.sh
