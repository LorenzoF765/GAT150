#pragma once
#include <string>
	void setFilePath(const std::string& pathname);
	std::string getFilePath();

	bool fileExists(const std::string& pathname);
	bool getFileSize(const std::string& pathname, size_t& size);
	bool readFile(const std::string& pathname, std::string& buffer);
}
