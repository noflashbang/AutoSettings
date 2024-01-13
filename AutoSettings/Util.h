#pragma once

#include <string>


static class Util
{
	public:
		static inline void StringToUpper(std::string* strToConvert)
		{
			for (std::string::iterator p = strToConvert->begin(); strToConvert->end() != p; ++p)
				*p = toupper(*p);
		};

		static inline void StringToLower(std::string* strToConvert)
		{
			for (std::string::iterator p = strToConvert->begin(); strToConvert->end() != p; ++p)
				*p = tolower(*p);
		};

		static inline void StringTrim(std::string* strToTrim)
		{
			std::string::size_type pos = strToTrim->find_last_not_of(' ');
			if (pos != std::string::npos)
			{
				strToTrim->erase(pos + 1);
				pos = strToTrim->find_first_not_of(' ');
				if (pos != std::string::npos) strToTrim->erase(0, pos);
			}
			else strToTrim->erase(strToTrim->begin(), strToTrim->end());
		};

		static inline void StringTrim(std::string* strToTrim, char c)
		{
			std::string::size_type pos = strToTrim->find_last_not_of(c);
			if (pos != std::string::npos)
			{
				strToTrim->erase(pos + 1);
				pos = strToTrim->find_first_not_of(c);
				if (pos != std::string::npos) strToTrim->erase(0, pos);
			}
			else strToTrim->erase(strToTrim->begin(), strToTrim->end());
		};

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
			return StringTrim(std::string(strToTrim));
		}

		static inline std::string StringTrim(std::string& strToTrim)
		{
			std::string::size_type pos = strToTrim.find_last_not_of(' ');
			if (pos != std::string::npos)
			{
				strToTrim.erase(pos + 1);
				pos = strToTrim.find_first_not_of(' ');
				if (pos != std::string::npos) strToTrim.erase(0, pos);
			}
			else strToTrim.erase(strToTrim.begin(), strToTrim.end());

			return strToTrim;
		}

		static inline std::string StringTrimEx(const std::string& strToTrim, const char c)
		{
			return StringTrimEx(std::string(strToTrim), c);
		}

		static inline std::string StringTrimEx(std::string& strToTrim, const char c)
		{
			std::string::size_type pos = strToTrim.find_last_not_of(c);
			if (pos != std::string::npos)
			{
				strToTrim.erase(pos + 1);
				pos = strToTrim.find_first_not_of(c);
				if (pos != std::string::npos) strToTrim.erase(0, pos);
			}
			else strToTrim.erase(strToTrim.begin(), strToTrim.end());

			return strToTrim;
		}
};