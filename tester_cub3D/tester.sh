#!/bin/bash

S="\001\033"
E="\002"

RESET=$S"[000m"$E


BLACK=$S"[030m"$E
RED=$S"[031m"$E
GREEN=$S"[032m"$E
YELLOW=$S"[033m"$E
BLUE=$S"[034m"$E
PURPLE=$S"[035m"$E
CYAN=$S"[036m"$E
GREY=$S"[037m"$E

dossier="./assets/maps_test"


if [ $# -eq 0 ]; then
  echo "Error number of arguments"
  echo "Usage : ./tester.sh <path to cub3D>"
  exit 1
fi

if [ ! -x "$1" ]; then
  echo -e "This file doesn't exist !"
  exit 1
fi

for FILES in "$dossier"/*; do
  if [ -f "$FILES" ]; then
    FIRST_CHAR=$(basename "$FILES" | cut -c 1)

    echo -e "-------------------------------------------------------"
    echo -e "$BLUE$> $1 $FILES$RESET"
    echo -en $RED
    "$1" "$FILES"
    retval=$?
    echo -en $RESET
    if [ "$FIRST_CHAR" = "b" ]; then
    echo -n "($retval) "

      if [ $retval -eq 1 ]; then
        echo -e "$GREEN✓ Good$RESET"
      else
        echo -e "$RED✗ Bad$RESET"
        # kill `pidof $1`
      fi  
    elif [ "$FIRST_CHAR" = "g" ]; then
    echo -n "($retval) "

      if [ $retval -eq 1 ]; then
        echo -e "$RED✗ Bad$RESET"
      else
        echo -e "$GREEN✓ Good$RESET"
        # kill `pidof $1`
      fi
    fi
  fi
done
echo -e "-------------------------------------------------------"

killall cub3D
killall cub3D_bonus