#!/usr/bin/env bash
set -e

echo "PWD TO FOLLOW"

echo %PWD

echo "Print all environmental variables!"

echo $OF_ROOT




echo =========================================
printenv

echo =========================================

# Get the current OF_ROOT
OF_ROOT="${OF_ROOT:-~/openFrameworks}"

echo $OF_ROOT

OF_ROOT="/$OF_ROOT" | sed 's/\\/\//g' | sed 's/://'

echo "Cleaned OF_ROOT"
echo $OF_ROOT


OF_ADDONS=$OF_ROOT/addons
# Addon path
# These paths assume that this file is located in
#   ADDON_NAME/ci/install.sh

ADDON_PATH=$( cd $(dirname $0) ; cd ../../; pwd -P )
ADDON_NAME=${ADDON_PATH##*/}

GH_USERNAME='bakercp'
GH_BRANCH='master'
GH_DEPTH=1

REQUIRED_ADDONS=()

# Extract ADDON_DEPENDENCIES from addon_config.mk file.
if [ -f $ADDON_PATH/addon_config.mk ]; then
  while read line; do
    #line="$(echo -e "${line}" | sed -e 's/^[[:space:]]*//' -e 's/[[:space:]]*$//')"
    if [[ $line == ADDON_DEPENDENCIES* ]] ;
    then
      line=${line#*=}
      IFS=' ' read -ra ADDR <<< "$line"
      for i in "${ADDR[@]}"; do
          REQUIRED_ADDONS+=($i)
      done
    fi
  done < $ADDON_PATH/addon_config.mk
fi

# Gather addons from all examples.
for addons_make in $ADDON_PATH/example*/addons.make; do
  while read addon; do
    if [ $addon != $ADDON_NAME ] ;
    then
      REQUIRED_ADDONS+=($addon)
    fi
  done < $addons_make
done

# We aren't de-duplicating array, to keep it pure bash.
for addon in "${REQUIRED_ADDONS[@]}"
do
  addon_path=$OF_ADDONS/$addon
  if [ ! -d "$addon_path" ]; then
    git clone --depth=$GH_DEPTH https://github.com/$GH_USERNAME/$addon.git $addon_path
  fi
done

echo "Listing currently installed addons ..."
ls -la $OF_ADDONS/*
