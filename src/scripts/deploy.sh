#!/bin/bash

[ -z "$(command -v realpath)" ] && printf "%s\n" "ERROR: realpath utility must be installed!" && exit 1

HW0_SOURCE_DIR="$(realpath "$(dirname "$0")")"
HW0_BINARY_DIR="$(pwd)"

HW0_CONFIGURE_ARGUMENTS=
HW0_MAKE_ARGUMENTS=
HW0_BUILD_TOOL="make"
HW0_INSTALL_PATH=${HW0_BINARY_DIR}/install
HW0_BUILD_NUMBER=0
CHECK_NINJA_INSTALLATION=0

#This is hardcoded due to Home Work requirements
PACKAGE_NAME_PREFIX=helloworld_uvarekov_otus_0

PACKAGE_VERSION_STRING=""


error()
{
	printf "%s\n" "[ERROR]: $*"
	exit 1
}

try()
{
	if ! "$@"; then
		error "$* failed"
	fi
}

process_option()
{
	case $1 in

	--install-to=*)
		try mkdir -p "${1#--install-to=}"
		HW0_INSTALL_PATH=$(realpath "${1#--install-to=}")
	;;

	--build-number=*)
		HW0_BUILD_NUMBER=${1#--build-number=}
		HW0_CONFIGURE_ARGUMENTS+=" $1"
	;;

	--build-tag=*)
		HW0_BUILD_TAG=${1#--build-tag=}
		HW0_CONFIGURE_ARGUMENTS+=" $1"
	;;

	--skip-configuration)
		SKIP_HW0_CONFIGURATION=true
	;;

	--ninja)
		CHECK_NINJA_INSTALLATION=1
	;;

	--no-production)
		HW0_CONFIGURE_ARGUMENTS+=" --minsizerel"
	;;

	--*)
		HW0_CONFIGURE_ARGUMENTS+=" $1"
	;;

	-D*)
		HW0_CONFIGURE_ARGUMENTS+=" $1"
	;;

	-*)
		HW0_MAKE_ARGUMENTS+=" $1"
	;;

	*)
		printf "%s\n" "ERROR: unknown option $1"
		exit 1
	;;

	esac
}


for ARGUMENT in "${@: 1: $#}"; do
	NONASCII=$(printf "%s\n" "$ARGUMENT" | perl -pe 's/[[:ascii:]]//g;')
	if [ -n "$NONASCII" ]; then
		printf "%s\n" "ERROR: Non-ASCII symbol in parameter: ${ARGUMENT}. Pass only ASCII letters from a terminal."
		exit 1
	fi
done

for ARGUMENT in "${@: 1: ($# - 1)}"; do
	process_option "$ARGUMENT"
done

if [ ${CHECK_NINJA_INSTALLATION} -gt 0 ]; then

		if [ -n "$(command -v ninja 2>/dev/null)" ]; then
			HW0_BUILD_TOOL=ninja
		else
			error "Install ninja first"
		fi

		HW0_CONFIGURE_ARGUMENTS+=" --ninja"
fi

args=( "$@" )
printf "%s [ %s ]\n" "Build arguments: " "${args[@]}"