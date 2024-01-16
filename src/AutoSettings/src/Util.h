#pragma once

#include "StandardLib.h"

static class Util
{
	public:

		static inline std::string file_to_string(const std::string& file_name)
		{
			std::ifstream file_stream{ file_name };

			if (!file_stream.fail())
			{
				return "";// Error opening file.
			}

			std::ostringstream str_stream;
			file_stream >> str_stream.rdbuf();  // NOT str_stream << file_stream.rdbuf()

			if (file_stream.fail() && !file_stream.eof())
			{
				return "";
			}

			return str_stream.str();
		}

		static inline bool string_to_file(const std::string& file_name, const std::string& content)
		{
			std::ofstream file_stream{ file_name };
			if (file_stream.fail())
			{
				return false;
			}
			file_stream << content;
			return !file_stream.fail();
		}

		static inline std::vector<std::string> StringSplit(std::string s, std::string delimiter)
		{
			size_t pos_start = 0;
			size_t pos_end = 0;
			size_t delim_len = delimiter.length();
			std::string token;
			std::vector<std::string> res;

			while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos)
			{
				token = s.substr(pos_start, pos_end - pos_start);
				pos_start = pos_end + delim_len;
				res.push_back(token);
			}

			res.push_back(s.substr(pos_start));
			return res;
		}

		static inline std::string StringToUpper(const std::string& strToConvert)
		{
			return StringToUpper(std::string(strToConvert));
		}

		static inline std::string StringToUpper(std::string& strToConvert)
		{
			for (std::string::iterator p = strToConvert.begin(); strToConvert.end() != p; ++p)
				*p = toupper(*p);

			return strToConvert;
		}
	
		static inline std::string StringToLower(const std::string& strToConvert)
		{
			return StringToLower(std::string(strToConvert));
		}

		static inline std::string StringToLower(std::string& strToConvert)
		{
			for (std::string::iterator p = strToConvert.begin(); strToConvert.end() != p; ++p)
				*p = tolower(*p);

			return strToConvert;
		}

		static inline std::string StringTrim(const std::string& strToTrim)
		{
			std::string str = std::string(strToTrim);
			StringTrim(str);
			return str;
		}

		static inline void StringTrim(std::string& strToTrim)
		{
			//all whitespace
			std::vector<char> whitespace = { ' ', '\t', '\n', '\r', '\f', '\v' };
			for (auto c : whitespace)
			{
				StringTrimEx(strToTrim, c);
			}
		}

		static inline std::string StringTrimEx(const std::string& strToTrim, const char c)
		{
			std::string str = std::string(strToTrim);
			StringTrimEx(str, c);
			return str;
		}

		static inline void StringTrimEx(std::string& strToTrim, const char c)
		{
			std::string::size_type pos = strToTrim.find_last_not_of(c);
			if (pos != std::string::npos)
			{
				strToTrim.erase(pos + 1);
				pos = strToTrim.find_first_not_of(c);
				if (pos != std::string::npos) strToTrim.erase(0, pos);
			}
			else strToTrim.erase(strToTrim.begin(), strToTrim.end());
		}
};