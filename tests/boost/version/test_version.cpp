#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN// in only one cpp file
#include <boost/test/unit_test.hpp>
namespace bt = boost::unit_test;

#include <versioning/ProjectVersion.h>

BOOST_AUTO_TEST_SUITE(test_version)

BOOST_AUTO_TEST_CASE(test_1_always_ok) { BOOST_TEST(1 == 1); }

BOOST_AUTO_TEST_CASE(test_2_major_version_non_zero) {
	auto version = otus_hw_0::ProjectVersion::GetVersion();

	BOOST_TEST(version.GetMajorVersion() != 0);
}

BOOST_AUTO_TEST_CASE(test_3_minor_version_non_zero) {
	auto version = otus_hw_0::ProjectVersion::GetVersion();

	BOOST_TEST(version.GetMinorVersion() != 0);
}

BOOST_AUTO_TEST_CASE(test_4_build_version_non_zero) {
	auto version = otus_hw_0::ProjectVersion::GetVersion();

	BOOST_TEST(version.GetBuildVersion() != 0);
}

BOOST_AUTO_TEST_SUITE_END()