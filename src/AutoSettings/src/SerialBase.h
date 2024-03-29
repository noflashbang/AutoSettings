#pragma once

#include "StandardLib.h"
#include "Util.h"
#include "ISerial.h"


class SerialBase : ISerializer
{
public:
	SerialBase(std::string* data);
	virtual ~SerialBase() {};

	virtual void IO(int            &io) = 0;
	virtual void IO(double         &io) = 0;
	virtual void IO(bool           &io) = 0;
	virtual void IO(std::string    &io) = 0;
	virtual void IO(std::vector<int> &io) = 0;
	virtual void IO(std::vector<double> &io) = 0;
	virtual void IO(std::vector<bool> &io) = 0;
	virtual void IO(std::vector<std::string> &io) = 0;

	std::string ArraySeperator = DEFAULT_ARRAY_SEPERATOR;

protected:

	void inline Serialize(int &io)
	{
		auto result = std::format("{}", io);
		m_Data->append(result);
	};

	void inline Serialize(double& io)
	{
		auto result = std::format("{}", io);
		m_Data->append(result);
	};

	template <typename T>
	void SerializeArray(std::vector<T> &io)
	{
		for(auto iter = io.begin(); iter != io.end(); iter++ )
		{
			if (iter != io.begin())
			{
				IO(ArraySeperator);
			}
			T holder = *iter;
			IO(holder);
		}
	};

	template <typename T, typename S>
	void ReadArray(std::vector<T>& io)
	{
		int ii = 0;
		auto tokens = Util::StringSplit(*m_Data, ArraySeperator);
		io.resize(tokens.size());
		for(auto token : tokens)
		{
			S in(&token);
			T holder;
			in.IO(holder);
			io.at(ii) = holder;
			ii++;
		}
	};

	std::string* m_Data;

	SerialBase() = delete;
	SerialBase(const SerialBase&) = delete;
	SerialBase& operator=(const SerialBase&) = delete;
};

