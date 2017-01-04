#ifndef __UTILS_HPP__
#define __UTILS_HPP__

#include <chrono>
#include <memory>
#include <filesystem>
#include <boost/noncopyable.hpp>

namespace Filesystem = std::experimental::filesystem;

namespace Utils {

	typedef Filesystem::path Path;

	typedef std::chrono::high_resolution_clock::time_point TimePoint;
}

#endif