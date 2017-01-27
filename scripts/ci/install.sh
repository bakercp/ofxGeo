#!/usr/bin/env bash
set -e

echo "The PWD"
echo $PWD

# If AppVeyor, get the path as a posix path.
if [ "${APPVEYOR}" == "True" ]; then
  echo "This is an AppVeyor build."
  OF_ROOT="$PWD"
fi

echo "OF_ADDON_NAME"
echo $OF_ADDON_NAME

echo "OF_ADDON_PATH"
echo ${OF_ROOT}/addons/${OF_ADDON_NAME}/

# Default addon github info.
GH_USERNAME='bakercp'
GH_BRANCH='master'
GH_DEPTH=1

# An array of required addons that will be gathered below.
REQUIRED_ADDONS=()

# Extract ADDON_DEPENDENCIES from addon_config.mk file.
if [ -f ${OF_ROOT}/addons/${OF_ADDON_NAME}/addon_config.mk ]; then
  while read line; do
    if [[ $line == ADDON_DEPENDENCIES* ]] ;
    then
      line=${line#*=}
      IFS=' ' read -ra ADDR <<< "$line"
      for i in "${ADDR[@]}"; do
          REQUIRED_ADDONS+=($i)
      done
    fi
  done < ${OF_ROOT}/addons/${OF_ADDON_NAME}/addon_config.mk
fi

# Gather addons from all examples.
for addons_make in ${OF_ROOT}/addons/${OF_ADDON_NAME}/example*/addons.make; do
  while read addon; do
    if [ ${addon} != ${OF_ADDON_NAME} ] ;
    then
      REQUIRED_ADDONS+=($addon)
    fi
  done < $addons_make
done

# We aren't de-duplicating array to keep it pure bash.
for addon in "${REQUIRED_ADDONS[@]}"
do
  if [ ! -d ${OF_ROOT}/addons/${addon} ]; then
    git clone --depth=$GH_DEPTH https://github.com/$GH_USERNAME/$addon.git ${OF_ROOT}/addons/${addon}
  fi
done

echo "Listing currently installed addons ..."
ls -la ${OF_ROOT}/addons
