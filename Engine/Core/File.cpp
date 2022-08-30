#include "File.h"
#include <filesystem>
#include <fstream>

namespace Solas
{
	void setFilePath(const std::string& pathname)
	{
		std::filesystem::current_path(pathname);
	}

	std::string getFilePath()
	{
		return std::filesystem::current_path().string();
	}

	bool fileExists(const std::string& pathname)
	{
		return std::filesystem::exists(pathname);
	}

	bool getFileSize(const std::string& pathname, size_t& size)
	{
		if (!fileExists(pathname)) return false;
		size = std::filesystem::file_size(pathname);

		return true;
	}

	bool readFile(const std::string& pathname, std::string& buffer)
	{
		if (!fileExists(pathname)) return false;

		size_t size;
		getFileSize(pathname, size);
		buffer.resize(size);

		std::ifstream fstream(pathname);
		fstream.read(buffer.data(), size);
		fstream.close();

		return true; // WAS FALSE BEFORE
	}
}