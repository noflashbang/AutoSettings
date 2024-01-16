#include "AutoSettingSerializerIn.h"

bool AutoSettingSerializerIn::IO(AutoSettingEntry& io)
{
	auto entry = Util::StringSplit(*m_Data, "=");
	if (entry.size() != 2)
	{
		return false;
	}

	io.SetKey(entry[0]);
	io.SetValue(entry[1]);
	io.SetLoaded(true);
	return true;
}
bool AutoSettingSerializerIn::IO(AutoSettingGroup& io)
{
	//for each line
	auto lines = Util::StringSplit(*m_Data, "\n");
	for (auto line : lines)
	{
		//if line is a group
		if (line[0] == '[')
		{
			io.SetName(Util::StringTrimEx(Util::StringTrimEx(line, '['), ']'));
		}

		//if line is an entry
		if (line.find("=") != std::string::npos)
		{
			AutoSettingSerializerIn in(&line);
			AutoSettingEntry entry;
			bool okay = in.IO(entry);
			if (okay)
			{
				io.AddEntry(&entry);
			}
		}
	}

	return true;
}
