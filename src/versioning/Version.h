#ifndef HELLOTASK_VERSION_H
#define HELLOTASK_VERSION_H


#include <cstdint>
#include <string>
#include <vector>
#include <sstream>
#include <charconv>

namespace otus_hw_0 {
	class Version {

	private:

		uint32_t _majorVersion;
		uint32_t _minorVersion;
		uint32_t _buildVersion;

	private:

		static constexpr uint32_t VersionConversion(std::string_view majorVersion) {

			uint32_t ver = 0;
			//# gcc, GCC, G++ 13+ required for constexpr std:from_chars
			auto result = std::from_chars(majorVersion.data(), majorVersion.data() + majorVersion.size(), ver);
			if (result.ec == std::errc::invalid_argument) {
				// We still can not throw from constexpr...
				// throw std::invalid_argument("Version couldn't have been converted: [" + std::string(majorVersion) + "]");
				return ver;
			}

			return ver;

		}

	public:

		constexpr Version(std::string_view majorVersion, std::string_view minorVersion, std::string_view buildVersion) {

			_majorVersion = VersionConversion(majorVersion);
			_minorVersion = VersionConversion(minorVersion);
			_buildVersion = VersionConversion(buildVersion);

		}

		bool operator<(const Version &another) const {

			if (_majorVersion > another._minorVersion) {
				return false;
			}
			if (_majorVersion < another._minorVersion) {
				return true;
			}

			if (_minorVersion > another._minorVersion) {
				return false;
			}
			if (_minorVersion < another._minorVersion) {
				return true;
			}

			if (_buildVersion > another._buildVersion) {
				return false;
			}
			if (_buildVersion < another._buildVersion) {
				return true;
			}

			return false;
		}

		bool operator==(const Version &another) const {

			return _majorVersion == another._majorVersion && _minorVersion == another._minorVersion &&
				   _buildVersion == another._buildVersion;

		}

		friend inline std::ostream &operator<<(std::ostream &os, const Version &version);

		[[nodiscard]] uint32_t GetMajorVersion() const {
			return _majorVersion;
		}

		[[nodiscard]] uint32_t GetMinorVersion() const {
			return _minorVersion;
		}

		[[nodiscard]] uint32_t GetBuildVersion() const {
			return _buildVersion;
		}
	};

	inline std::ostream &operator<<(std::ostream &os, const Version &version) {

		os << version._majorVersion << "." << version._minorVersion << "." << version._buildVersion;

		return os;
	}

	static inline std::string to_string(const Version &x) {
		std::ostringstream ss;
		ss << x;
		return ss.str();
	}

}


#endif //HELLOTASK_VERSION_H
